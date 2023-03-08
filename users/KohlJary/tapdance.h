#include QMK_KEYBOARD_H

enum TD_KEYCODES{
  T_CN, //1: scln, 2: cln
  T_NS, //1: nxt sen, 2: nxt par
  T_DR, //1: cur dir, 2: up dir
  T_HE, //1: home, 2: end
  T_UD, //1: pgup, 2: pgdn
  T_CC, //1: copy, 2: cut
  T_EQ, //1: ==, 2: !=
  T_IN, //1: --, 2: ++
  T_AO, //1: &&, 2: ||
  T_GL, //Hold: GUI, 1: Leader
  T_SL, //Hold: Shift, 1: Leader
  T_AL, //Hold: Alt, 1: Enter, 2: Leader
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

extern enum TD_KEYCODES td_keycodes;

void dance_sen_par(tap_dance_state_t *state, void *user_data);
void dance_dir(tap_dance_state_t *state, void *user_data);
void dance_hom_end(tap_dance_state_t *state, void *user_data);
void dance_pg_up_dn(tap_dance_state_t *state, void *user_data);
void dance_cut_copy(tap_dance_state_t *state, void *user_data);
void dance_eq_neq(tap_dance_state_t *state, void *user_data);
void dance_dec_inc(tap_dance_state_t *state, void *user_data);
void dance_and_or(tap_dance_state_t *state, void *user_data);

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

void guilead_finished(tap_dance_state_t *state, void *user_data);
void guilead_reset(tap_dance_state_t *state, void *user_data);

void shiftlead_finished(tap_dance_state_t *state, void *user_data);
void shiftlead_reset(tap_dance_state_t *state, void *user_data);

void altlead_finished(tap_dance_state_t *state, void *user_data);
void altlead_reset(tap_dance_state_t *state, void *user_data);
