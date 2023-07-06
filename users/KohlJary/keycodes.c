#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "keycodes.h"
#include "tapdance.h"
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
  static uint32_t eq_key_timer;
  static uint32_t lg_key_timer;
  static uint32_t pa_key_timer;
  static uint32_t ao_key_timer;
  static uint32_t ah_key_timer;
  static uint32_t incdec_key_timer;

  user_return = false;
  mod_state = get_mods();
  oneshot_mod_state = get_oneshot_mods();

  bool shift_mod = ((mod_state | oneshot_mod_state) & MOD_MASK_SHIFT);

  switch (keycode) {
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
        lg_key_timer = timer_read();
      } else {
        clear_mods();
        clear_oneshot_mods();
        if(timer_elapsed(lg_key_timer) < TAPPING_TERM) {
          SEND_STRING("<=");
        } else {
          SEND_STRING(">=");
        }
        set_mods(mod_state);
      }
      break;
    case INC_DEC:
      if (record->event.pressed) {
        incdec_key_timer = timer_read();
      } else {
        clear_mods();
        clear_oneshot_mods();
        if(timer_elapsed(incdec_key_timer) > TAPPING_TERM) {
          send_string("--");
        } else {
          send_string("++");
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

const key_override_t bsp_del_override = ko_make_basic(MOD_MASK_SHIFT, LT(L_1,KC_BSPC), KC_DEL);

const key_override_t slsh_bsls_override = ko_make_basic(MOD_MASK_CTRL, KC_SLSH, KC_BSLS);

const key_override_t plus_override = ko_make_basic(MOD_MASK_CTRL, GUI_T(KC_MINS), KC_PLUS);

/* const key_override_t and_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_AMPR); */

/* const key_override_t or_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_PIPE); */

const key_override_t and_or_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PIPE);

const key_override_t and_exlm_override = ko_make_basic(MOD_MASK_CTRL, KC_AMPR, KC_EXLM);

/* const key_override_t and_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_SCLN, */
/*                                             KC_AMPR, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger); */

/* const key_override_t or_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_SCLN, */
/*                                             KC_PIPE, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger); */

const key_override_t tild_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_TILD);

const key_override_t exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);

const key_override_t lprn_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_LBRC,
                                        KC_LPRN, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
const key_override_t labk_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_LBRC,
                                        KC_LABK, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);
const key_override_t rprn_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_RBRC,
                                        KC_RPRN, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);
const key_override_t rabk_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_RBRC,
                                        KC_RABK, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &next_track_override,
    &prev_track_override,
    &vol_up_override,
    &vol_down_override,
    &vlead_override,
    &bsp_del_override,
    &slsh_bsls_override,
    &plus_override,
    &and_or_override,
    &and_exlm_override,
    &tild_override,
    &exlm_override,
    &lprn_override,
    &labk_override,
    &rprn_override,
    &rabk_override,
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
