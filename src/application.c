// Tower Kit documentation https://tower.hardwario.com/
// SDK API description https://sdk.hardwario.com/
// Forum https://forum.hardwario.com/

#include <application.h>
#include <ai_platform.h>

#include <network_temperature.h>
#include <network_temperature_data.h>

#include <network_humidity.h>
#include <network_humidity_data.h>

#include <stm32l0xx_hal_crc.h>

#define UPDATE_INTERVAL (10 * 60 * 1000)

//#define UPDATE_INTERVAL (10000)

// LED instance
twr_led_t led;

// Button instance
twr_button_t button;

// Thermometer instance
twr_tmp112_t tmp112;
float core_tmp112_value = 0;

twr_tag_humidity_t humidity_tag;
float tag_humidity = 0;

uint16_t button_click_count = 0;

twr_scheduler_task_id_t send_data_task_id;

struct tm datetime;

float lastTemperature = 0;
float lastHumidity = 0;

ai_handle network_temperature;
float aiTemperatureInData[AI_NETWORK_TEMPERATURE_IN_1_SIZE];
float aiTemperatureOutData[AI_NETWORK_TEMPERATURE_OUT_1_SIZE];

ai_u8 activations_temperature[AI_NETWORK_TEMPERATURE_DATA_ACTIVATIONS_SIZE];

ai_buffer *ai_temperature_input;
ai_buffer *ai_temperature_output;

static void AI_Temperature_Init(void);
static void AI_Temperature_Run(float *pIn, float *pOut);

ai_handle network_humidity;
float aiHumidityInData[AI_NETWORK_HUMIDITY_IN_1_SIZE];
float aiHumidityOutData[AI_NETWORK_HUMIDITY_OUT_1_SIZE];

ai_u8 activations_humidity[AI_NETWORK_HUMIDITY_DATA_ACTIVATIONS_SIZE];

ai_buffer *ai_humidity_input;
ai_buffer *ai_humidity_output;

static void AI_Humidity_Init(void);
static void AI_Humidity_Run(float *pIn, float *pOut);

static void AI_Temperature_Init(void)
{
    ai_error err;

    /* Create a local array with the addresses of the activations buffers */
    const ai_handle act_addr[] = {activations_temperature};
    /* Create an instance of the model */
    err = ai_network_temperature_create_and_init(&network_temperature, act_addr, NULL);
    if (err.type != AI_ERROR_NONE)
    {
        twr_log_error("ai_network_create_and_init error - type=%d code=%d", err.type, err.code);
        return;
    }
    ai_temperature_input = ai_network_temperature_inputs_get(network_temperature, NULL);
    ai_temperature_output = ai_network_temperature_outputs_get(network_temperature, NULL);
}

static void AI_Temperature_Run(float *pIn, float *pOut)
{
    ai_i32 batch;
    ai_error err;

    /* Update IO handlers with the data payload */
    ai_temperature_input[0].data = AI_HANDLE_PTR(pIn);
    ai_temperature_output[0].data = AI_HANDLE_PTR(pOut);

    batch = ai_network_temperature_run(network_temperature, ai_temperature_input, ai_temperature_output);
    if (batch != 1)
    {
        err = ai_network_temperature_get_error(network_temperature);
        twr_log_error("AI ai_network_run error - type=%d code=%d", err.type, err.code);
        return;
    }
}

static void AI_Humidity_Init(void)
{
    ai_error err;

    /* Create a local array with the addresses of the activations buffers */
    const ai_handle act_addr[] = {activations_humidity};
    /* Create an instance of the model */
    err = ai_network_humidity_create_and_init(&network_humidity, act_addr, NULL);
    if (err.type != AI_ERROR_NONE)
    {
        twr_log_error("ai_network_create_and_init error - type=%d code=%d", err.type, err.code);
        return;
    }
    ai_humidity_input = ai_network_humidity_inputs_get(network_humidity, NULL);
    ai_humidity_output = ai_network_humidity_outputs_get(network_humidity, NULL);
}

static void AI_Humidity_Run(float *pIn, float *pOut)
{
    ai_i32 batch;
    ai_error err;

    /* Update IO handlers with the data payload */
    ai_humidity_input[0].data = AI_HANDLE_PTR(pIn);
    ai_humidity_output[0].data = AI_HANDLE_PTR(pOut);

    batch = ai_network_humidity_run(network_humidity, ai_humidity_input, ai_humidity_output);
    if (batch != 1)
    {
        err = ai_network_humidity_get_error(network_humidity);
        twr_log_error("AI ai_network_run error - type=%d code=%d", err.type, err.code);
        return;
    }
}

// Button event callback
void button_event_handler(twr_button_t *self, twr_button_event_t event, void *event_param)
{
    // Log button event
    twr_log_info("APP: Button event: %i", event);

    // Check event source
    if (event == TWR_BUTTON_EVENT_CLICK)
    {
        // Toggle LED pin state
        twr_led_set_mode(&led, TWR_LED_MODE_TOGGLE);

        // Publish message on radio
        button_click_count++;
        twr_radio_pub_push_button(&button_click_count);
    }
}

void humidity_tag_event_handler(twr_tag_humidity_t *self, twr_tag_humidity_event_t event, void *event_param)
{
    if (event == TWR_TAG_HUMIDITY_EVENT_UPDATE)
    {
        float value;
        if (twr_tag_humidity_get_humidity_percentage(self, &value))
        {
            tag_humidity = value;
            twr_log_debug("HUMIDITY: %.2f", tag_humidity);
        }
    }
}

void tmp112_event_handler(twr_tmp112_t *self, twr_tmp112_event_t event, void *event_param)
{
    if (event == TWR_TMP112_EVENT_UPDATE)
    {
        float value;
        if (twr_tmp112_get_temperature_celsius(self, &value))
        {
            core_tmp112_value = value;
            twr_log_debug("TEMPERATURE: %.2f", core_tmp112_value);
        }
    }
}

void send_data_task()
{
    twr_log_debug("SENDING DATA");

    twr_rtc_get_datetime(&datetime);

    int year = datetime.tm_year + 1900;

    ((ai_float *)aiTemperatureInData)[0] = (ai_float)year;
    ((ai_float *)aiTemperatureInData)[1] = (ai_float)datetime.tm_mon;
    ((ai_float *)aiTemperatureInData)[2] = (ai_float)datetime.tm_mday;
    ((ai_float *)aiTemperatureInData)[3] = (ai_float)datetime.tm_hour;
    ((ai_float *)aiTemperatureInData)[4] = (ai_float)datetime.tm_min;
    ((ai_float *)aiTemperatureInData)[5] = (ai_float)datetime.tm_sec;
    ((ai_float *)aiTemperatureInData)[6] = (ai_float)lastTemperature;
    ((ai_float *)aiTemperatureInData)[7] = (ai_float)lastHumidity;

    AI_Temperature_Run(aiTemperatureInData, aiTemperatureOutData);

    float predicted_temperature = ((ai_float *)aiTemperatureOutData)[0];

    ((ai_float *)aiHumidityInData)[0] = (ai_float)year;
    ((ai_float *)aiHumidityInData)[1] = (ai_float)datetime.tm_mon;
    ((ai_float *)aiHumidityInData)[2] = (ai_float)datetime.tm_mday;
    ((ai_float *)aiHumidityInData)[3] = (ai_float)datetime.tm_hour;
    ((ai_float *)aiHumidityInData)[4] = (ai_float)datetime.tm_min;
    ((ai_float *)aiHumidityInData)[5] = (ai_float)datetime.tm_sec;
    ((ai_float *)aiHumidityInData)[6] = (ai_float)lastHumidity;
    ((ai_float *)aiHumidityInData)[7] = (ai_float)lastTemperature;

    AI_Humidity_Run(aiHumidityInData, aiHumidityOutData);

    float predicted_humidity = ((ai_float *)aiHumidityOutData)[0];

    char buffer_predicted[64];
    snprintf(buffer_predicted, sizeof(buffer_predicted), "{\\\"p_temp\\\":%.2f,\\\"p_hum\\\":%.2f}", predicted_temperature, predicted_humidity);
    twr_radio_pub_string("predicted", buffer_predicted);
    twr_log_debug("PREDICTED: %s", buffer_predicted);

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "{\\\"temperature\\\":%.2f,\\\"humidity\\\":%.2f}", core_tmp112_value, tag_humidity);
    twr_log_debug("DATA: %s", buffer);
    twr_radio_pub_string("data", buffer);

    lastHumidity = tag_humidity;
    lastTemperature = core_tmp112_value;

    twr_scheduler_plan_current_relative(UPDATE_INTERVAL + 1000);
}

// Application initialization function which is called once after boot
void application_init(void)
{
    __HAL_RCC_CRC_CLK_ENABLE();

    /*struct tm datetime;

    datetime.tm_hour = 12;
    datetime.tm_min = 43;
    datetime.tm_sec = 00;

    datetime.tm_mon = 03;
    datetime.tm_mday = 20;
    datetime.tm_year = 123;

    twr_rtc_set_datetime(&datetime, 0);*/

    // Initialize logging
    twr_log_init(TWR_LOG_LEVEL_DUMP, TWR_LOG_TIMESTAMP_ABS);

    // Initialize AI
    AI_Temperature_Init();
    AI_Humidity_Init();

    // Initialize LED
    twr_led_init(&led, TWR_GPIO_LED, false, 0);
    twr_led_pulse(&led, 2000);

    // Initialize button
    twr_button_init(&button, TWR_GPIO_BUTTON, TWR_GPIO_PULL_DOWN, 0);
    twr_button_set_event_handler(&button, button_event_handler, NULL);

    // Initialize thermometer on core module
    twr_tmp112_init(&tmp112, TWR_I2C_I2C0, TWR_TAG_TEMPERATURE_I2C_ADDRESS_ALTERNATE);
    twr_tmp112_set_event_handler(&tmp112, tmp112_event_handler, NULL);
    twr_tmp112_set_update_interval(&tmp112, UPDATE_INTERVAL);

    twr_tag_humidity_init(&humidity_tag, TWR_TAG_HUMIDITY_REVISION_R3, TWR_I2C_I2C0, TWR_TAG_HUMIDITY_I2C_ADDRESS_DEFAULT);
    twr_tag_humidity_set_event_handler(&humidity_tag, humidity_tag_event_handler, NULL);
    twr_tag_humidity_set_update_interval(&humidity_tag, UPDATE_INTERVAL);

    // Initialize radio
    twr_radio_init(TWR_RADIO_MODE_NODE_SLEEPING);

    send_data_task_id = twr_scheduler_register(send_data_task, NULL, UPDATE_INTERVAL + 1000);

    // Send radio pairing request
    twr_radio_pairing_request("toi-project", FW_VERSION);

    twr_rtc_get_datetime(&datetime);
    twr_log_debug("$DATE: \"%d-%02d-%02dT%02d:%02d:%02dZ\"", datetime.tm_year + 1900, datetime.tm_mon, datetime.tm_mday, datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
}
