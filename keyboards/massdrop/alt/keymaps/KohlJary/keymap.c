#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "KohlJary.h"

enum alt_keycodes {
    //Massdrop ALT declared keycodes
    U_T_AUTO = NEW_SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR, //USB Toggle Automatic GCR control
    DBG_TOG,  //DEBUG Toggle On / Off
    DBG_MTRX, //DEBUG Toggle Matrix Prints
    DBG_KBD,  //DEBUG Toggle Keyboard Prints
    DBG_MOU,  //DEBUG Toggle Mouse Prints
    MD_BOOT,  //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //Base layer
    [L_B] = LAYOUT_65_ansi_blocker(
        G(KC_GRV),        KC_1,         KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_MINS, KC_EQL,  KC_BSPC,         LT(L_S,KC_GRV),
        GUI_T(KC_DEL),    KC_Q,         KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_LBRC, KC_RBRC, LT(L_S,KC_BSLS), KC_VOLD,
        CTL_T(KC_ESC),    KC_A,         KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   TD(T_CN), USR_QT,      ALT_T(KC_ENT),        TD(T_HE),
        KC_LSFT,          LT(L_1,KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, SLSH_BS,  LT(L_2,KC_TAB),       KC_UP,       TD(T_UD),
        MO(L_2), MO(L_1), TD(T_CC),                           KC_SPC,                       C(KC_V),  MO(L_1),     KC_LEFT, KC_DOWN,     KC_RGHT
    ),
    //Inverted number row layer
    [L_I] = LAYOUT_65_ansi_blocker(
        _______, INV_1,   INV_2,   INV_3,   INV_4,   INV_5,   INV_6,   INV_7,   INV_8,   INV_9,   INV_0,   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    //Gaming/compatibility layer (Keys are explicitly declared to ensure compatibility)
    [L_G] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TG(L_G),
        KC_TAB,  KC_1,    KC_Q, KC_W, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_VOLD,
        KC_LCTL, KC_E,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  TD(T_HE),
        KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,   LT(L_2,KC_GRV), KC_UP,   TD(T_UD),
        KC_GRV,  KC_LGUI, KC_LALT,                _______,                     MO(L_S), TG(L_I), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    //Modifier layer 1 (macros, vim-key arrows, keyboard mouse commands)
    [L_1] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______,    _______,    _______, _______,  _______, _______, _______, LAMBDA,  AND_OR,  EQ_NEQ,  KC_DEL,     KC_MUTE,
        _______, _______, _______, S(KC_LBRC), S(KC_RBRC), KC_DOT,  KC_EQL,   KC_F5,   KC_F10,  KC_F11,  KC_F12,  BRACES,  PARBRA,  TG(L_I),    KC_WH_U,
        _______, S(KC_6), S(KC_4), S(KC_9),    S(KC_0),    _______, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_MINS, KC_EQL,           G(KC_QUOT), KC_WH_D,
        _______, _______, _______, KC_LBRC,    KC_RBRC,    _______, _______,  _______, ELPS,    _______, KC_BSLS,          KC_BTN1, KC_MS_U,    KC_BTN2,
        _______, DM_PLY1, DM_PLY2,                                  _______,                             _______, _______, KC_MS_L, KC_MS_D,    KC_MS_R
    ),
    //Modifier layer 2 (F-keys, number home row, media controls)
    [L_2] = LAYOUT_65_ansi_blocker(
        TG(L_G), KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,   KC_F22,   KC_F23,  KC_F24,  _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_EQL,           _______, _______,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, TD(T_NS), TD(T_DR),          _______, KC_VOLU, _______,
        _______, _______, _______,                            _______,                             _______,  _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    //Settings layer (RGB settings, reflashing commands, debug utilities)
    [L_S] = LAYOUT(
        _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,  MK_FLSH, DM_REC1,
        RGB_TOG, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS, KC_EQL,  NK_TOGG, DM_PLY1,
        RGB_M_B, RGB_RMOD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   _______, _______,          MD_BOOT, DM_REC2,
        TG(L_8), RGB_MOD,  RGB_VAD, RGB_SPD, RGB_HUD, RGB_SAD, NK_TOGG, DBG_TOG, U_T_AUTO, U_T_AGCR, _______,          _______, KC_PGUP, DM_PLY2,
        _______, _______,  _______,                            _______,                              DM_REC1, DM_REC2, KC_HOME, KC_PGDN, KC_END
    ),
    [L_8] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, BIT_7,   BIT_7,   BIT_7,   BIT_7,   _______, _______, BIT_7,   BIT_7,   BIT_7,   BIT_7,   BIT_7,            _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            BIT_ENT,                            _______, _______, _______, _______, _______
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

uint8_t mod_state;
uint8_t oneshot_mod_state;
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
