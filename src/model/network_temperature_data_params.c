/**
  ******************************************************************************
  * @file    network_temperature_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Mar 28 21:39:41 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "network_temperature_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_temperature_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_temperature_weights_array_u64[217] = {
  0x3eb8a29f3ed5db40U, 0xbaf789ea3e90d44eU, 0x3ec2abef3b01416cU, 0x3e8a12983ecfc30aU,
  0xbedd99a83e8d4b02U, 0x3c1c21ffbd0381b0U, 0xbb2e46e53e842d3aU, 0xbe9ad358bf099cffU,
  0xbcc0e2223fd1eb77U, 0xbca0d564bef831a7U, 0x3b7fe216bb96f238U, 0x404dbb003d4a5242U,
  0x3c753797bf93a7c6U, 0xbf05e67fbf0ca996U, 0xbe6daa43bf035f6dU, 0xbe7bfcf4befc2e4eU,
  0xbc68c5bbbe7c1db6U, 0xbccde30dbe43f414U, 0xbcca6bdebd3991cbU, 0x3ee77d903e89c2f1U,
  0x3c5d23203cb4c83cU, 0xbf4d8dc3bd45070bU, 0xbf0f40a8bf2be0c1U, 0xbeffd6e4bea4df5fU,
  0xbba16c02bcbc404fU, 0x3e93dc8ebf1819dfU, 0x3dd7ea4ebe61b3c1U, 0xbeaae7813edebe56U,
  0xbd7716c0befa87a9U, 0x3eb6b5c8be46dbc8U, 0x3eb841acbeeea740U, 0x3e1bb6a03e05c148U,
  0x3dd4b5f3be6354a8U, 0xbe5a9c243dcb37dcU, 0x3d015b9a3e91b58bU, 0xc0cfca10bc623d9aU,
  0xbae8d2cabf6f9193U, 0xbe398043beea7b38U, 0xbc8048afbdd0e218U, 0x40b214bebcaae36eU,
  0xbb2f53bb3b930e06U, 0xbd9f1775be1faf49U, 0xbeb6f827bdca1483U, 0x3dad9c16bef30ccdU,
  0x3ac2cdb83ddf9f54U, 0x3ec7d6e0bf0e571eU, 0xbed57d94becf705aU, 0xbebac9053b697ecaU,
  0xbe857218bd41427eU, 0xbedc6ae4be59ba18U, 0xbe84db54be887918U, 0x3ee4a2d43e07f6c0U,
  0x3c4b0e70bd944230U, 0x3e70bfb9bf1eedbaU, 0x3c7cab103e4c8065U, 0x40b471b73caa4b13U,
  0xbe71dd40be20cbb8U, 0xbeed0b703e5d0d98U, 0x3e0d26103e8dbcc0U, 0x3ee8aa3cbdd94bd0U,
  0xbec35068bef1df90U, 0x3d02a2e0befdc4b8U, 0x3e394cc8bd9cf230U, 0xbdca7e30bee25a98U,
  0xbee548b03d5b08c0U, 0x3ee0e0b43dd69d20U, 0xbd878000bdc1faf0U, 0x3d39f9003d3ab2a0U,
  0x3d4b9390bef7d4b0U, 0x3f11c1593e091f00U, 0xbcc22d9e3de85fdeU, 0xc0bfd5dcb9e3e818U,
  0xbef24daa3dab3baaU, 0xbe450bfabd8b5670U, 0xbdcc7736beb09a69U, 0xbe5fbd2a00000000U,
  0xbdca98d2bee8d8edU, 0xbe91fc96U, 0xbed56b94U, 0x0U,
  0x3d6d9a60bdd7ad49U, 0x3d5795f8be80aa2aU, 0xbe44df14be6770e2U, 0x3de4612c3e811da5U,
  0x3e15373ebecf3315U, 0x3e32a356be99efcfU, 0x3e63e156be3ce203U, 0xbe6b6dcbbd3ba288U,
  0xbe7cedbb3de4b624U, 0x3e7431ea3e31af72U, 0xbe076bacbeb937c5U, 0x3d6ff3563e66f4daU,
  0x3ec454813d8bfe2aU, 0x3e6f1d76be9d1898U, 0x3e5a1486bd9c83f9U, 0xbe489d41be4810daU,
  0xbde04064bc025d3dU, 0xbc97a0503ea44189U, 0xbe756181bbd30b00U, 0x3e9188f7be760f24U,
  0x3e99bebbbdbe4224U, 0xbe925656bec8c5e4U, 0xbdaff38cbe542a0eU, 0x3ed312853e0beab2U,
  0x3dcbae65be5ef45aU, 0x3cc11964be17ce67U, 0xbda522d83e960d4aU, 0xbd8d1d353ed50b05U,
  0xbd8ae106bdca94caU, 0x3d918ffcbe8bedb3U, 0x3bc50c40bb589846U, 0xbe5859a7be7c9762U,
  0x3e873fa6be2cb168U, 0x3ec1ff8a3e90e621U, 0xbdeeabe03eb83e9aU, 0xbea38ed6be8e4bd4U,
  0x3ea911bcbe4e78bdU, 0x3e6ce91e3eed2080U, 0xbec80876bdc1560dU, 0x3cea67c0bec4b3fbU,
  0xbdf6326a3ea24d50U, 0xbda2027a3e842b0aU, 0x3e61519ebeb210d5U, 0xbe1f2fe53ea3ad7dU,
  0x3c9123763e3c7f92U, 0x3eada6db3e4b0aceU, 0xbdf07880be740c76U, 0xbea7fc16be825d9aU,
  0x3cfc4270bec57383U, 0xbeb5cc953e240f42U, 0xbeabe24abe50a2aeU, 0x3bdabfc0be690281U,
  0x3e91dae3bea7cbd6U, 0xbe774e4dbea40b90U, 0x3ebcf92dbcbf7780U, 0xbdb4d0c8be903b7eU,
  0x3d0e589abdd33eb0U, 0x3e57a2c33e03851bU, 0xbd2021bc3d11c1efU, 0xbd4730033e8fbd5dU,
  0x3e4db6693e9896caU, 0xbd020d283e5ac234U, 0xbd2c57703e93a7afU, 0xbe90c480be66d6c9U,
  0x3eca4ea9bdae7d13U, 0xbdb7bf50bd255b38U, 0xbea7156dbd8c4d28U, 0x3db6629c3de6972cU,
  0x3e319282be4dca38U, 0xbe735ee53dc5dbd4U, 0xbecf3ed7bec63355U, 0xbe51c017be023714U,
  0xbeeedd3dbe636084U, 0xbe9ba3423ed58569U, 0xbeb537d4bc93c400U, 0xbea15a16becbccbdU,
  0xbe5d5a65bedc905bU, 0xbe0dde58bea00342U, 0xbd853c783ea0df64U, 0x3c4f5b80beacfb3cU,
  0xbe901afebeb006daU, 0xbd3455883e846069U, 0xbec9b4b6bed3a31aU, 0xbec4da4abdc16414U,
  0xbe94eda8be892f60U, 0xbd893fc83ebf2555U, 0x3e2e670abeba903fU, 0xbe1d0b0a3eb3ba55U,
  0xbf748c7bbe8ff1f6U, 0xbe00037a3e298652U, 0x3d6605d83ea24c6dU, 0x3e93a7b4bedc0022U,
  0xbeae28e83e85a3b1U, 0x3e34b622be8a7eb9U, 0xbe870142be985990U, 0xbe211a143d1af718U,
  0xbe18dd103fda4ad3U, 0x3ea31a193e9502deU, 0x3d401204bde47c70U, 0xbdb0f2bf3ea8f9a5U,
  0x3e4b655a3e08b009U, 0x3ed8a5b33ec20768U, 0xbe6b83a9bec18096U, 0x3e8031df3ec1afbfU,
  0x3f5068b83e8476d9U, 0xbec33938be25b54aU, 0x3e4107a4bd9f33dbU, 0x3ca4bdae3db5c2f4U,
  0x3ee8012f3e2a2925U, 0xbda86ec03eb4edabU, 0xbd8d9818be729552U, 0xbe2171543dc2d6d4U,
  0xbec4a0fb3ee9975cU, 0x3ea946073ea7b0f5U, 0xbd6cf888bdf31720U, 0xbeab0ee2bed10078U,
  0x3e7979423d1c91d0U, 0x3cb608603e8899fbU, 0xbe6421abbe91774cU, 0xbe8ad48cbe370d72U,
  0x3dfe13c4bd6c2ba0U, 0x3e42009abde98c80U, 0xbe94f9a2be8cb00cU, 0xbeaaaa70bdeabaccU,
  0xbbfa5180becb39deU, 0xbe50134dbe352de2U, 0xbdc056083e77fa36U, 0x3eb18be9beb500c8U,
  0x3e797302U, 0xbd9adc21U, 0xbd98e120bdc1a463U, 0xbe372c96U,
  0x3f2b6ebaU, 0xbde684d3U, 0xbc41d7623f2a477aU, 0xbdbf2797U,
  0x0U,
};


ai_handle g_network_temperature_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_temperature_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

