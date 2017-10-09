#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"

#include "hwcrypto/aes.h"

#define BLINK_GPIO 13

esp_aes_context  aes_con = {
	.nr				= 1,
	.rk		= ???
};

void app_main()
{
    printf("Hello there\n");

}
