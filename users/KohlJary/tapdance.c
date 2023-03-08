#include QMK_KEYBOARD_H
#include "tapdance.h"

// Create a global instance of the tapdance state type
static td_state_t td_state = TD_NONE;

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

void dance_sen_par(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(". ");
      add_oneshot_mods(MOD_BIT(KC_LSFT));
    } else if (state->count == 2) {
      SEND_STRING(".");
      SEND_STRING(SS_LSFT(SS_TAP(X_ENT) SS_TAP(X_ENT)));
      add_oneshot_mods(MOD_BIT(KC_LSFT));
    }
    reset_tap_dance(state);
}

void dance_dir(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("./");
    } else if (state->count == 2) {
      SEND_STRING("../");
    } else if (state->count == 3) {
      SEND_STRING("~/");
    }
    reset_tap_dance(state);
}

void dance_hom_end(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(SS_TAP(X_HOME));
    } else if (state->count == 2) {
      SEND_STRING(SS_TAP(X_END));
    }
    reset_tap_dance(state);
}

void dance_pg_up_dn(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(SS_TAP(X_PGUP));
    } else if (state->count == 2) {
      SEND_STRING(SS_TAP(X_PGDN));
    }
    reset_tap_dance(state);
}

void dance_pg_cut_copy(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
      SEND_STRING(SS_LCTL("c"));
  } else if (state->count == 2) {
      SEND_STRING(SS_LCTL("x"));
  }
  reset_tap_dance(state);
}

void dance_eq_neq(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("==");
    } else if (state->count == 2) {
      SEND_STRING("!=");
    }
    reset_tap_dance(state);
}

void dance_dec_inc(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("--");
    } else if (state->count == 2) {
      SEND_STRING("++");
    }
    reset_tap_dance(state);
}

void dance_and_or(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("&&");
    } else if (state->count == 2) {
      SEND_STRING("||");
    }
    reset_tap_dance(state);
}

void guilead_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            leader_start();
            break;
        default:
            break;
    }
}

void guilead_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LGUI)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void shiftlead_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            leader_start();
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            caps_word_toggle();
            break;
        default:
            break;
    }
}

void shiftlead_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void altlead_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            leader_start();
            break;
        default:
            break;
    }
}

void altlead_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
  //Tap once for semicolon, twice for colon
  [T_CN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  //Tap once for next sentence, twice for next paragraph
  [T_NS] = ACTION_TAP_DANCE_FN(dance_sen_par),
  //Tap once for current directory, twice for up a directory
  [T_DR] = ACTION_TAP_DANCE_FN(dance_dir),
  //Tap once for home, twice for end
  [T_HE] = ACTION_TAP_DANCE_FN(dance_hom_end),
  //Tap once for page up, twice for page down
  [T_UD] = ACTION_TAP_DANCE_FN(dance_pg_up_dn),
  //Tap once for copy selection, twice for cut selection
  [T_CC] = ACTION_TAP_DANCE_FN(dance_pg_cut_copy),
  //Tap once for equals, twice for not equals
  [T_EQ] = ACTION_TAP_DANCE_FN(dance_eq_neq),
  //Tap once for decrement, twice for increment
  [T_IN] = ACTION_TAP_DANCE_FN(dance_dec_inc),
  //Tap once for and, twice for or
  [T_AO] = ACTION_TAP_DANCE_FN(dance_and_or),
  //Hold for GUI, tap for leader
  [T_GL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, guilead_finished, guilead_reset),
  //Hold for Shift, tap for leader
  [T_SL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shiftlead_finished, shiftlead_reset),
  //Hold for Alt, tap for leader
  [T_AL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlead_finished, altlead_reset)
};
