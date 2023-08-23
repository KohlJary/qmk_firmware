/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include <stdbool.h>
#include "KohlJary.h"

// clang-format off

/* enum layers{ */
/*     MAC_BASE, */
/*     WIN_BASE, */
/*     _FN1, */
/*     _FN2, */
/*     _FN3 */
/* }; */

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define KJ_SPC  LT(LY1,KC_SPC)
#define KJ_TAB  ALT_T(KC_TAB)
#define KJ_ENT  LT(LYN,KC_ENT)
#define KJ_BSPC LT(LY2,KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LYB] = LAYOUT_ansi_69(
        TD(T_UX), KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_LPRN,  KC_RPRN, QK_LEAD,           KC_MUTE,
        TD(T_GE), KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, GUI_T(KC_MINS),    KC_MPLY,
        TD(T_CE), KC_A,    KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT, KJ_TAB,            TD(T_LY),
        TD(T_LS), KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,              KC_AMPR, KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, TD(T_RS), KC_MS_U,
        KC_HOME,  KC_END,  TD(T_CP),          KJ_SPC,  TD(T_CP),          KJ_ENT,  KJ_BSPC,          TD(T_MB),                    KC_MS_L,  KC_MS_D, KC_MS_R),

    [LYG] = LAYOUT_ansi_69(
        KC_ESC,  _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        KC_TAB,  _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        KC_SCLN, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        KC_LSFT, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______, _______,
        KC_LCTL, _______,  _______,           _______,          KC_BSPC,  _______,          _______,           _______,            _______, _______, _______),

    [LYN] = LAYOUT_ansi_69(
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_ASTR, KC_PLUS, KC_7,    KC_8,    KC_9,    _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_SLSH, KC_MINS, KC_4,    KC_5,    KC_6,              _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, KC_DOT,  KC_0,    KC_1,    KC_2,    KC_3,              _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______, _______,          _______,          KC_BSPC,  _______,          _______,           _______,            _______, _______, _______),

    [LY1] = LAYOUT_ansi_69(
        QK_BOOT, _______,  _______,  _______, _______, _______, _______,     _______, _______, _______, _______,   _______,  _______,  _______,          RGB_TOG,
        _______, LAMBDA,   _______,  _______, _______, _______, RCS(KC_TAB), KC_WBAK, C(KC_L), KC_WFWD, C(KC_TAB), G(KC_P),  G(KC_N),  _______,          _______,
        _______, EQ_NEQ,   PER_AST,  DOL_CIR, AT_HASH, INC_DEC,              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,   _______,  _______,  _______,          _______,
        _______, LTE_GTE,  _______,  _______, _______, _______,              _______, _______, _______, _______,   _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,     _______,          _______,            _______,            _______, _______, _______),

    [LY2] = LAYOUT_ansi_69(
        QK_BOOT, KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,   _______,          RGB_TOG,
        RGB_TOG, KC_ASTR, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_F17,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,  _______,          _______,
        _______, KC_SLSH, KC_MINS, KC_4,    KC_5,    KC_6,             KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F5,   KC_F12,   _______,          _______,
        _______, KC_DOT,  KC_0,    KC_1,    KC_2,    KC_3,    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,   _______,           _______,
        _______, _______, _______,           _______,         _______, _______,          _______,          _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LYB] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LYG] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LY1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LY2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE
