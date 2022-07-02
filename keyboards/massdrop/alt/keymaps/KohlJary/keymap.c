#include QMK_KEYBOARD_H
#include <stdbool.h>

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    CDIR,                  //Current directory
    UPDIR,                 //Up a directory
    EQ_NEQ,                //Equal/not equal comparison
    AND_OR,                //And/or operator
    LAMBDA,                //Lambda operator
    BRACES,                //Brace/curly brace
    PARBRA,                //Parentheses/brackets
    SQUOTE,                //Single/double/back quote on one key
    SQUOTEP,               //Single/double/back quote pair on one key
    SLSH_BS,               //Slash/backslash on one key
    MAKE_FL,               //Make/flash keymap
    NEXTSEN,               //Next sentence macro
    NEXTPAR,               //Next paragraph macro
    HOM_END,               //Home/end on one key
    PG_UPDN,               //Page up/down on one key
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        LT(5, KC_GRV),   KC_1,  KC_2,           KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,       KC_EQL,  KC_BSPC,        G(KC_GRV),
        LGUI_T(KC_DEL),  KC_Q,  KC_W,           KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC,       KC_RBRC, LT(5,KC_BSLS),  KC_VOLU,
        RCTL_T(KC_ESC),  KC_A,  KC_S,           KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K,    KC_L,   KC_SCLN, SQUOTE,                 LALT_T(KC_ENT), HOM_END,
        KC_LSFT,         KC_Z,  KC_X,           KC_C, KC_V, KC_B, KC_N,   KC_M, KC_COMM, KC_DOT, SLSH_BS, LT(4,KC_TAB),           KC_UP,          PG_UPDN,
        MO(3),           TG(1), MEH_T(KC_GRV),                    KC_SPC,                        NEXTPAR, NEXTSEN,       KC_LEFT, KC_DOWN,        KC_RGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,    KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,      KC_EQL,  KC_BSPC, TG(2),
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC,      KC_RBRC, KC_BSLS, KC_END,
        KC_LCTL, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,               KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(4,KC_TAB),          KC_PGUP, KC_PGDN,
        KC_GRV,  KC_LGUI, KC_LALT,                   _______,                        KC_HOME, KC_END,       KC_HOME, KC_PGDN, KC_END
    ),
    [3] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, LAMBDA,  AND_OR,  EQ_NEQ,  KC_DEL,  KC_MUTE,
        _______, S(KC_5), S(KC_6), S(KC_7), S(KC_8), KC_DOT,  KC_EQL,   _______, _______, _______, KC_F12,  BRACES,  PARBRA,  _______, KC_WH_U,
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), KC_F11,  KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_F5,   SQUOTEP,          _______, KC_WH_D,
        _______, KC_BSLS, KC_MINS, KC_EQL,  KC_PPLS, _______, _______,  _______, _______, NEXTPAR, NEXTSEN, KC_BTN1,          KC_MS_U, KC_BTN2,
        _______, UPDIR,   CDIR,                               _______,                             DM_PLY1, DM_PLY2, KC_MS_L, KC_MS_D, KC_MS_R
    ),
    [4] = LAYOUT_65_ansi_blocker(
        TG(2),   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21, KC_F22,  KC_F23,  KC_F24,  _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, CDIR,   UPDIR,   _______,          KC_VOLU, _______,
        _______, _______, _______,                            _______,                           _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [5] = LAYOUT(
        _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,  MAKE_FL, DM_REC1,
        RGB_TOG, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_MINS, KC_EQL,  _______, DM_PLY1,
        RGB_M_B, RGB_RMOD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   _______, _______,          MD_BOOT, DM_REC2,
        _______, RGB_MOD,  RGB_VAD, RGB_SPD, RGB_HUD, RGB_SAD, NK_TOGG, DBG_TOG, U_T_AUTO, U_T_AGCR, _______, _______,          KC_PGUP, DM_PLY2,
        _______, _______,  _______,                            _______,                              DM_REC1, DM_REC2, KC_HOME, KC_PGDN, KC_END
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    bool ctrl_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL);
    bool shift_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT);
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
        case CDIR:
            if (record->event.pressed) {
              SEND_STRING("./");
            }
            return false;
        case UPDIR:
            if (record->event.pressed) {
              SEND_STRING("../");
            }
            return false;
        case EQ_NEQ:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (shift_mod) {
                if (ctrl_mod) {
                  SEND_STRING("!==");
                } else {
                  SEND_STRING("!=");
                }
              } else {
                if (ctrl_mod) {
                  SEND_STRING("===");
                } else {
                  SEND_STRING("==");
                }
              }
              set_mods(mod_state);
            }
            return false;
        case AND_OR:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (shift_mod) {
                SEND_STRING("||");
              } else {
                SEND_STRING("&&");
              }
              set_mods(mod_state);
            }
            return false;
        case LAMBDA:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (ctrl_mod) {
                SEND_STRING("() => {}");
              } else if (shift_mod) {
                SEND_STRING("->");
              } else {
                SEND_STRING("=>");
              }
              set_mods(mod_state);
            }
            return false;
        case BRACES:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (shift_mod) {
                SEND_STRING("{}");
              } else {
                SEND_STRING("[]");
              }
              tap_code(KC_LEFT);
              set_mods(mod_state);
            }
            return false;
        case PARBRA:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (shift_mod) {
                SEND_STRING("<>");
              } else {
                SEND_STRING("()");
              }
              tap_code(KC_LEFT);
              set_mods(mod_state);
            }
            return false;
        case SQUOTE:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (ctrl_mod) {
                if (shift_mod) {
                  SEND_STRING("~");
                } else {
                  SEND_STRING("`");
                }
              } else if (shift_mod) {
                SEND_STRING("\"");
              } else {
                SEND_STRING("'");
              }
              set_mods(mod_state);
            }
            return false;
        case SQUOTEP:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (ctrl_mod) {
                SEND_STRING("``");
              } else if (shift_mod) {
                SEND_STRING("\"\"");
              } else {
                SEND_STRING("''");
              }
              tap_code(KC_LEFT);
              set_mods(mod_state);
            }
            return false;
        case SLSH_BS:
            if (record->event.pressed) {
              clear_mods();
              clear_oneshot_mods();
              if (ctrl_mod) {
                if (shift_mod) {
                  SEND_STRING("|");
                } else {
                  SEND_STRING("\\");
                }
              } else {
                if (shift_mod) {
                  SEND_STRING("?");
                } else {
                  SEND_STRING("/");
                }
              }
              set_mods(mod_state);
            }
            return false;
        case MAKE_FL:
            clear_mods();
            clear_oneshot_mods();
            if (record->event.pressed) {
              SEND_STRING(SS_LGUI("`") SS_DELAY(500) SS_LCTL("eu") "qcf");
              key_timer = timer_read32();
              tap_code(KC_ENT);
            } else {
              if (timer_elapsed32(key_timer) >= 500) {
                reset_keyboard();
              }
            }
            set_mods(mod_state);
            return false;
        case NEXTSEN:
            if (record->event.pressed) {
              SEND_STRING(". ");
              add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case NEXTPAR:
            if (record->event.pressed) {
              SEND_STRING(".");
              tap_code(KC_ENT);
              tap_code(KC_ENT);
              add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case HOM_END:
            if (record->event.pressed) {
              del_mods(MOD_MASK_CTRL);
              del_oneshot_mods(MOD_MASK_CTRL);
              if (ctrl_mod) {
                SEND_STRING(SS_TAP(X_HOME));
              } else {
                SEND_STRING(SS_TAP(X_END));
              }
              set_mods(mod_state);
            }
            return false;
        case PG_UPDN:
            if (record->event.pressed) {
              del_mods(MOD_MASK_CTRL);
              del_oneshot_mods(MOD_MASK_CTRL);
              if (ctrl_mod) {
                SEND_STRING(SS_TAP(X_PGUP));
              } else {
                SEND_STRING(SS_TAP(X_PGDN));
              }
              set_mods(mod_state);
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
