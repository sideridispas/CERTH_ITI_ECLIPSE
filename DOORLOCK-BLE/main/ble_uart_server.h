/* Sideridis Paschalis - CERTH ITI GR
 * BLE - Door Lock project
 * Header file
 *
 * October 2017
 */

/* Copyright (c) 2017 pcbreflux. All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>. *
 */
#ifndef BLE_UART_SERVER_H_
#define BLE_UART_SERVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define GATTS_SERVICE_UUID   0x0001
//#define GATTS_CHAR_UUID      0xFF01
//#define GATTS_DESCR_UUID     0x3333
#define GATTS_CHAR_NUM		2
#define GATTS_NUM_HANDLE     1+(3*GATTS_CHAR_NUM)


#define BLE_MANUFACTURER_DATA_LEN  2

#define GATTS_CHAR_VAL_LEN_MAX		16

#define BLE_PROFILE_APP_ID 0

void gatts_profile_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);
void gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

void char1_write_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void char2_read_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);

void lock_arm();
void unlock();
void generate_store_RND_PS();
void ble_init();
void vTimout(void *pvParameters);
void vBlinking(void *pvParameters);
void vErrorLED(void *pvParameters);

void printHex16(char* text, unsigned char* hex_var);

#ifdef __cplusplus
}
#endif

#endif /* BLE_UART_SERVER_H_ */
