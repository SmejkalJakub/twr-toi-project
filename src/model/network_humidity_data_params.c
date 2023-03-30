/**
  ******************************************************************************
  * @file    network_humidity_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Mar 28 21:39:36 2023
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

#include "network_humidity_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_humidity_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_humidity_weights_array_u64[217] = {
  0x3f0112443c4c7ec6U, 0x3d1f899a398282ccU, 0x3d628d2b3e1c7c42U, 0xb9774e10bcfdb924U,
  0x39d1b188be9f0669U, 0x3d26aaa8be878bf0U, 0x3ec81ba63ec3833fU, 0xbd2f16cf3d749e0eU,
  0x3be7b7c63f6dadf3U, 0x3df3d307bf0eb030U, 0x3a5620703e3ae316U, 0x4087fc0fbcaafe27U,
  0x3b4e5488bd6e8af7U, 0x3ec98966bdbbf742U, 0x3bc6ca77bed1ecd9U, 0xbe9f36653e2ea01cU,
  0xbc6e9116beed890cU, 0xbf171e723d9d1828U, 0xbf5c1fa8bf1ba9ebU, 0x3f589ccebf8de478U,
  0xbdd9a260bddeecc7U, 0xbdd68ef03eeca90cU, 0xbe23fd083e1110b8U, 0x3e6008283e420d90U,
  0xbea2489c3ee99274U, 0x3eecdcb0beca93fcU, 0xbd9b3ed03e9fd250U, 0x3ed5e6603ef17554U,
  0xbb6ac28dbe675548U, 0x3eb58f333cd5503aU, 0xbef4bd8bbf19e7ecU, 0x3e6f152cbf46be73U,
  0xbad1a379bf0aa794U, 0xbef76cddbf043a44U, 0x3eb8f657bda1e0d6U, 0xbe054e793e17bb0fU,
  0x3c2e5a90bf009222U, 0xbdfa67a3be598799U, 0xbf5132a0beb4b5a3U, 0xc010e0073f70afe2U,
  0xbd4001c63edd1f47U, 0xbed051cebe78ae25U, 0xbde76710c05227d0U, 0x4047473c3e15350cU,
  0xbed6d1bcbde88687U, 0x3ecd3cc8bee01038U, 0xbef962e43da9a850U, 0x3edaccc83eac57a4U,
  0xbea6e844bd178c20U, 0x3e1107503e2bfb70U, 0xbe74be583e9f5658U, 0x3ef225743ea0a5a8U,
  0x3dd72bfc3eaf2294U, 0xbf92afeebf211815U, 0x3e4f4bfac01196a6U, 0xc0686b1d3e86ad2cU,
  0xbb6beb6bbfa0024eU, 0xbec4d76bbea7fb28U, 0x3eb5bd7a3e4d2774U, 0xbeca7890be8734f8U,
  0x3e074f7a3ca61e21U, 0xbe970e1cbe85663bU, 0xbca9cd78bf36a6b3U, 0xc08e4541be90c4fcU,
  0xbe3f0030be7dc70eU, 0xbe96f7ec3df47400U, 0xbe42ede03ece701cU, 0xbef2eea03e5945f0U,
  0x3ce9a1183d0de800U, 0x3d8abdd4bdf997fcU, 0xbd8604ddbec05afcU, 0xbff155853e2b2d9eU,
  0xbe9ca89abe6f6d70U, 0xbec5b320bd993611U, 0x0U, 0xbd4b5aa5be639188U,
  0xbec1b11bbe4363f2U, 0x0U, 0xbd3c134ebecacec6U, 0xbe88d0b6U,
  0xbcddbbc5bd1ff679U, 0x3e7d0b363ead3bccU, 0x3eac3f2bbeab55d8U, 0xbd9259f8be86c6adU,
  0xbed1bd56be90e046U, 0xbed49305bed2a5b9U, 0x3d892de73e8881e7U, 0xbec89cb3be545319U,
  0xbebb35553f1334f6U, 0xbdb52f203e1c917eU, 0x3e8d5fa93da8bb14U, 0x3eada1d9be5622f9U,
  0xbed9cfdf3ea5f877U, 0x3e0a644abde15244U, 0x3ccb41a03ea6239bU, 0x3ecc23edbe7717a8U,
  0xbea20718bd45db00U, 0xbe49b33c3de69cc7U, 0xbe846cd63e11de66U, 0x3e82e7203e0fc241U,
  0xbe54fd663eb69d49U, 0xbda0eb6c3e92b229U, 0x3dafb9643df74b30U, 0x3df978843e38f189U,
  0x3d16b488be4f547dU, 0x3d0effe8be35d31cU, 0xbd60a2783edb6e05U, 0xbdd9aae43d5604c8U,
  0xbf01c8bcbf0d12abU, 0xbeac3facbea776d7U, 0x3edc26fbbfbf4e6eU, 0x3e96c7cfbf30a6f1U,
  0xbb1b290b3d1fe56dU, 0x3e589fc8bd4acea6U, 0x3e813cc9beaef1b8U, 0x3e94f325bec035fdU,
  0xbf39eaf4bd9e0e55U, 0x3ea3e4753e89aeabU, 0xbef0beb53ec623aeU, 0x3c8772d0bd8af745U,
  0xbeba2de9bf16cf9bU, 0x3e8692363e3798b4U, 0x3dbb42ac3e87f47dU, 0xbd8a345a3e35d0d1U,
  0x3da535ae3ddcccbaU, 0xbe951a46bdd68998U, 0xbe2deb73bdaa0c16U, 0x3e61d88a3e4f970fU,
  0xbe7b7cd6beb2f189U, 0x3d9f9fc4be2443baU, 0xbc97b0903d795ef8U, 0x3d131be23ebb9bfcU,
  0xbe41f5abbe27f9d4U, 0xbed7903fbd177750U, 0xbdc8e4003dfa4ffaU, 0x3d7967303e30b669U,
  0xbd86e385bd645978U, 0x3e812b01bf12b394U, 0x3e9788833e2c25deU, 0xbee1bd2cbf11a0d7U,
  0xbe22fd583d5c98caU, 0x3e97ad8dbece3b7bU, 0xbeab76d83e965e1aU, 0xbc908620bece755cU,
  0xb9b8e5803e4c01deU, 0xbdb41b5cbe2f6594U, 0xbec4cfc63d248e10U, 0xbe6758413e8d5807U,
  0xbf2929493cfd1edfU, 0x3e8cebfbbe2bad8cU, 0x3e83568bbd90427eU, 0xbce26fd0bf199b84U,
  0xbe150ad9bb04ad80U, 0x3ebb7098beca8776U, 0xbed5efa3be4e24efU, 0x3df247233e84e241U,
  0x3d50d75abe2a80b8U, 0xbe8bddd2bdbf2ab8U, 0x3e9ab8943e28fdaaU, 0xbd111190be24c9b8U,
  0xbe9e30aabf1ac174U, 0x3c4ff140beb03e50U, 0x3e3d9362be617e32U, 0xbeb393f13e977801U,
  0x3e11cc65be4f9feeU, 0xbaaaa6003e393922U, 0xbe85038dbf0a0a74U, 0xbdd1acb0bf00a144U,
  0xbe4a7f51bea8a699U, 0xbdd1b6d4ba8b5900U, 0x3d1bd6e0be8ec38eU, 0xbcd84c203c564a00U,
  0x3e14a7143da3cb3aU, 0xbe0fa4bcbe425e69U, 0x3c58b4c0bf2dea7bU, 0x3e9bc689bf8c97d8U,
  0xbeb6251b3c391dd3U, 0xbdfb9bc3bd8be7b7U, 0x3e99a7d5be5ab4deU, 0xbd467bccbdabcad4U,
  0x3e1f0d4ebf10d8ecU, 0xbedb3038bbd28740U, 0x3d344bb6be3d9c37U, 0xbdfbd8583f15322aU,
  0x3f09013e3db38cefU, 0xbd1039173cb8d77aU, 0xbd99de5cbe4c1b5fU, 0xbe2ad5a6bdddb050U,
  0x3d782627bbd38a59U, 0xbe24c38cbd74bf00U, 0x3d5b44cd3bc777b4U, 0x3de0a5e4bbfaa28fU,
  0xbeb2055cbd21e2c4U, 0xbf865e8e3e282bd2U, 0xbe1b728cbeb1dcd7U, 0x3e5fa0623e83ad28U,
  0x3e9108f0be1aa2fdU, 0xbe75ad10be6b4c4aU, 0x3a736118bde242b8U, 0x3e75a89abdb782b3U,
  0xbb2a862c3f8a5b43U, 0xbf5d0305be306f8fU, 0x3d3569d0bd1d0d00U, 0xbe88d20d3e9a5987U,
  0xc020ba1a3e32335dU, 0x3edd348fbdeb77dcU, 0x3e73d9873f971a44U, 0xbda48934bca96f32U,
  0xbe105dff3f19bc67U, 0xbd5316e800000000U, 0xbe566a63bea77fbaU, 0xbcd57f3abda7f5afU,
  0xbe823915be0c5a95U, 0xbe7dc286be1891f6U, 0xbe6ca3183d1e2838U, 0xbdf1b7973e9c27eeU,
  0xbeb782ebU,
};


ai_handle g_network_humidity_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_humidity_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

