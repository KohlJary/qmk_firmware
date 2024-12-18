#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "keycodes.h"
#include "tapdance.h"
#include "os_detection.h"
#include "layers.h"

uint8_t mod_state;
uint8_t oneshot_mod_state;

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

static bool user_return;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t key_timer;
  static uint32_t dc_key_timer;
  static uint32_t pa_key_timer;
  static uint32_t ah_key_timer;

  user_return = false;
  mod_state = get_mods();
  oneshot_mod_state = get_oneshot_mods();

  bool shift_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT);
  bool ctrl_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_CTRL);

  switch (keycode) {
    case EQ_NEQ:
      if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("!=");
        } else {
          SEND_STRING("==");
        }
        return false;
      }
      break;
    case LTE_GTE:
      if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("<=");
        } else {
          SEND_STRING(">=");
        }
        return false;
      }
      break;
    case INC_DEC:
      if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("--");
        } else {
          SEND_STRING("++");
        }
        return false;
      }
      break;
    case AND_OR:
      if (record->event.pressed) {
      clear_mods();
      clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("||");
        } else {
          SEND_STRING("&&");
        }
        return false;
      }
      break;
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
    case KC_NULL:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("undefined");
        } else {
          SEND_STRING("null");
        }
        return false;
      }
      break;
    case KC_TRUE:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("false");
        } else {
          SEND_STRING("true");
        }
        return false;
      }
      break;
    case IF_ELSE:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if (ctrl_mod) {
          SEND_STRING("else if () {");
          tap_code(KC_ENT);
          tap_code(KC_ESC);
          SEND_STRING("k$F)i");
        }
        else if (shift_mod) {
          SEND_STRING("else () {");
          tap_code(KC_ENT);
          tap_code(KC_ESC);
          SEND_STRING("k$F)i");
        } else {
          SEND_STRING("if () {");
          tap_code(KC_ENT);
          tap_code(KC_ESC);
          SEND_STRING("k$F)i");
        }
        return false;
      }
      break;
    case FOR_EAC:
      if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        if (shift_mod) {
          SEND_STRING("foreach () {");
          tap_code(KC_ENT);
          tap_code(KC_ESC);
          SEND_STRING("k$F)i");
        } else {
          SEND_STRING("for () {");
          tap_code(KC_ENT);
          tap_code(KC_ESC);
          SEND_STRING("k$F)i");
        }
        return false;
      }
      break;
    case AT_HASH:
      if (record->event.pressed) {
        ah_key_timer = timer_read();
      } else {
        clear_mods();
        clear_oneshot_mods();
        if(timer_elapsed(ah_key_timer) < TAPPING_TERM) {
          SEND_STRING("@");
        } else {
          SEND_STRING("#");
        }
        set_mods(mod_state);
      }
      break;
    case DOL_CIR:
      if (record->event.pressed) {
        dc_key_timer = timer_read();
      } else {
        clear_mods();
        clear_oneshot_mods();
        if(timer_elapsed(dc_key_timer) < TAPPING_TERM) {
          SEND_STRING("$");
        } else {
          SEND_STRING("^");
        }
        set_mods(mod_state);
      }
      break;
    case PER_AST:
      if (record->event.pressed) {
        pa_key_timer = timer_read();
      } else {
        clear_mods();
        clear_oneshot_mods();
        if(timer_elapsed(pa_key_timer) < TAPPING_TERM) {
          SEND_STRING("%");
        } else {
          SEND_STRING("*");
        }
      }
      break;
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
    case UC_STRT:
      if (record->event.pressed) {
        ucis_start();
      }
      return false;
      break;
    case LCA(KC_DEL):
      if (record->event.pressed) {
        if (detected_host_os() == OS_LINUX) {
          add_oneshot_mods(MOD_BIT(KC_LGUI));
          tap_code(KC_ESC);
          return false;
        }
      }
      break;
    case G(KC_SPC):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LGUI));
          tap_code(KC_S);
          return false;
        }
      }
      break;
    case G(KC_DOT):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LGUI));
          add_oneshot_mods(MOD_BIT(KC_LSFT));
          tap_code(KC_3);
          return false;
        }
      }
      break;
    case G(KC_EQL):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_M);
          return false;
        }
      }
      break;
    case G(KC_P):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_P);
          return false;
        }
      }
      break;
    case G(KC_N):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_N);
          return false;
        }
      }
      break;
    case G(KC_H):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_H);
          return false;
        }
      }
      break;
    case G(KC_J):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_J);
          return false;
        }
      }
      break;
    case G(KC_K):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_K);
          return false;
        }
      }
      break;
    case G(KC_L):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_L);
          return false;
        }
      }
      break;
    case G(KC_A):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_A);
          return false;
        }
      }
      break;
    case G(KC_S):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_S);
          return false;
        }
      }
      break;
    case G(KC_D):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_D);
          return false;
        }
      }
      break;
    case G(KC_F):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_F);
          return false;
        }
      }
      break;
    case G(KC_SCLN):
      if (record->event.pressed) {
        if (detected_host_os() == OS_WINDOWS) {
          add_oneshot_mods(MOD_BIT(KC_LALT));
          tap_code(KC_SCLN);
          return false;
        }
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
        case KC_UNDS:
        case TD(T_LS):
        case TD(T_GM):
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case TD(T_LS):
        case TD(T_RS):
        case TD(T_GE):
        case TD(T_CE):
            return false;  // Ignore backspace.
    }

    return true;  // Other keys can be repeated.
}

const key_override_t next_track_override =
    ko_make_with_layers_negmods_and_options(
        MOD_MASK_CTRL,       // Trigger modifiers: ctrl
        KC_MPLY,             // Trigger key: play/pause
        KC_MNXT,             // Replacement key
        ~0,                  // Activate on all layers
        MOD_MASK_SA,         // Do not activate when shift or alt are pressed
        ko_option_no_reregister_trigger); // Specifies that the play key is not registered again after lifting ctrl

const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_MPLY,
                                            KC_MPRV, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

const key_override_t vol_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_MPLY,
                                            KC_VOLU, ~0, MOD_MASK_CS, ko_option_no_reregister_trigger);

const key_override_t vol_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SA, KC_MPLY,
                                            KC_VOLD, ~0, MOD_MASK_CTRL, ko_option_no_reregister_trigger);

const key_override_t mute_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_MPLY,
                                        KC_MUTE, ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger);

const key_override_t vlead_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, QK_LEAD,
                                        KC_F24, ~0, MOD_MASK_CA, ko_option_no_reregister_trigger);

const key_override_t bsp_del_1_override = ko_make_basic(MOD_MASK_SHIFT, LT(LY1,KC_BSPC), KC_DEL);

const key_override_t bsp_del_2_override = ko_make_basic(MOD_MASK_SHIFT, LT(LY2,KC_BSPC), KC_DEL);

const key_override_t bsp_del_no_ly_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t slsh_bsls_override = ko_make_basic(MOD_MASK_CTRL, KC_SLSH, KC_BSLS);

const key_override_t quot_override = ko_make_basic(MOD_MASK_CTRL, KC_QUOT, KC_GRV);

const key_override_t alt_quot_override = ko_make_basic(MOD_MASK_CTRL, TD(T_AQ), KC_GRV);

const key_override_t ly_quot_override = ko_make_basic(MOD_MASK_CTRL, LT(LY1,KC_QUOT), KC_GRV);

const key_override_t at_hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_HASH);
const key_override_t ast_perc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_PERC);

const key_override_t and_or_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PIPE);

const key_override_t tild_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_TILD);

const key_override_t exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);

const key_override_t lprn_labk_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LABK);
const key_override_t rprn_rabk_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RABK);

const key_override_t mins_ampr_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, GUI_T(KC_MINS), KC_AMPR, ~0, MOD_MASK_SHIFT);
const key_override_t unds_pipe_override = ko_make_basic(MOD_MASK_CS, GUI_T(KC_MINS), KC_PIPE);

const key_override_t kp_mins_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_PSLS);
const key_override_t kp_pls_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PAST);
const key_override_t kp_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_PDOT, KC_EQL);
const key_override_t kp_gpls_override = ko_make_basic(MOD_MASK_SHIFT, GUI_T(KC_PPLS), KC_PAST);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &next_track_override,
    &prev_track_override,
    &mute_override,
    &vol_up_override,
    &vol_down_override,
    &vlead_override,
    &bsp_del_1_override,
    &bsp_del_2_override,
    &bsp_del_no_ly_override,
    &slsh_bsls_override,
    &quot_override,
    &alt_quot_override,
    &ly_quot_override,
    &at_hash_override,
    &ast_perc_override,
    &and_or_override,
    &tild_override,
    &exlm_override,
    &lprn_labk_override,
    &rprn_rabk_override,
    &mins_ampr_override,
    &unds_pipe_override,
    &kp_mins_override,
    &kp_pls_override,
    &kp_dot_override,
    &kp_gpls_override,
    NULL
};

const ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("poop", 0x1F4A9),                // 💩
    UCIS_SYM("rofl", 0x1F923),                // 🤣
    UCIS_SYM("cuba", 0x1F1E8, 0x1F1FA),       // 🇨🇺
    UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0), // ಠ_ಠ
    UCIS_SYM("copy", 0x00A9),                 // ©
    UCIS_SYM("reg",  0x00AE)                  // ®
);
