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
 * TD(T_CE): Single tap; Escape, Hold: Ctrl, Double tap; QMK leader, Double tap hold; Ctrl+Shift
 * TD(T_AQ): Single tap; ', Hold; Alt, Double tap; F24 (vim leader), Double tap hold; Alt+Shift
 * TD(T_GE): Single tap; =, Hold; Gui, Double tap hold; Gui+Shift
 * TD(T_UX): Single tap; Quake terminal, Hold; Ctrl+C, Double tap; Fullscreen, Double tap hold; T_RSTRT behavior
 *
 * TD(T_CP): Single tap; Copy, Hold; Paste, Double tap; Cut, Double tap hold; Screen capture tool
 * TD(T_MB): Single tap/hold; M1, Double tap; M2, Double tap hold; M3
 * TD(T_LY): 1; TG(L_M), 2; TG(L_F), 3; TG(L_G), 4; Ctrl+Alt+Del
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
 * KC_DOT: Shift for !
 * KC_COMM: Shift for ~
 *
 * KC_BSPC: Shift for Delete
 * KC_WH_U: Shift for wheel down
 *
 * KC_MINS: Ctrl for +
 * KC_SLSH: Ctrl for \
 * KC_QUOT/TD(T_AQ): Ctrl for `
 *
 * KC_LBRC/KC_RBRC: Ctrl for (), Ctrl+Shift for <>
 *
 * KC_MPLY: Ctrl for next track, Ctrl+Shift for prev track, Alt for vol up, Alt+Shift for vol down, Ctrl+Alt for mute
 * QK_LEAD: Shift for F24 (vim leader key)
 * QK_REP: Shift for alternate repeat key
 */

#define KJ_SPC  LT(LY2,KC_SPC)
#define KJ_TAB  LT(LY1,KC_TAB)
#define KJ_ENT  LT(LY2,KC_ENT)
#define KJ_BSPC LT(LY1,KC_BSPC)
#define CS_HOME RCS_T(KC_HOME)
#define CA_END  LCA_T(KC_END)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LYB] = LAYOUT_moonlander(
        TD(T_UX), KC_1,    KC_2,    KC_3,    KC_4,    KC_5, TD(T_CP),            KC_MPLY,   KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    TD(T_LY),
        TD(T_GE), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, QK_LEAD,             KC_AMPR,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    GUI_T(KC_MINS),
        TD(T_CE), KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LBRC,             KC_RBRC,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, TD(T_AQ),
        TD(T_LS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, TD(T_RS),
        CS_HOME,  G(KC_1), G(KC_2), G(KC_3), G(KC_4),       G(KC_SPC),           G(KC_ENT),          KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, CA_END,
                                    KJ_SPC,  KJ_TAB,  TD(T_CP),                             MO(LYN), KJ_ENT,  KJ_BSPC
    ),

    [LYG] = LAYOUT_moonlander(
        KC_ESC,  _______, _______, _______, _______, _______, KC_6,              _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, KC_Y,              _______, _______, _______, _______, _______, _______, _______,
        KC_SCLN, _______, _______, _______, _______, _______, KC_H,              _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_7,    KC_8,    KC_9,    KC_0,             KC_GRV,            _______,          _______, _______, _______, _______, _______,
                                            KC_SPC,  KC_BSPC, KC_EQL,            _______, _______, _______
    ),

    [LYN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_ASTR, KC_PLUS, KC_7,    KC_8,    KC_9,    _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_SLSH, KC_MINS, KC_4,    KC_5,    KC_6,    _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_DOT,  KC_0,    KC_1,    KC_2,    KC_3,                                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, KC_BSPC,           _______, _______, _______
    ),

    [LYF] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,            KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [LYM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, TD(T_MB),
                                            _______, _______, _______,           _______, _______, _______
    ),

    [LY1] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______,     _______, _______, _______,  _______,   QK_BOOT,
        _______, LAMBDA,  _______, _______, _______, _______, KC_F24,            _______, RCS(KC_TAB), KC_WBAK, C(KC_L), KC_WFWD,  C(KC_TAB), _______,
        _______, EQ_NEQ,  PER_AST, DOL_CIR, AT_HASH, INC_DEC, _______,           _______, KC_LEFT,     KC_DOWN, KC_UP,   KC_RIGHT, KC_F12,    _______,
        _______, LTE_GTE, _______, _______, _______, _______,                             _______,     _______, _______, _______,  TD(T_DR),  _______,
        _______, G(KC_5), G(KC_6), G(KC_7), G(KC_8),          _______,           _______,              _______, _______, _______,  _______,   _______,
                                            KC_SPC,  UC_STRT, KC_ESC,            UC_NEXT, _______,     _______
    ),

    [LY2] = LAYOUT_moonlander(
        QK_BOOT, _______, _______, _______,  _______, _______, _______,          KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  _______,
        _______, DM_REC2, DM_REC1, RGB_HUI,  RGB_SAI, RGB_VAI, RGB_SPI,          KC_F17,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
        _______, DM_PLY2, DM_PLY1, RGB_RMOD, RGB_TOG, RGB_MOD, RGB_SPD,          _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F5,   ALT_T(KC_F12),
        _______, _______, _______, RGB_HUD,  RGB_SAD, RGB_VAD,                            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,   _______,
        _______, _______, _______, _______,  _______,          _______,          _______,          _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______, _______, _______
    ),

    [LY3] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};
