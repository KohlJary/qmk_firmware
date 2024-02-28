/* Copyright 2022 @ Keychron (https://www.keychron.com)
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
#include "KohlJary.h"

#define KJ_PPLS GUI_T(KC_PPLS)
#define KJ_PEQL CTL_T(KC_PEQL)
#define KJ_PDOT ALT_T(KC_PDOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LYB] = LAYOUT_numpad_6x4(
        KJ_PEQL, KC_PMNS, TG(LYN),  LT(LY1, KC_ESC),
        KJ_PDOT, KJ_PPLS, TG(LYV),  KC_MPLY,
        KC_P1,   KC_P4,   KC_P7,
        KC_P2,   KC_P5,   KC_P8,    KC_TAB,
        KC_P3,   KC_P6,   KC_P9,
        SFT_T(KC_PENT),   KC_P0,    KC_BSPC),

    [LYG] = LAYOUT_numpad_6x4(
        KC_LCTL, KC_G, KC_Y,   _______,
        KC_LSFT, KC_F, KC_T,   KC_TAB,
        KC_Z,    KC_A, KC_Q,
        KC_X,    KC_S, KC_W,   KC_1,
        KC_C,    KC_D, KC_E,
        KC_SPC,        KC_R,   KC_2),

    [LYN] = LAYOUT_numpad_6x4(
        _______,    _______, _______, TO(LYB),
        _______,    _______, C(KC_W), _______,
        KC_WH_D,    KC_MS_L, KC_WH_U,
        _______,    KC_MS_D, KC_MS_U, KC_WBAK,
        KC_BTN2,    KC_MS_R, KC_F5,
        KC_BTN1,             C(KC_T), KC_WFWD),

    [LYV] = LAYOUT_numpad_6x4(
        G(KC_DOT), _______, _______,   TO(LYB),
        _______,   _______, _______,   _______,
        C(KC_X),   G(KC_H), G(KC_P),
        C(KC_C),   G(KC_J), G(KC_K),   KC_F5,
        C(KC_V),   G(KC_L), G(KC_N),
        KC_SPC,             _______,   KC_DEL),

    [LYF] = LAYOUT_numpad_6x4(
        KC_VOLD,    KC_MPRV, KC_MPLY,   _______,
        KC_VOLU,    KC_MNXT, KC_MSTP,   KC_MUTE,
        _______,    _______, _______,
        _______,    _______, _______,   _______,
        _______,    _______, _______,
        _______,             _______,   _______),

    [LY1] = LAYOUT_numpad_6x4(
        _______,  _______, TG(LY2), _______,
        _______,  _______, TG(LYG), KC_NUM,
        KC_F1,    KC_F4,   KC_F7,
        KC_F2,    KC_F5,   KC_F8,   KC_F11,
        KC_F3,    KC_F6,   KC_F9,
        QK_BOOT,           KC_F10,  KC_F12),

    [LY2] = LAYOUT_numpad_6x4(
        _______, _______,  _______,  _______,
        _______, _______,  _______,  _______,
        RGB_VAD, RGB_RMOD, RGB_VAI,
        RGB_HUD, RGB_TOG,  RGB_HUI,  _______,
        RGB_SAD, RGB_MOD,  RGB_SAI,
        RGB_SPD,           RGB_SPI,  _______),

    [LY3] = LAYOUT_numpad_6x4(
        _______,    _______, _______,   _______,
        _______,    _______, _______,   _______,
        _______,    _______, _______,
        _______,    _______, _______,   _______,
        _______,    _______, _______,
        _______,             _______,   _______)//,

    /* [_RESERVED2] = LAYOUT_numpad_6x4( */
    /*     _______,    _______, _______,   _______, */
    /*     _______,    _______, _______,   _______, */
    /*     _______,    _______, _______, */
    /*     _______,    _______, _______,   _______, */
    /*     _______,    _______, _______, */
    /*     _______,             _______,   _______) */
};
