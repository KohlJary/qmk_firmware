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

#define KJ_SPC  LT(LY2,KC_SPC)
#define KJ_TAB  LT(LY1,KC_TAB)
#define KJ_ENT  LT(LY2,KC_ENT)
#define KJ_BSPC LT(LY1,KC_BSPC)
#define KJ_MINS GUI_T(KC_MINS)

// Vim binds
#define VIM_TOP S(KC_H)
#define VIM_MID S(KC_M)
#define VIM_BOT S(KC_L)

#define MOD_AS  MOD_LALT | MOD_LSFT
#define MOD_CS  MOD_LCTL | MOD_LSFT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LYB] = LAYOUT_moonlander(
        TD(T_CP),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_CIRC,          KC_DLR,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    TD(T_UX),
        TD(T_GE),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_AT,            KC_AMPR,  KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KJ_MINS,
        TD(T_CE),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_LBRC,          KC_RBRC,  KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, TD(T_AQ),
        TD(T_LS),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(T_RS),
        OSM(MOD_CS), KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,         KC_BTN1,          KC_BTN2,          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  OSM(MOD_AS),
                                                KJ_SPC,  KJ_TAB, QK_LEAD,          TD(T_NM), KJ_ENT, KJ_BSPC
    ),

    [LYG] = LAYOUT_moonlander(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, _______, _______, _______, _______, KC_Y,             _______, _______, _______, _______, _______, _______, _______,
        KC_SCLN, _______, _______, _______, _______, _______, KC_H,             _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_7,    KC_8,    KC_9,    KC_0,             KC_GRV,           _______,          _______, _______, _______, _______, _______,
                                            KC_SPC,  KC_BSPC, KC_EQL,           _______, _______, _______
    ),

    [LYN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PPLS, KC_7,    KC_8,    KC_9,    KC_0,    _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PSLS, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, KC_DOT,  KC_1,    KC_2,    KC_3,    KC_EQL,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    [LYV] = LAYOUT_moonlander(
        _______, KC_PROG, KC_WSPR, KC_WSBF, KC_WSNX, KC_TERM, _______,          _______, KC_WBAK, KC_WBTP, KC_OPTB, KC_WBTN, KC_WFWD, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    [LYF] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    [LYN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PPLS, KC_7,    KC_8,    KC_9,    KC_0,    _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PSLS, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, KC_DOT,  KC_1,    KC_2,    KC_3,    KC_EQL,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    [LY1] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,  _______,  QK_BOOT,
        _______, KC_PROG, KC_WSPR, KC_WSBF, KC_WSNX, KC_TERM, _______,          _______, KC_WBAK, KC_WBTP, KC_OPTB, KC_WBTN,  KC_WFWD,  _______,
        _______, KC_CIRC, EQ_NEQ,  LTE_GTE, INC_DEC, AND_OR,  KC_LABK,          KC_RABK, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_DLR,   _______,
        _______, KC_PERC, _______, _______, _______, LAMBDA,                             KC_NULL, VIM_TOP, VIM_MID, VIM_BOT,  KC_ASTR,  _______,
        _______, _______, _______, _______, _______,          _______,          _______,          _______, _______, _______,  _______,  _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    [LY2] = LAYOUT_moonlander(
        QK_BOOT, _______, _______, _______,  _______, _______, _______,         _______, KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  _______,
        _______, DM_REC2, DM_REC1, RGB_HUI,  RGB_SAI, RGB_VAI, _______,         KC_F17,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
        _______, DM_PLY2, DM_PLY1, RGB_RMOD, RGB_TOG, RGB_MOD, KC_LPRN,         KC_RPRN, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F5,   ALT_T(KC_F12),
        _______, RGB_SPD, RGB_SPI, RGB_HUD,  RGB_SAD, RGB_VAD,                           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F6,   _______,
        _______, _______, _______, _______,  _______,          _______,         _______,          KC_WBTP, KC_WBAK, KC_WFWD, KC_WBTN, _______,
                                             _______, _______, _______,         _______, _______, _______
    ),

    [LY3] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),
};

void keyboard_post_init_user(void) {
    layer_on(LYV);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t mod_state = get_mods();
    uint8_t oneshot_mod_state = get_oneshot_mods();
    bool shift_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT);
    bool ctl_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL);
    bool alt_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_ALT);
    bool gui_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_GUI);

    bool layersOn[6] = {
        layer_state_is(LYF),
        layer_state_is(LYV),
        layer_state_is(LYG),
        layer_state_is(LYN),
        layer_state_is(LY1),
        layer_state_is(LY2)
    };
    uint8_t rainbow[7][3] = {
        {RGB_RED},
        {RGB_ORANGE},
        {RGB_YELLOW},
        {RGB_GREEN},
        {RGB_BLUE},
        {RGB_PURPLE},
        {RGB_WHITE}
    };
    uint8_t modColor = (layersOn[0] == true) ? 0 : (layersOn[1] == true) ? 5 : 7;
    uint8_t alphaColor = (layersOn[2] == true) ? 0 : (layersOn[4] == true) ? 4 : (layersOn[5] == true) ? 2 : 7;

    for (uint8_t i = led_min; i < led_max; i++) {
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
            rgb_matrix_set_color(i, 0, 0, 0);
            continue;
        }

        if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
            if (modColor != 7) {
                rgb_matrix_set_color(i, rainbow[modColor][0], rainbow[modColor][1], rainbow[modColor][2]);
                continue;
            }
            continue;
        }

        if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
            if (alphaColor != 7) {
                rgb_matrix_set_color(i, rainbow[alphaColor][0], rainbow[alphaColor][1], rainbow[alphaColor][2]);
                continue;
            }
            continue;
        }

        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            if (alt_mod && ctl_mod && gui_mod) {
                rgb_matrix_set_color(i, RGB_WHITE);
                continue;
            } else if (alt_mod && ctl_mod) {
                rgb_matrix_set_color(i, RGB_GREEN);
                continue;
            } else if (alt_mod && gui_mod) {
                rgb_matrix_set_color(i, RGB_PURPLE);
                continue;
            } else if (ctl_mod && gui_mod) {
                rgb_matrix_set_color(i, RGB_ORANGE);
                continue;
            } else if (alt_mod) {
                rgb_matrix_set_color(i, RGB_BLUE);
                continue;
            } else if (ctl_mod) {
                rgb_matrix_set_color(i, RGB_YELLOW);
                continue;
            } else if (gui_mod) {
                rgb_matrix_set_color(i, RGB_RED);
                continue;
            }
            continue;
        }

        if (g_led_config.flags[i] & LED_FLAG_INDICATOR) {
            if (is_caps_word_on()) {
                rgb_matrix_set_color(i, RGB_RED);
                continue;
            } else if (shift_mod) {
                rgb_matrix_set_color(i, RGB_ORANGE);
                continue;
            } else if (leader_sequence_active()) {
                rgb_matrix_set_color(i, RGB_PURPLE);
                continue;
            } else if (layersOn[3]) {
                rgb_matrix_set_color(i, RGB_GREEN);
                continue;
            }
            continue;
        }
    }
    return false;
}

void housekeeping_task_user(void) {
    if (!is_transport_connected()) {
        layer_on(LYG);
        layer_off(LYV);
    } else {
        layer_off(LYG);
    }
}
