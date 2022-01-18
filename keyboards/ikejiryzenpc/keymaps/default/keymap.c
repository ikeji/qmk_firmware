// Copyright 2021 Shun Ikejima (@Shun Ikejima)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.h"
#include "pointing_device.h"
#include "print.h"

#define _BASE 0
#define _L 1
#define _R 2
#define _GUI 3
#define _FN 6

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MYKEY = SAFE_RANGE,
  MACRO1,
  MACRO2,
  MACRO3,
  MACRO4,
  MACRO5,
};

#define CANDE   CTL_T(KC_ESC)
#define AANDT   ALT_T(KC_TAB)
#define SANDE   SFT_T(KC_ENT)
#define SANDS   SFT_T(KC_SPC)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)
#define EANDL   LT(_L, KC_ENT)
#define BANDL   LT(_L, KC_BSPC)
#define EANDR   LT(_R, KC_ENT)
#define EANDG   GUI_T(KC_ENT)
#define EANDLG  LT(_GUI, KC_ENT)


#define MBTN1   KC_MS_BTN1
#define MBTN2   KC_MS_BTN2
#define MBTN3   KC_MS_BTN3

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CANDE ,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  MO(_FN), KC_LALT, KC_LCTL, KC_LGUI, BANDL,   SANDS,   SANDS,EANDR,MO(_GUI), KC_RGUI, KC_RALT, MO(_FN) \
),

[_L] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, KC_UNDS,   KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, _______, S(KC_NUHS),S(KC_NUBS),_______,_______,_______, \
  _______, _______, _______, _______, _______, MBTN1,   MBTN2,   MBTN3,   _______, _______, _______, _______ \
),

[_R] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, MBTN1,   MBTN2,   _______, _______, _______, _______, _______ \
),

#define G(kc) LGUI(kc)

[_GUI] =  LAYOUT( \
  _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, \
  _______, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), _______, KC_INS,  _______, _______, _______, _______, _______, \
  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

#undef G


[_FN] =  LAYOUT( \
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
  _______, KC_F11,  KC_F12,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_HOME, \
  _______, MACRO1,  MACRO2,  MACRO3,  MACRO4,  MACRO5,  _______, _______, FN_BACK, FN_FORD, KC_PGDN, KC_END, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MACRO1:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("p") SS_DELAY(100) "keymacro.sh 1" SS_TAP(X_ENT));
      }
      break;
    case MACRO2:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("p") SS_DELAY(100) "keymacro.sh 2" SS_TAP(X_ENT));
      }
      break;
    case MACRO3:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("p") SS_DELAY(100) "keymacro.sh 3" SS_TAP(X_ENT));
      }
      break;
    case MACRO4:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("p") SS_DELAY(100) "keymacro.sh 4" SS_TAP(X_ENT));
      }
      break;
    case MACRO5:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("p") SS_DELAY(100) "keymacro.sh 5" SS_TAP(X_ENT));
      }
      break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SANDS:
      return 3000;
    case EANDL:
    case EANDR:
      return 100;
    case CANDE:
      return 200;
    default:
      return 500;
  }
}

// Joystick
// Set Pins
// uint8_t xPin  = 8;   // VRx / /B4
// uint8_t yPin  = 7;   // VRy // B5
// uint8_t swPin = E6;  // SW

// Set Parameters
uint16_t minAxisValue = 150;
uint16_t maxAxisValue = 830;

uint8_t maxCursorSpeed = 5;
uint8_t precisionSpeed = 1;
uint8_t speedRegulator = 20;  // Lower Values Create Faster Movement

int8_t xPolarity = 1;
int8_t yPolarity = 1;

uint8_t cursorTimeout = 10;

int32_t xOrigin, yOrigin;

uint16_t lastCursor = 0;

int16_t axisCoordinate(pin_t pin, uint16_t origin) {
    int8_t  direction;
    int16_t distanceFromOrigin;
    int16_t range;

    int16_t position = analogReadPin(pin);
//    printf("position: %d\n", position);

    if (origin == position) {
        return 0;
    } else if (origin > position) {
        distanceFromOrigin = origin - position;
        range              = origin - minAxisValue;
        direction          = -1;
    } else {
        distanceFromOrigin = position - origin;
        range              = maxAxisValue - origin;
        direction          = 1;
    }

    float   percent    = (float)distanceFromOrigin / range;
    int16_t coordinate = (int16_t)(percent * 100);
    if (coordinate < 0) {
        return 0;
    } else if (coordinate > 100) {
        return 100 * direction;
    } else {
        return coordinate * direction;
    }
}

int8_t axisToMouseComponent(pin_t pin, int16_t origin, uint8_t maxSpeed, int8_t polarity) {
    int coordinate = axisCoordinate(pin, origin);
    if (coordinate != 0) {
        float percent = (float)coordinate / 100;
        if (get_mods() & MOD_BIT(KC_LSFT)) {
            return percent * precisionSpeed * (abs(coordinate) / speedRegulator) / polarity;
        } else {
            return percent * maxCursorSpeed * (abs(coordinate) / speedRegulator) / polarity;
        }
    } else {
        return 0;
    }
}

void pointing_device_task(void) {
    report_mouse_t report = pointing_device_get_report();

    // todo read as one vector
    if (timer_elapsed(lastCursor) > cursorTimeout) {
        lastCursor = timer_read();
        if (layer_state_is(_R)) {
          report.h   =   axisToMouseComponent(A0, xOrigin, 1, 15);
          report.v   = - axisToMouseComponent(A1, yOrigin, 1, 15);
        } else {
          report.x   = axisToMouseComponent(A0, xOrigin, maxCursorSpeed, xPolarity);
          report.y   = axisToMouseComponent(A1, yOrigin, maxCursorSpeed, yPolarity);
        }
    }
    //
    /*
    if (!readPin(E6)) {
        report.buttons |= MOUSE_BTN1;
    } else {
        report.buttons &= ~MOUSE_BTN1;
    }
    */

    pointing_device_set_report(report);
    pointing_device_send();
}

void pointing_device_init(void) {
  // init pin? Is needed?
  //setPinInputHigh(E6);
  // Account for drift
  xOrigin = 0;
  for (int i=0;i<1000;i++) {
    xOrigin += analogReadPin(A0);
  }
  xOrigin/=1000;
  yOrigin = 0;
  for (int i=0;i<1000;i++) {
    yOrigin += analogReadPin(A1);
  }
  yOrigin/=1000;
}
