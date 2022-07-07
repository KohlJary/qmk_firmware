#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "keycodes.h"

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

uint8_t mod_state;
uint8_t oneshot_mod_state;
bool process_record_user_keycodes(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    bool ctrl_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL);
    bool shift_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT);
    switch (keycode) {
        case ELPS:
            if (record->event.pressed) {
              SEND_STRING("...");
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
        case USR_QT:
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
        case USR_QTP:
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
        case MK_FLSH:
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
        case INV_1:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("1");
              } else {
                SEND_STRING("!");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_2:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("2");
              } else {
                SEND_STRING("@");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_3:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("3");
              } else {
                SEND_STRING("#");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_4:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("4");
              } else {
                SEND_STRING("$");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_5:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("5");
              } else {
                SEND_STRING("%");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_6:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("6");
              } else {
                SEND_STRING("^");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_7:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("7");
              } else {
                SEND_STRING("&");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_8:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("8");
              } else {
                SEND_STRING("*");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_9:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("9");
              } else {
                SEND_STRING("(");
              }
              set_mods(mod_state);
            }
            return false;
        case INV_0:
            if (record->event.pressed) {
              del_mods(MOD_MASK_SHIFT);
              del_oneshot_mods(MOD_MASK_SHIFT);
              if (shift_mod) {
                SEND_STRING("0");
              } else {
                SEND_STRING(")");
              }
              set_mods(mod_state);
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
