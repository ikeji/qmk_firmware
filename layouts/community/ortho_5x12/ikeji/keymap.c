#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _L 1
#define _R 2
#define _GUI 3
#define _FN 6

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define CANDE   CTL_T(KC_ESC)
#define FN_BACK LALT(KC_LEFT)
#define FN_FORD LALT(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CANDE ,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, MO(_L),  KC_SPC,  KC_BSPC, KC_ENT,  KC_SPC,  MO(_R),  MO(_GUI),KC_RGUI, KC_RSFT, MO(_FN) \
),

[_L] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  XXXXXXX, XXXXXXX, KC_F12,S(KC_NUHS),S(KC_NUBS),_______,_______,_______, \
  _______, _______, _______, _______, _______, KC_ENT,  KC_TRNS, KC_TRNS, KC_ENT,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_R] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  XXXXXXX, XXXXXXX, KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_ENT,  KC_TRNS, KC_TRNS, KC_ENT,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

#define G(kc) LGUI(kc)

[_GUI] =  KEYMAP( \
  _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), XXXXXXX, XXXXXXX, G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, \
  _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), XXXXXXX, XXXXXXX, G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, \
  _______, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, \
  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______, _______ \
),

#undef G

[_FN] =  KEYMAP( \
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, _______, \
  _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  FN_BACK, FN_FORD, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, _______, _______, _______, _______, _______, _______ \
),                                                      

};
