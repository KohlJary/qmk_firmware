#include QMK_KEYBOARD_H
#include "layers.h"
#include "os_detection.h"
#include "tapdance.h"
#include "keycodes.h"

// Create a global instance of the tapdance state type
static td_state_t td_state = TD_NONE;
static td_state_t ctrlesc_td_state = TD_NONE;
static td_state_t guieq_td_state = TD_NONE;
static td_state_t altqt_td_state = TD_NONE;
static td_state_t ux_td_state = TD_NONE;
static td_state_t mb_td_state = TD_NONE;
static td_state_t sc_td_state = TD_NONE;
static td_state_t lshift_td_state = TD_NONE;
static td_state_t rshift_td_state = TD_NONE;

uint8_t mod_state;
uint8_t oneshot_mod_state;

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) {
      if (!state->pressed) return TD_DOUBLE_TAP;
      else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Determine the tapdance state to return
td_state_t cur_dance_interrupt(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) {
      if (!state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
      else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
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

void dance_dec_inc(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("--");
    } else if (state->count == 2) {
      SEND_STRING("++");
    }
    reset_tap_dance(state);
}

void dance_home_end(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      tap_code(KC_HOME);
    } else if (state->count == 2) {
      tap_code(KC_END);
    }
    reset_tap_dance(state);
}

void dance_layer(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      layer_invert(LYV);
    } else if (state->count == 2) {
      layer_invert(LYF);
    } else if (state->count == 3) {
      layer_invert(LYG);
    }
    reset_tap_dance(state);
}

void altquote_finished(tap_dance_state_t *state, void *user_data) {
    altqt_td_state = cur_dance(state);
    switch (altqt_td_state) {
        case TD_SINGLE_TAP:
            register_code(KC_QUOT);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_F24);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_RSFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void altquote_reset(tap_dance_state_t *state, void *user_data) {
    switch (altqt_td_state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_QUOT);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_F24);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void leftshift_finished(tap_dance_state_t *state, void *user_data) {
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    lshift_td_state = cur_dance(state);
    switch (lshift_td_state) {
        case TD_SINGLE_TAP:
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            if (is_caps_word_on()) {
                caps_word_off();
                clear_oneshot_mods();
            }
            break;
        case TD_DOUBLE_TAP:
            caps_word_toggle();
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            register_mods(MOD_BIT(KC_LCTL));
            break;
        default:
            break;
    }
}

void leftshift_reset(tap_dance_state_t *state, void *user_data) {
    switch (lshift_td_state) {
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void rightshift_finished(tap_dance_state_t *state, void *user_data) {
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    rshift_td_state = cur_dance(state);
    switch (rshift_td_state) {
        case TD_SINGLE_TAP:
            if(IS_LAYER_ON(LYN)) {
                reset_oneshot_layer();
            } else {
                set_oneshot_layer(LYN, ONESHOT_START);
            }
            break;
        case TD_DOUBLE_TAP:
            layer_invert(LYN);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RSFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            register_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void rightshift_reset(tap_dance_state_t *state, void *user_data) {
    switch (rshift_td_state) {
        case TD_SINGLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            unregister_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void ctrlesc_finished(tap_dance_state_t *state, void *user_data) {
    ctrlesc_td_state = cur_dance(state);
    switch (ctrlesc_td_state) {
        case TD_SINGLE_TAP:
            register_code(KC_ESC);
            break;
        case TD_DOUBLE_TAP:
            leader_start();
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void ctrlesc_reset(tap_dance_state_t *state, void *user_data) {
    switch (ctrlesc_td_state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void copypaste_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    bool ly1_on = IS_LAYER_ON(LY1);
    switch (td_state) {
        case TD_SINGLE_TAP:
            if(ly1_on) {
              add_oneshot_mods(MOD_BIT(KC_LGUI));
              tap_code(KC_GRV);
            }
            else {
              SEND_STRING(SS_LCTL("c"));
            }
            break;
        case TD_DOUBLE_TAP:
            if(ly1_on) {
              add_oneshot_mods(MOD_BIT(KC_LCTL));
              tap_code(KC_Z);
            }
            else {
              add_oneshot_mods(MOD_BIT(KC_LCTL));
              tap_code(KC_X);
            }
            break;
        case TD_SINGLE_HOLD:
            if(ly1_on) {
              add_oneshot_mods(MOD_BIT(KC_LGUI));
              tap_code(KC_SPC);
            }
            else {
              add_oneshot_mods(MOD_BIT(KC_LCTL));
              tap_code(KC_V);
            }
            break;
        case TD_DOUBLE_HOLD:
            if(ly1_on) {
              add_oneshot_mods(MOD_BIT(KC_LGUI));
              tap_code(KC_Y);
            }
            else {
              add_oneshot_mods(MOD_BIT(KC_LSFT));
              add_oneshot_mods(MOD_BIT(KC_LGUI));
              tap_code(KC_S);
            }
            break;
        default:
            break;
    }
}

void copypaste_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        default:
            break;
    }
}

void shiftcaps_finished(tap_dance_state_t *state, void *user_data) {
    sc_td_state = cur_dance(state);
    switch (sc_td_state) {
        case TD_SINGLE_TAP:
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_DOUBLE_TAP:
            caps_word_on();
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_HOLD:
            caps_word_off();
            break;
        default:
            break;
    }
}

void shiftcaps_reset(tap_dance_state_t *state, void *user_data) {
    switch (sc_td_state) {
        default:
            break;
    }
}

void openbrace_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            SEND_STRING("{");
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("[");
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING("(");
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING("<");
            break;
        default:
            break;
    }
}

void openbrace_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        default:
            break;
    }
}

void closebrace_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            SEND_STRING("}");
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("]");
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(")");
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(">");
            break;
        default:
            break;
    }
}

void closebrace_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        default:
            break;
    }
}

void guieq_finished(tap_dance_state_t *state, void *user_data) {
    guieq_td_state = cur_dance(state);
    switch (guieq_td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_EQL);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_EQL);
            register_code16(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            if(detected_host_os() == OS_WINDOWS) {
                register_mods(MOD_BIT(KC_LALT));
            } else {
                register_mods(MOD_BIT(KC_LGUI));
            }
            break;
        case TD_DOUBLE_HOLD:
            if(detected_host_os() == OS_WINDOWS) {
                register_mods(MOD_BIT(KC_LALT));
            } else {
                register_mods(MOD_BIT(KC_LGUI));
            }
            register_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

void guieq_reset(tap_dance_state_t *state, void *user_data) {
    switch (guieq_td_state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            unregister_code16(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            if(detected_host_os() == OS_WINDOWS) {
                unregister_mods(MOD_BIT(KC_LALT));
            } else {
                unregister_mods(MOD_BIT(KC_LGUI));
            }
            break;
        case TD_DOUBLE_HOLD:
            if(detected_host_os() == OS_WINDOWS) {
                unregister_mods(MOD_BIT(KC_LALT));
            } else {
                unregister_mods(MOD_BIT(KC_LGUI));
            }
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

void utility_finished(tap_dance_state_t *state, void *user_data) {
    ux_td_state = cur_dance(state);
    bool ly2_on = IS_LAYER_ON(LY2);
    switch (ux_td_state) {
        case TD_SINGLE_TAP:
            if(ly2_on) {
              add_oneshot_mods(MOD_BIT(KC_LGUI));
              tap_code(KC_P);
            }
            else {
              add_oneshot_mods(MOD_BIT(KC_LGUI));
              tap_code(KC_N);
            }
            break;
        case TD_DOUBLE_TAP:
            add_oneshot_mods(MOD_BIT(KC_LGUI));
            tap_code(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
            add_oneshot_mods(MOD_BIT(KC_LCTL));
            tap_code(KC_C);
            break;
        case TD_DOUBLE_HOLD:
            add_oneshot_mods(MOD_BIT(KC_LCTL));
            add_oneshot_mods(MOD_BIT(KC_LALT));
            tap_code(KC_DEL);
            break;
        default:
            break;
    }
}

void utility_reset(tap_dance_state_t *state, void *user_data) {
    switch (ux_td_state) {
        case TD_SINGLE_HOLD:
            tap_code(KC_UP);
            tap_code(KC_ENT);
            break;
        default:
            break;
    }
}

void mouse_button_finished(tap_dance_state_t *state, void *user_data) {
    mb_td_state = cur_dance(state);
    switch (mb_td_state) {
        case TD_SINGLE_TAP:
            tap_code(KC_BTN1);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_BTN2);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_BTN1);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_BTN3);
            break;
        default:
            break;
    }
}

void mouse_button_reset(tap_dance_state_t *state, void *user_data) {
    switch (mb_td_state) {
        case TD_SINGLE_HOLD:
            unregister_code(KC_BTN1);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_BTN3);
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
  //Tap once for semicolon, twice for colon
  [T_CN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  //Tap once for current directory, twice for up a directory
  [T_DR] = ACTION_TAP_DANCE_FN(dance_dir),
  //Tap once for decrement, twice for increment
  [T_IN] = ACTION_TAP_DANCE_FN(dance_dec_inc),
  //Tap once for home, twice for end
  [T_HE] = ACTION_TAP_DANCE_FN(dance_home_end),
  //Hold for Alt, tap for quote, double tap for F24, double hold for Alt+Shift
  [T_AQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altquote_finished, altquote_reset),
  //Hold for shift, single tap for OSM shift, double tap for open paren
  [T_LS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, leftshift_finished, leftshift_reset),
  //Hold for shift, single tap for Caps Word, double tap for close paren
  [T_RS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rightshift_finished, rightshift_reset),
  //Hold for Control, single tap for escape, double tap for QMK leader, double tap and hold for Control+Alt
  [T_CE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrlesc_finished, ctrlesc_reset),
  //Hold for paste, single tap for copy, double tap for cut
  [T_CP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, copypaste_finished, copypaste_reset),
  //single tap for oneshot shift, double tap for caps word
  [T_SC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shiftcaps_finished, shiftcaps_reset),
  //Hold for open curly, single tap for open paren, double tap for open brace, double hold for open angle brack
  [T_OB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, openbrace_finished, openbrace_reset),
  //Hold for close curly, single tap for close paren, double tap for close brace, double hold for close angle brack
  [T_CB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, closebrace_finished, closebrace_reset),
  //Hold for GUI, tap for =, double hold for !=
  [T_GE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, guieq_finished, guieq_reset),
  //Hold for GUI, tap for =, double hold for !=
  [T_UX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, utility_finished, utility_reset),
  //Tap/Hold for M1, double tap for M2, double hold for M3
  [T_MB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mouse_button_finished, mouse_button_reset),
  //1: TG(L_M), 2: TG(L_F), 3: TG(L_G), 4: Ctrl+Alt+Del
  [T_LY] = ACTION_TAP_DANCE_FN(dance_layer),
};

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(T_AQ):
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(T_AQ):
        case TD(T_OB):
        case TD(T_CB):
        case TD(T_CE):
        case TD(T_CP):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}
