/* Copyright 2022 @ Keychron (https://www.keychron.com)
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
#define KC_WSPR LGUI(KC_P)
#define KC_WSNX LGUI(KC_N)

#define KJ_SPC  LT(LY1,KC_SPC)
#define KJ_TAB  LT(LY2,KC_TAB)
#define KJ_ENT  LT(LYN,KC_ENT)
#define KJ_BSPC LT(LY2,KC_BSPC)
#define KJ_QUOT ALT_T(KC_QUOT)

#define CS_HOME RCS_T(KC_HOME)
#define CA_END LCA_T(KC_END)

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LYB] = LAYOUT_ansi_89(
        KC_MPLY,  TD(T_UX), G(KC_P), G(KC_TAB), G(KC_N),  G(KC_DOT), G(KC_SPC), G(KC_ENT),G(KC_EQL),LAMBDA,   AT_HASH,  DOL_CIR,  PER_AST,  LAMBDA,   TG(LYF),           T_RSTRT,
        _______,  KC_AMPR,  KC_1,    KC_2,      KC_3,     KC_4,      KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LPRN,  KC_RPRN,  KC_CAPS,           TD(T_CP),
        _______,  TD(T_GE), KC_Q,    KC_W,      KC_E,     KC_R,      KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  GUI_T(KC_MINS),    KC_WH_U,
        QK_LEAD,  TD(T_CE), KC_A,    KC_S,      KC_D,     KC_F,      KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KJ_QUOT,            QK_LEAD,           KC_WH_D,
        _______,  TD(T_LS), KC_Z,    KC_X,      KC_C,     KC_V,      KC_B,      KC_ENT,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  TD(T_RS),          KC_MS_U,
        _______,  CS_HOME,  CA_END,             KC_ENT,   KJ_SPC,    KJ_TAB,              KJ_BSPC,            TD(T_MB),                               KC_MS_L, KC_MS_D,  KC_MS_R),

    [LYG] = LAYOUT_ansi_89(
        _______,  KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_ENT,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,   KC_SCLN,                       KC_BSPC,            KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LYF] = LAYOUT_ansi_89(
        _______,    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),

    [LY1] = LAYOUT_ansi_89(
        RGB_TOG,  QK_BOOT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,       KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,   _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,  _______,  _______,  _______,   _______,  _______,  _______,            _______,
        _______,  _______,  LAMBDA,   AT_HASH,  KC_7,     KC_8,     KC_9,      RCS(KC_TAB), KC_WBAK,  C(KC_L),  KC_WFWD,  C(KC_TAB), KC_WSPR,  KC_WSNX,  KC_TASK,            _______,
        _______,  _______,  PER_AST,  DOL_CIR,  KC_4,     KC_5,     KC_6,      KC_LEFT,     KC_DOWN,  KC_UP,    KC_RGHT,  C(KC_L),   C(KC_F),            _______,            _______,
        _______,  _______,  LTE_GTE,  KC_0,     KC_1,     KC_2,     KC_3,      _______,     NK_TOGG,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  _______,            _______,  _______,  _______,                          _______,            _______,                       _______,  _______,  _______),

    [LY2] = LAYOUT_ansi_89(
        RGB_TOG,  QK_BOOT,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   KC_F17,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F5,    KC_F12,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F6,     _______,  _______,  _______,
        _______,  _______,  _______,            _______,  KC_ENT,   _______,                       _______,            _______,                       _______,  _______,  _______),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LYB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LY1]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [LYG] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LY2]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE
