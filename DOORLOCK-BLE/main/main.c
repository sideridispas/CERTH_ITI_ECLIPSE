/* Sideridis Paschalis - CERTH ITI GR
 * BLE - Door Lock project
 * Main function file
 *
 * October 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "bt.h"
#include "bta_api.h"

#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_main.h"

#include "sdkconfig.h"

#include "ble_uart_server.h"

#define GATTS_TAG "MAIN"

void app_main() {

	printf("Initialization..\n");

	//Lock the door before anything
	lock_arm();

	//Setup of BLE processes and start the BLE Server
	ble_init();

	printf("Ready\n");

    return;
}
