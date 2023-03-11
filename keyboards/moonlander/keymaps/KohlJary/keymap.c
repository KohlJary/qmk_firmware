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
 * TD(T_EQ): Single tap; ==, Double tap; !=
 * TD(T_IN): Single tap; ++, Double tap; --
 * TD(T_AO): Single tap; &&, Double tap; ||
 *
 * EQ_NEQ: ==, shifted for !=
 * LTE_GTE: <=, shifted for >=
 * LAMBDA: =>, shifted for ->
 * AND_OR: &, shifted for |
 * SLSH_BS: /, ctrl for \
 * USR_QT: hold for alt, tap for ', ctrl tap for `
 * BSP_DEL: backspace, shifted for delete
 *
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_B] = LAYOUT_moonlander(
        G(KC_GRV),      KC_1,    KC_2,    KC_3,    KC_4,    KC_5, LTE_GTE,        TD(T_IN),   KC_6, KC_7,    KC_8,    KC_9,   KC_0,    G(KC_EQL),
        GUI_T(KC_EQL),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, TD(T_EQ),       TD(T_AO),   KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    GUI_T(KC_MINS),
        CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, LAMBDA,         AND_OR,     KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, USR_QT,
        TD(T_LS),       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N, KC_M,    KC_COMM, KC_DOT, SLSH_BS, TD(T_RS),
        ALT_T(KC_HOME), DM_REC1, DM_REC2, DM_PLY1, DM_PLY2,       G(KC_SPC),      G(KC_ENT),        KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, CTL_T(KC_END),
                                          KC_SPC, LT(L_1,KC_TAB), TD(T_2L),       LT(L_1,KC_F5), LT(L_2, KC_ENT), BSP_DEL
    ),

    [L_G] = LAYOUT_moonlander(
        KC_ESC,  _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, KC_Y,              _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, KC_H,              _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_6,    KC_7,    KC_8,    KC_9,             KC_ESC,            _______,          _______, _______, _______, _______, _______,
                                            _______, KC_BSPC, KC_GRV,            _______, _______, _______
    ),

    [L_F] = LAYOUT_moonlander(
        _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_P),           G(KC_N), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [L_1] = LAYOUT_moonlander(
        TG(L_F), G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), TG(L_G),           TG(L_F), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), QK_BOOT,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_LABK, KC_RABK, KC_PLUS,           KC_WH_U, LAMBDA,  TD(T_EQ),TD(T_IN),TD(T_AO),_______, _______,
        _______, KC_CIRC, KC_PERC, KC_DLR,  KC_LCBR, KC_RCBR, KC_MINS,           KC_WH_D, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
        _______, AND_OR,  KC_ASTR, KC_TILD, KC_LBRC, KC_RBRC,                             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, KC_MS_BTN2, KC_MS_BTN1
    ),

    [L_2] = LAYOUT_moonlander(
        RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,  RGB_VAD, RGB_VAI, LCA(KC_DEL),       A(KC_F4),RGB_SPD, RGB_SPI, RGB_RMOD,RGB_MOD, RGB_TOG, QK_BOOT,
        _______,  KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        KC_VOLU,  KC_DOT,  KC_4,    KC_5,    KC_6,    KC_SLSH, _______,           _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F5,   KC_F12, 
        KC_VOLD,  KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,                              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F11,  _______,
        KC_MUTE,  KC_MPRV, KC_MPLY, KC_MNXT, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                   _______, _______, _______,                              _______, _______, _______
    ),
};
