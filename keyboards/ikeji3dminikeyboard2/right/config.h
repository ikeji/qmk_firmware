// Copyright 2022 Shun Ikejima (@Shun Ikejima)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define ANALOG_JOYSTICK_X_AXIS_PIN A1
#define ANALOG_JOYSTICK_Y_AXIS_PIN A0

#define SELECT_SOFT_SERIAL_SPEED 3
#define DISABLE_SYNC_TIMER
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y
#define ANALOG_JOYSTICK_AXIS_MIN 165
#define ANALOG_JOYSTICK_AXIS_MAX 960
