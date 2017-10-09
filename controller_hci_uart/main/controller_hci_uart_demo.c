// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdio.h>
#include <string.h>
#include "nvs_flash.h"
#include "bt.h"
#include "driver/uart.h"
#include "esp_log.h"


#define ECHO_TEST_TXD  (17)
#define ECHO_TEST_RXD  (16)

#define ECHO_TEST_RTS  (18)
#define ECHO_TEST_CTS  (19)

#define BUF_SIZE (1024)


static const char *tag = "CONTROLLER_UART_HCI";

static void uart_gpio_reset(void)
{
	const int uart_num = UART_NUM_1;
	    //const int uart_num = UART_NUM_2;
	    uart_config_t uart_config = {
	        .baud_rate = 115200,
	        .data_bits = UART_DATA_8_BITS,
	        .parity = UART_PARITY_DISABLE,
	        .stop_bits = UART_STOP_BITS_1,
	        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
	        .rx_flow_ctrl_thresh = 122,
	    };
	    //Configure UART1 parameters
	    uart_param_config(uart_num, &uart_config);
	    //Set UART1 pins(TX: IO4, RX: I05, RTS: IO18, CTS: IO19)
	    uart_set_pin(uart_num, ECHO_TEST_TXD, ECHO_TEST_RXD, ECHO_TEST_RTS, ECHO_TEST_CTS);
	    //Install UART driver (we don't need an event queue here)
	    //In this example we don't even use a buffer for sending data.
	    uart_driver_install(uart_num, BUF_SIZE * 2, 0, 0, NULL, 0);
}

void app_main()
{ 

    esp_err_t ret;

    /* Initialize NVS — it is used to store PHY calibration data */
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );


    /* As the UART1/2 pin conflict with flash pin, so do matrix of the signal and pin */
    uart_gpio_reset();

    ESP_LOGE(tag, "HEREEEEE #1");

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ret = esp_bt_controller_init(&bt_cfg);
    if (ret != ESP_OK) {
        ESP_LOGE(tag, "Bluetooth Controller initialize failed, ret %d", ret);
        return;
    }
    ESP_LOGE(tag, "HEREEEEE #2");

    ret = esp_bt_controller_enable(ESP_BT_MODE_BTDM);
    if (ret != ESP_OK) {
        ESP_LOGE(tag, "Bluetooth Controller initialize failed, ret %d", ret);
        return;
    }
    ESP_LOGE(tag, "HEREEEEE #3");
}

