/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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



#include QMK_KEYBOARD_H
#include "version.h"
#include "KohlJary.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_B] = LAYOUT_moonlander(
        G(KC_GRV),     KC_1, KC_2,  KC_3,    KC_4, KC_5, OSL(L_2),       OSL(L_1),  KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_GRV,
        GUI_T(KC_EQL), KC_Q, KC_W,  KC_E,    KC_R, KC_T, KC_PGUP,        KC_PGDN,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    ALT_T(KC_MINS),
        CTL_T(KC_ESC), KC_A, KC_S,  KC_D,    KC_F, KC_G, KC_HOME,        KC_END,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, USR_QT,
        KC_LSFT,       KC_Z, KC_X,  KC_C,    KC_V, KC_B,                            KC_N,    KC_M,  KC_COMM, KC_DOT,  SLSH_BS, CW_TOGG,
        QK_LEAD,    _______,_______,DM_PLY2, DM_PLY1, G(KC_SPC),         G(KC_ENT), QK_LEAD, KC_DOWN, KC_LBRC, KC_RBRC, QK_LEAD,
                              LT(L_1,KC_SPC), KC_TAB, C(KC_C),           C(KC_V), BSP_DEL, LT(L_2,KC_ENT)
    ),

    [L_1] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,            KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_BOOT,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_LCBR, KC_RCBR, KC_LABK,           KC_RABK, LAMBDA,  TD(T_EQ),TD(T_IN),TD(T_AO),KC_ASTR, _______,
        _______, KC_CIRC, KC_PERC, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR,           KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_GRV,  KC_WH_U,
        _______, KC_AMPR, KC_ASTR, KC_TILD, KC_LBRC, KC_RBRC,                             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BSLS, KC_WH_D,
        _______, _______, _______, DM_REC2, DM_REC1,          _______,           _______,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            _______, _______, _______,           _______, KC_MS_BTN2, KC_MS_BTN1
    ),

    [L_2] = LAYOUT_moonlander(
        LED_LEVEL,  RGB_RMOD,RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,           RGB_VAD, RGB_VAI, _______, _______, _______, _______, QK_BOOT,
TOGGLE_LAYER_COLOR, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, RGB_SAD,           RGB_SAI, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
        RGB_TOG,    KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLSH, RGB_VAD,           RGB_VAI, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F5,   _______,
        KC_DOT,     KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,                              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F11,  _______,
        _______,    _______, _______, _______, _______,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                  _______, _______, _______,                              _______, _______, _______
    ),
};
