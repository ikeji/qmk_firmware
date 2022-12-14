// Copyright 2021 Shun Ikejima (@Shun Ikejima)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define XXX KC_Z
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) { \
    { k00, k01, k02, k03, k04, k05, XXX, XXX, XXX, XXX }, \
    { k10, k11, k12, k13, k14, k15, XXX, XXX, XXX, XXX }, \
    { k20, k21, k22, k23, k24, k25, XXX, XXX, XXX, XXX }, \
    { k30, k31, k32, k33, k34, k35, XXX, XXX, XXX, XXX }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, k06, k16, k26, k36 }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, k07, k17, k27, k37 }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, k08, k18, k28, k38 }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, k09, k19, k29, k39 }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, k0a, k1a, k2a, k3a }, \
    { XXX, XXX, XXX, XXX, XXX, XXX, k0b, k1b, k2b, k3b }, \
}
