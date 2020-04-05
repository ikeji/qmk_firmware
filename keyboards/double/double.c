/* Copyright 2020 Shun Ikejima
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "double.h"
#include "pointing_device.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.


report_mouse_t mouse_rep;

#define SDIO D1
#define SCK  D0
#define CS   D4

void matrix_init_kb(void) {
    matrix_init_user();
    setPinOutput(SDIO);
    writePinLow(SDIO);
    setPinOutput(SCK);
    writePinLow(SCK);
    setPinOutput(CS);
    writePinLow(CS);
    wait_us(1);
    writePinHigh(CS);
}

uint8_t read(unsigned char addr) {
  uint8_t temp;
  writePinLow(CS);
  temp = addr;
  writePinLow(SCK);

  setPinOutput(SDIO);
  for (int8_t n=0;n<8;n++){
    writePinLow(SCK);
    if (temp & 0x80) {
      writePinHigh(SDIO);
    } else {
      writePinLow(SDIO);
    }
    wait_us(2);
    temp <<=1;
    writePinHigh(SCK);
  }

  temp=0;
  setPinInput(SDIO);
  for (int8_t n=0;n<8;n++){
    wait_us(1);
    writePinLow(SCK);
    wait_us(1);
    temp<<=1;
    if (readPin(SDIO) != 0) {
      temp |= 0x01;
    }
    writePinHigh(SCK);
  }
  wait_us(20);
  writePinHigh(CS);
  return temp;
}

int conv(uint8_t from) {
  if (from > 128) {
    return ((int)from) - 256;
  } else {
    return from;
  }
}

void matrix_scan_kb(void) {
    matrix_scan_user();
    mouse_rep.buttons = 0;
    mouse_rep.h=-conv(read(0x03))/2;
    mouse_rep.v=conv(read(0x04))/2;
    mouse_rep.y=0;
    mouse_rep.x=0;
    pointing_device_set_report(mouse_rep);
}

/*
void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

bool led_update_kb(led_t led_state) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    return led_update_user(led_state);
}
*/
