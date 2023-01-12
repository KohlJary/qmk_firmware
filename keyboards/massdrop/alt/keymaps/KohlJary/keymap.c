#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
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
        G(KC_GRV),     KC_1,         KC_2,         KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,           KC_0,            A(KC_BSPC), A(KC_DEL), C(KC_BSPC), C(KC_DEL),
        GUI_T(KC_F5),  KC_Q,         KC_W,         KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,           KC_P,            KC_BSPC,    KC_DEL,    C(KC_DEL),  KC_MPLY,
        CTL_T(KC_ESC), KC_A,         KC_S,         KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,           KC_SCLN,         USR_QT,     ALT_T(KC_ENT),         TD(T_HE),
        KC_LSFT,       LT(L_1,KC_Z), LT(L_2,KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, LT(L_2,KC_DOT), LT(L_1,KC_SLSH), RSFT_T(KC_TAB),        CAPSWRD,    KC_UP,
        MO(L_S),       OSM(MOD_MEH), DM_REC1,                  KC_SPC,                                    DM_PLY1,    OSM(MOD_MEH),    KC_LEFT,   KC_RGHT,    KC_DOWN
    ),
    //Japanese input layer
    [L_J] = LAYOUT_65_ansi_blocker(
        JP_ZKHK,       JP_1,    JP_2, JP_3, JP_4, JP_5, JP_6, JP_7, JP_8,    JP_9,   JP_0,    JP_MINS, JP_CIRC, KC_BSPC, JP_YEN,
        GUI_T(KC_F5),  JP_Q,    JP_W, JP_E, JP_R, JP_T, JP_Y, JP_U, JP_I,    JP_O,   JP_P,    JP_LBRC, JP_RBRC, JP_BSLS, JP_AT,
        CTL_T(KC_ESC), JP_A,    JP_S, JP_D, JP_F, JP_G, JP_H, JP_J, JP_K,    JP_L,   JP_SCLN, JP_COLN,    ALT_T(KC_ENT), JP_EISU,
        KC_LSFT,       JP_Z,    JP_X, JP_C, JP_V, JP_B, JP_N, JP_M, JP_COMM, JP_DOT, JP_SLSH, RSFT_T(KC_TAB),   KC_UP,   KC_VOLD,
        MO(L_S),       JP_MHEN, JP_HENK,                _______,                     JP_KANA, TG(L_J), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    //Gaming/compatibility layer (Keys are explicitly declared to ensure compatibility)
    [L_G] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TG(L_G),
        KC_TAB,  KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, TD(T_UD),
        KC_LCTL, KC_A,    KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  TD(T_HE),
        KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,      KC_RSFT,     KC_UP,   KC_VOLD,
        KC_GRV,  KC_LGUI, KC_LALT,                _______,                     TG(L_G), _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    //Modifier layer 1 (macros, symbols, vim-key arrows, keyboard mouse commands)
    [L_1] = LAYOUT_65_ansi_blocker(
        _______, _______,  _______,    _______,  _______,    _______,    _______,  _______, _______, _______,   _______,   _______,    _______, _______, _______,
        _______, S(KC_1),  S(KC_2),    S(KC_3),  S(KC_LBRC), S(KC_RBRC), TD(T_EQ), S(KC_1), KC_EQL,  S(KC_GRV), S(KC_EQL), S(KC_8),    _______, _______, _______,
        _______, S(KC_6),  S(KC_5),    S(KC_4),  S(KC_9),    S(KC_0),    KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,   KC_MINS,   S(KC_MINS),          _______, TD(T_UD),
        _______, S(KC_7),  S(KC_BSLS), TD(T_AO), KC_LBRC,    KC_RBRC,    _______,  _______, _______, KC_BSLS,   TD(T_IN),              _______, KC_MS_U, KC_BTN1,
        _______, TD(T_CC), C(KC_V),                                      _______,                               TG(L_G),   TG(L_J),    KC_MS_L, KC_MS_D, KC_MS_R
    ),
    //Modifier layer 2 (F-keys, numbers, media controls)
    [L_2] = LAYOUT_65_ansi_blocker(
        _______, S(KC_TAB), KC_TAB, KC_SLSH, S(KC_8), KC_F13,    KC_F14,  KC_F15,  KC_F16,  KC_F17, KC_F18,   KC_F19,  KC_F20,  _______, _______,
        _______, S(KC_8),   KC_7,   KC_8,    KC_9,    S(KC_EQL), KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  _______, _______, _______,
        _______, KC_SLSH,   KC_4,   KC_5,    KC_6,    KC_MINS,   KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_F5,    KC_F12,           _______, _______,
        _______, KC_0,      KC_1,   KC_2,    KC_3,    KC_TAB,    KC_F1,   KC_F2,   KC_F3,   KC_F4,  TD(T_DR),          _______, KC_PGUP, KC_VOLD,
        _______, KC_DOT,    KC_EQL,                              _______,                           _______,  _______, KC_HOME, KC_PGDN, KC_END
    ),
    //Settings layer (RGB settings, reflashing commands, debug utilities)
    [L_S] = LAYOUT(
        DBG_TOG,  RGB_RMOD, RGB_MOD,  RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,  RGB_M_B, RGB_TOG, MK_FLSH, DM_REC1,
        U_T_AUTO, _______,  _______,  _______, _______, _______, _______, AND_OR,  EQ_NEQ,  LAMBDA,  _______,  _______, _______, NK_TOGG, DM_PLY1,
        U_T_AGCR, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,          MD_BOOT, DM_REC2,
        TG(L_8),  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, TD(T_DR),          _______, KC_PGUP, DM_PLY2,
        _______,  _______,  _______,                             _______,                            _______,  _______, KC_HOME, KC_PGDN, KC_END
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
