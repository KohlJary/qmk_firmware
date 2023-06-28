#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "keycodes.h"
#include "layers.h"

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

uint8_t mod_state;
uint8_t oneshot_mod_state;
uint8_t bit_state = 0x00;

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static uint8_t bspc_tracker;
static uint8_t del_tracker;
static bool user_return;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t key_timer;
  static uint32_t eq_key_timer;
  static uint32_t ao_key_timer;
  static uint32_t incdec_key_timer;

  user_return = false;
  mod_state = get_mods();
  oneshot_mod_state = get_oneshot_mods();

  bool ctrl_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL);
  bool alt_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_ALT);
  bool shift_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT);

  switch (keycode) {
    case ELPS:
      if (record->event.pressed) {
        SEND_STRING("...");
      }
      break;
    case EQ_NEQ:
      if (record->event.pressed) {
        eq_key_timer = timer_read();
      } else {
        clear_mods();
        clear_oneshot_mods();
        if(timer_elapsed(eq_key_timer) < TAPPING_TERM) {
          SEND_STRING("==");
        } else {
          SEND_STRING("!=");
        }
        set_mods(mod_state);
      }
      break;
    case LTE_GTE:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING(">=");
        } else {
          SEND_STRING("<=");
        }
        set_mods(mod_state);
      }
      return false;
    case INC_DEC:
      if (record->event.pressed) {
        incdec_key_timer = timer_read();
      } else {
        clear_mods();
        clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("-");
          if(timer_elapsed(incdec_key_timer) > TAPPING_TERM) {
            SEND_STRING("-");
          }
        } else {
          SEND_STRING("+");
          if(timer_elapsed(incdec_key_timer) > TAPPING_TERM) {
            SEND_STRING("+");
          }
        }
        set_mods(mod_state);
      }
      break;
    case AND_OR:
      if (record->event.pressed) {
        ao_key_timer = timer_read();
      } else {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        if (shift_mod) {
          SEND_STRING("|");
          if(timer_elapsed(ao_key_timer) > TAPPING_TERM) {
            SEND_STRING("|");
          }
        } else {
          SEND_STRING("&");
          if(timer_elapsed(ao_key_timer) > TAPPING_TERM) {
            SEND_STRING("&");
          }
        }
        set_mods(mod_state);
      }
      return false;
    case LAMBDA:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("->");
        } else {
          SEND_STRING("=>");
        }
        return false;
      }
      break;
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
      break;
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
      break;
    case USR_QT:
      if (record->event.pressed) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        del_mods(MOD_MASK_CTRL);
        del_oneshot_mods(MOD_MASK_CTRL);
        if (ctrl_mod) {
          if (shift_mod) {
            SEND_STRING("~");
          } else {
            SEND_STRING("`");
          }
        } else {
          if (shift_mod) {
            SEND_STRING("\"");
          } else {
            SEND_STRING("'");
          }
        }
        set_mods(mod_state);
      }
      break;
    case CUT_COP:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if (alt_mod) {
          SEND_STRING(SS_LCTL("a"));
        } else if (ctrl_mod) {
          SEND_STRING(SS_LCTL("x"));
        } else if (shift_mod) {
          SEND_STRING(SS_LCTL("v"));
        } else {
          SEND_STRING(SS_LCTL("c"));
        }
        set_mods(mod_state);
      }
      break;
    case SLSH_BS:
      if (record->event.pressed) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        del_mods(MOD_MASK_CTRL);
        del_oneshot_mods(MOD_MASK_CTRL);
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
      break;
    case QUE_EXC:
      if (record->event.pressed) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
          if (shift_mod) {
            SEND_STRING("?");
          } else {
            SEND_STRING("!");
          }
        set_mods(mod_state);
      }
      return false;
    case CLN_DSH:
      if (record->event.pressed) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        del_mods(MOD_MASK_CTRL);
        del_oneshot_mods(MOD_MASK_CTRL);
        if (ctrl_mod) {
          if (shift_mod) {
            SEND_STRING("_");
          } else {
            SEND_STRING("-");
          }
        } else {
          if (shift_mod) {
            SEND_STRING(":");
          } else {
            SEND_STRING(";");
          }
        }
        set_mods(mod_state);
      }
      return false;
    case BSP_DEL:
      if (record->event.pressed) {
        /* bsp_key_timer = timer_read(); */
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        if (shift_mod) {
          register_code(KC_DEL);
          del_tracker++;
        } else {
          register_code(KC_BSPC);
          bspc_tracker++;
        }
        set_mods(mod_state);
      } else {
        if (bspc_tracker) {
          unregister_code(KC_BSPC);
          bspc_tracker--;
        }
        if (del_tracker) {
          unregister_code(KC_DEL);
          del_tracker--;
        }
      }
      return false;
    // Shift+backspace for delete
    case KC_BSPC:
    case LT(L_1,KC_BSPC):
    {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case ALT_T(KC_QUOT):
    {
        static bool grvkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_CTRL) {
                del_mods(MOD_MASK_CTRL);
                register_code(KC_GRV);
                grvkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (grvkey_registered) {
                unregister_code(KC_GRV);
                grvkey_registered = false;
                return false;
            }
        }
        return true;
    }
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
      break;
    case T_RSTRT:
      clear_mods();
      clear_oneshot_mods();
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("c"));
      } else {
        tap_code(KC_UP);
        tap_code(KC_ENT);
      }
      set_mods(mod_state);
      break;
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
      break;
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
      break;
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
      break;
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
      break;
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
      break;
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
      break;
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
      break;
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
      break;
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
      break;
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
      break;
    default:
      if(user_return == true) {
        return false;
      }
      return process_record_keymap(keycode, record);
      break;
  }
  if(user_return == true) {
    return false;
  }
  return process_record_keymap(keycode, record);
}

/* bool process_record_user_bit(uint16_t keycode, keyrecord_t *record) { */
/*   /1* static uint32_t bit_timer[8]; *1/ */
/*   /1* static bool bit_set; *1/ */

/*   switch(keycode) { */
/*     case BIT_0: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 1; */
/*         /1* bit_timer[0] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 1; */
/*         /1* bit_timer[0] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_1: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 2; */
/*         /1* bit_timer[1] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 2; */
/*         /1* bit_timer[1] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_2: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 4; */
/*         /1* bit_timer[2] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 4; */
/*         /1* bit_timer[2] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_3: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 8; */
/*         /1* bit_timer[3] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 8; */
/*         /1* bit_timer[3] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_4: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 16; */
/*         /1* bit_timer[4] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 16; */
/*         /1* bit_timer[4] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_5: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 32; */
/*         /1* bit_timer[5] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 32; */
/*         /1* bit_timer[5] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_6: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 64; */
/*         /1* bit_timer[6] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 64; */
/*         /1* bit_timer[6] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_7: */
/*       if (record->event.pressed) { */
/*         bit_state = bit_state + 128; */
/*         /1* bit_timer[7] = timer_read32(); *1/ */
/*       } */
/*       else { */
/*         bit_state = bit_state - 128; */
/*         /1* bit_timer[7] = 0; *1/ */
/*       } */
/*       break; */
/*     case BIT_ENT: */
/*       tap_code(bit_state); */
/*       tap_code(KC_ENT); */
/*       bit_state = 0x00; */
/*       break; */
/*   } */
/*   return process_record_keymap(keycode, record); */
/* } */

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case BSP_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
