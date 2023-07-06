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

/*
 * Keycode Reference
 * =================
 *
 * G(KC_GRV): Toggle Quake terminal
 * G(KC_1-KC_0): Switch workspaces/applications
 * G(KC_EQL): Fullscreen active window
 * G(KC_P): Previous workspace
 * G(KC_N): Next workspace
 * G(KC_TAB): Workspace back and forth
 * G(KC_SPC): Open application search
 * G(KC_ENT): Open new terminal window
 *
 * TD(T_LS): Single tap; shift next character, Hold; shift modifier, Double tap; home, Double tap + hold; Ctrl+Alt+Shift
 * TD(T_RS): Single tap; caps word toggle, Hold; shift modifier, Double tap; end, Double tap + hold; Ctrl+Alt
 *
 * TD(T_CE): Single tap; Escape, Hold: Ctrl, Double tap hold; Ctrl+Shift
 * TD(T_AQ): Single tap; ', Hold; Alt, Double tap; `, Double tap hold; Alt+Shift
 * TD(T_GE): Single tap; =, Hold; Gui, Double tap hold; Gui+Shift
 * TD(T_UX): Single tap; Quake terminal, Hold; T_RSTRT behavior, Double tap; Fullscreen, Double tap hold; Ctrl+Alt+Del
 *
 * TD(T_CP): Single tap; Copy, Hold; Paste, Double tap; Cut, Double tap hold; Screen capture tool
 *
 * EQ_NEQ: ==, hold for !=
 * INC_DEC: ++, hold for --
 * LTE_GTE: <=, shifted for >=
 * LAMBDA: =>, shifted for ->
 * AT_HASH: tap for @, long press for #
 * DOL_CIR: tap for $, long press for ^
 * PER_AST: tap for %, long press for *
 * T_RSTRT: press for Ctrl+C, release for Up, Enter (restart terminal process)
 * UC_STRT: start unicode character input
 *
 * KC_AMPR: Shift for |, Ctrl for !
 * KC_MINS: Ctrl for +
 * KC_SLSH: Ctrl for \
 * KC_DOT: Shift for !
 * KC_COMM: Shift for ~
 * KC_LBRC/KC_RBRC: Ctrl for (), Ctrl+Shift for <>
 *
 * KC_BSPC: Shift for Delete
 *
 * KC_MPLY: Ctrl for next track, Ctrl+Shift for prev track, Alt for vol up, Alt+Shift for vol down, Ctrl+Alt for mute
 *
 * KC_BTN1: Alt for R click
 * KC_WH_U: Shift for wheel down
 *
 * QK_LEAD: Shift for F24 (vim leader key)
 * QK_REP: Shift for alternate repeat key
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_B] = LAYOUT_moonlander(
        TD(T_UX), KC_1,    KC_2,   KC_3,     KC_4,    KC_5, UC_NEXT,             KC_MPLY,   KC_6,   KC_7,    KC_8,    KC_9,   KC_0,    OSL(L_F),
        TD(T_GE), KC_Q,    KC_W,   KC_E,     KC_R,    KC_T, QK_LEAD,             KC_AMPR,   KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    GUI_T(KC_MINS),
        TD(T_CE), KC_A,    KC_S,   KC_D,     KC_F,    KC_G, KC_LBRC,             KC_RBRC,   KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, TD(T_AQ),
        TD(T_LS), KC_Z,    KC_X,   KC_C,     KC_V,    KC_B,                                 KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, TD(T_RS),
        KC_BTN1,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,       G(KC_SPC),           G(KC_ENT),         KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, T_RSTRT,
                      LT(L_2,KC_SPC), LT(L_1,KC_TAB), TD(T_CP),                             QK_REP, LT(L_2, KC_ENT),  LT(L_1,KC_BSPC)
    ),

    [L_G] = LAYOUT_moonlander(
        KC_ESC,  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, KC_Y,              _______, _______, _______, _______, _______, _______, _______,
        KC_SCLN, _______, _______, _______, _______, _______, KC_H,              _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_6,    KC_7,    KC_8,    KC_9,             KC_GRV,            _______,          _______, _______, _______, _______, _______,
                                   KC_SPC,  KC_BSPC, KC_EQL,                              _______, _______, _______
    ),

    [L_F] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,            KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [L_1] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,  _______, QK_BOOT,
        _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_P),           G(KC_N), G(KC_6), G(KC_7), G(KC_8), G(KC_9),  G(KC_0), _______,
        _______, EQ_NEQ,  PER_AST, DOL_CIR, AT_HASH, INC_DEC, KC_PGDN,           KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, LTE_GTE, _______,
        _______, LAMBDA,  LTE_GTE, _______, _______, _______,                             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_WH_U, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______,  _______, TG(L_G),
                                   KC_SPC,  UC_STRT, KC_ESC,                              _______, KC_BTN1, KC_BTN2
    ),

    [L_2] = LAYOUT_moonlander(
        QK_BOOT, RGB_HUD, RGB_HUI,  RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,          KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  TG(L_G),
        _______, KC_ASTR, KC_SLSH,  KC_7,     KC_8,    KC_9,   RGB_SPI,          KC_F17,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
        _______, KC_PLUS, KC_MINS,  KC_4,     KC_5,    KC_6,   RGB_SPD,          _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F5,   ALT_T(KC_F12),
        _______, KC_DOT,  KC_0,     KC_1,     KC_2,    KC_3,                              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,   _______,
        _______, _______, RGB_RMOD, RGB_TOG, RGB_MOD,          _______,          _______,          _______, _______, _______, _______, _______,
                                    _______, _______, _______,                            _______, _______, _______
    ),

    [L_3] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};
