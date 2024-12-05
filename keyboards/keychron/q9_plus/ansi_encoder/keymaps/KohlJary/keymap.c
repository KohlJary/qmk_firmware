/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#define KC_TASK LCA(KC_DEL)
#define KC_FLXP LGUI(KC_E)
#define KC_WSPR LGUI(KC_P)
#define KC_WSBF LGUI(KC_TAB)
#define KC_WSNX LGUI(KC_N)
#define KC_WSNM LGUI(KC_DOT)
#define KC_MAX  LGUI(KC_EQL)
#define KC_TERM LGUI(KC_DOT)
#define KC_PROG LGUI(KC_SPC)

// Web Browser Tab Previous
#define KC_WBTP RCS(KC_TAB)
// Web Browser Tab Next
#define KC_WBTN C(KC_TAB)
// Web Browser Tab Open
#define KC_OPTB RCS(KC_T)

#define KJ_ALTQ TD(T_AQ)
#define KJ_AMPR LT(LY2,KC_AMPR)
#define KJ_BSPC LT(LY2,KC_BSPC)
#define KJ_CDIR TD(T_DR)
#define KJ_CESC TD(T_CE)
#define KJ_COPY TD(T_CP)
#define KJ_CSFT TD(T_CS)
#define KJ_ENT  TD(T_NE)
#define KJ_F12  ALT_T(KC_F12)
#define KJ_GEQL TD(T_GE)
#define KJ_LSFT TD(T_LS)
#define KJ_MINS GUI_T(KC_MINS)
#define KJ_RSFT TD(T_RS)
#define KJ_SCLN LT(LY1,KC_ENT)
#define KJ_SPC  LT(LY1,KC_SPC)
#define KJ_TAB  TD(T_1T)
#define KJ_2TB  LT(LY2,KC_TAB)
#define KJ_TERM TD(T_TM)
#define KJ_UTIL TD(T_UX)

#define KJ_TTY1 LCA(KC_F1)
#define KJ_TTY2 LCA(KC_F2)
#define KJ_TTY3 LCA(KC_F3)
#define KJ_TTY4 LCA(KC_F4)

#define MOD_AS  MOD_LALT | MOD_LSFT
#define MOD_CS  MOD_LCTL | MOD_LSFT
#define OSHT_CS OSM(MOD_CS)
#define OSHT_AS OSM(MOD_AS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LYB] = LAYOUT_54_ansi(
        KJ_GEQL, KC_Q,    KC_W,    KC_E,    KC_R, KC_T,    KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KJ_MINS,          KC_MPLY,
        KJ_CESC, KC_A,    KC_S,    KC_D,    KC_F, KC_G,    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KJ_ALTQ,          KJ_ENT,           KJ_COPY,
        KJ_LSFT, KC_Z,    KC_X,    KC_C,    KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KJ_RSFT,          KC_PGUP,
        KJ_CSFT, KJ_2TB,  DM_REC1, DM_PLY1,       KJ_SPC,              KJ_BSPC,         KC_AMPR, KC_TASK, KJ_UTIL, KC_HOME, KC_PGDN, KC_END),

    [LYG] = LAYOUT_54_ansi(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R, KC_T,    KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KJ_MINS,          KC_MPLY,
        KJ_CESC, KC_A,    KC_S,    KC_D,    KC_F, KC_G,    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT, MO(LY1),       KJ_SPC,              KJ_BSPC,         KC_RALT, MO(LY1), MO(LY2), KC_LEFT, KC_DOWN, KC_RGHT),

    [LYN] = LAYOUT_54_ansi(
        _______, KC_PPLS, KC_7,    KC_8,    KC_9, KC_0,    _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_PMNS, KC_4,    KC_5,    KC_6, _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______, KC_DOT,  KC_1,    KC_2,    KC_3, _______, _______, _______, _______, _______, _______,            _______,           _______,
        KC_LGUI, _______, _______, _______,       _______,                   _______,          _______,  _______,  _______,  _______, _______, _______),

    [LY1] = LAYOUT_54_ansi(
        _______,  KC_LABK, KC_RABK, INC_DEC, LAMBDA,  KC_PGUP, _______, KJ_TERM, KC_WBAK, KC_WFWD,  KC_WBTP,  KC_LPRN, KC_RPRN,  _______,          RGB_TOG,
        _______,  KC_HOME, AND_OR,  LTE_GTE, EQ_NEQ,  KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KJ_CDIR,  _______,           _______,          _______,
        _______,  IF_ELSE, FOR_EAC, KC_NULL, KC_TRUE, KC_PGDN, KC_WBTN, KJ_TTY1, KJ_TTY2, KJ_TTY3,  KJ_TTY4,            _______,           KC_MS_U,
        _______,  _______, _______, _______,          _______,                   QK_LEAD,           _______,  KC_BTN2, KC_BTN1,  KC_MS_L, KC_MS_D, KC_MS_R),

    [LY2] = LAYOUT_54_ansi(
        QK_BOOT, KC_F17,  KC_F18,  KC_F19,  KC_F20, KC_PLUS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   _______, _______, _______,          RGB_TOG,
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_AT,  KC_DLR,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F5,    KJ_F12,           _______,          _______,
        _______, KC_F21,  KC_F22,  KC_F23,  KC_F24, KC_MINS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,             _______,          _______,
        _______, _______, DM_REC2, DM_PLY2,         KJ_TAB,                    _______,          _______,  _______, _______, _______, _______, _______),

    [LY3] = LAYOUT_54_ansi(
        RGB_TOG, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______,          _______,
        _______, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______,  _______,           _______,          _______,
        _______, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______,           _______,           _______,
        _______, _______,  _______, _______,          _______,                   _______,          _______,  _______, _______,  _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LYB]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LYG]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LYN]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LY1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LY2]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LY3]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif
