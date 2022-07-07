#include QMK_KEYBOARD_H
#include "tapdance.h"

void dance_sen_par(qk_tap_dance_state_t *state, void *user_data) {
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

void dance_dir(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING("./");
    } else if (state->count == 2) {
      SEND_STRING("../");
    }
    reset_tap_dance(state);
}

void dance_hom_end(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(SS_TAP(X_HOME));
    } else if (state->count == 2) {
      SEND_STRING(SS_TAP(X_END));
    }
    reset_tap_dance(state);
}

void dance_pg_up_dn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
      SEND_STRING(SS_TAP(X_PGUP));
    } else if (state->count == 2) {
      SEND_STRING(SS_TAP(X_PGDN));
    }
    reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
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
};
