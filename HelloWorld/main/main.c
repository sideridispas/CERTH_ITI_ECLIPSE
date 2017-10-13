//#include <stdio.h>
//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
//#include "esp_system.h"
//#include "driver/gpio.h"
//
//#include "hwcrypto/aes.h"
//
//#define BLINK_GPIO 13
//
////uint8_t priv_key[32] = "hereHaveTheKeyThatKeepsTheSecret";
//
//esp_aes_context  aes_ctx = {
//	.key_bytes = 32,
//	.key = "hereHaveTheKeyThatKeepsTheSecret",
//};
//
//void app_main()
//{
//    printf("Hello there\n");
//
//    //esp_aes_init(aes_con);
//
//    const unsigned char input[16] = "hohoho";
//    unsigned char output[16];
//    unsigned char final_output[16];
//
//    esp_aes_encrypt(&aes_ctx, input, output);
//
//    printf("Input: %.*s\n",16,input);
//    printf("Output: %.*s\n",16,output);
//
//    esp_aes_decrypt(&aes_ctx, output, final_output);
//    printf("Final Output: %.*s\n",16,final_output);
//
//
//    const unsigned char final_o[16] = {0x0e,0xf4,0xf1,0x04,0x8a,0x57,0xcc,0x77,0x4b,0x99,0x3b,0x91,0xa2,0xb1,0x64,0x04};
//
//    esp_aes_decrypt(&aes_ctx, final_o, final_output);
//    printf("Final Output: %.*s\n",16,final_output);
//
//}
