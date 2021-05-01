/* Copyright 2021 Shun Ikejima
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


#define KC(a) (KC_##a)

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29 \
) { \
    { KC(k00), KC(k01), KC(k02), KC(k03), KC(k04), KC(k05), KC(k06), KC(k07), KC(k08), KC(k09), }, \
    { KC(k10), KC(k11), KC(k12), KC(k13), KC(k14), KC(k15), KC(k16), KC(k17), KC(k18), KC(k19), }, \
    { KC(k20), KC(k21), KC(k22), KC(k23), KC(k24), KC(k25), KC(k26), KC(k27), KC(k28), KC(k29), }, \
}
