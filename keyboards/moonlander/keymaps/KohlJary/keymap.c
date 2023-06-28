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
 * G(KC_SPC): Open application search
 * G(KC_ENT): Open new terminal window
 *
 * TD(T_LS): Single tap; shift next character, Hold; shift modifier, Double tap; open parnenthesis
 * TD(T_RS): Single tap; caps word toggle, Hold; shift modifier, Double tap; closing parnenthesis
 * TD(T_2L): Single tap; leader key, Hold; activate layer 2 momentary
 *
 * TD(T_CE): Single tap; Escape, Hold: Control, Double tap hold; Control+Alt
 * TD(T_EQ): Single tap; ==, Long tap; !=
 * TD(T_IN): Single tap; ++, Double tap; --
 * TD(T_AO): Single tap; &&, Double tap; ||
 *
 * EQ_NEQ: ==, shifted for !=
 * LTE_GTE: <=, shifted for >=
 * LAMBDA: =>, shifted for ->
 * AND_OR: &, shifted for |
 * SLSH_BS: /, ctrl for \
 * USR_QT: hold for alt, tap for ', ctrl tap for `
 *
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_B] = LAYOUT_moonlander(
        G(KC_GRV),      KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,       G(KC_EQL), KC_6, KC_7,    KC_8,    KC_9,   KC_0,    T_RSTRT,
        GUI_T(KC_EQL),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, EQ_NEQ,        QUE_EXC,   KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    GUI_T(KC_MINS),
        TD(T_CE),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G, AND_OR,        QK_LEAD,   KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, ALT_T(KC_QUOT),
        TD(T_LS),       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N, KC_M,    KC_COMM, KC_DOT, SLSH_BS, TD(T_RS),
        KC_CALC,        _______, _______, _______, _______,       G(KC_SPC),     G(KC_ENT),       KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, TG(L_G),
                                  LT(L_2,KC_SPC), LT(L_1,KC_TAB), LSG(KC_S),     QK_REP,  LT(L_2, KC_ENT), LT(L_1,KC_BSPC)
    ),

    [L_G] = LAYOUT_moonlander(
        KC_ESC,  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, KC_Y,              _______, _______, _______, _______, _______, _______, _______,
        KC_SCLN, _______, _______, _______, _______, _______, KC_H,              _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_6,    KC_7,    KC_8,    KC_9,             KC_GRV,            _______,          _______, _______, _______, _______, _______,
                                                      KC_SPC, KC_BSPC, KC_EQL,            _______, _______, _______
    ),

    [L_F] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [L_1] = LAYOUT_moonlander(
        LCA(KC_DEL), LCA(KC_F1), LCA(KC_F2), LCA(KC_3), LCA(KC_F4), LCA(KC_F5), _______,              _______, LCA(KC_F6), LCA(KC_F7), LCA(KC_F8), LCA(KC_F9), LCA(KC_F10),QK_BOOT,
        _______,     KC_EXLM,    KC_AT,      KC_HASH,   KC_LBRC,    KC_RBRC,    LAMBDA,               _______, KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_PGUP,    GUI_T(KC_PGDN),
        _______,     KC_CIRC,    KC_PERC,    KC_DLR,    KC_LCBR,    KC_RCBR,    INC_DEC,              KC_F24,  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_HOME,    ALT_T(KC_END),
        _______,     KC_PLUS,    KC_ASTR,    KC_TILD,   KC_LABK,    KC_RABK,                                   KC_LPRN,    KC_RPRN,    _______,    _______,    _______,    _______,
        _______,     DM_REC1,    DM_REC2,    DM_PLY1,   DM_PLY2,                _______,              _______,             _______,    _______,    _______,    _______,    TG(L_F),
                                                        KC_MPRV,    KC_MPLY,    KC_MNXT,              QK_AREP, TD(T_CP),   C(KC_V)
    ),

    [L_2] = LAYOUT_moonlander(
        RGB_TOG, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD,  RGB_VAI,      KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,
        _______, KC_SLSH, KC_7,    KC_8,    KC_9,    RGB_RMOD, RGB_SPI,      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
        _______, KC_DOT,  KC_4,    KC_5,    KC_6,    RGB_MOD,  RGB_SPD,      _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F5,   ALT_T(KC_F12),
        _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,                          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,   _______,
        _______, _______, _______, _______, _______,         _______,        _______,          _______, _______, _______, _______, _______,
                                   KC_VOLD, KC_MUTE, KC_VOLU,                         _______, _______, _______
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

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_QUOT):
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_QUOT):
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
