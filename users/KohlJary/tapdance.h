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
  T_GQ, //Hold: GUI, 1: USR_QUOT behavior
  T_SL, //Hold: Shift, 1: Leader
  T_AL, //Hold: Alt, 1: Enter, 2: Leader
  T_2L, //Hold: Layer 2, 1: Leader
  T_LS, //Hold: Left Shift, 1: OSM Shift, 2: Open Paren
  T_RS, //Hold: Right Shift, 1: Caps Word, 2: Close Paren
  T_CE, //Hold: Control, 1: Escape, Double Hold: Control+Alt
  T_1T, //Hold: Layer 1, 1: Tab, 2: Shift+Tab
  T_BD, //Hold: Layer 1, Tap || Double Hold: Backspace/Delete
  T_CP, //Hold: Paste, 1: Copy, 2: Cut
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
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

void guiquote_finished(tap_dance_state_t *state, void *user_data);
void guiquote_reset(tap_dance_state_t *state, void *user_data);

void shiftlead_finished(tap_dance_state_t *state, void *user_data);
void shiftlead_reset(tap_dance_state_t *state, void *user_data);

void altlead_finished(tap_dance_state_t *state, void *user_data);
void altlead_reset(tap_dance_state_t *state, void *user_data);

void twolead_finished(tap_dance_state_t *state, void *user_data);
void twolead_reset(tap_dance_state_t *state, void *user_data);

void leftshift_finished(tap_dance_state_t *state, void *user_data);
void leftshift_reset(tap_dance_state_t *state, void *user_data);

void rightshift_finished(tap_dance_state_t *state, void *user_data);
void rightshift_reset(tap_dance_state_t *state, void *user_data);

void ctrlesc_finished(tap_dance_state_t *state, void *user_data);
void ctrlesc_reset(tap_dance_state_t *state, void *user_data);

void onetab_finished(tap_dance_state_t *state, void *user_data);
void onetab_reset(tap_dance_state_t *state, void *user_data);

void bspdel_finished(tap_dance_state_t *state, void *user_data);
void bspdel_reset(tap_dance_state_t *state, void *user_data);

void copypaste_finished(tap_dance_state_t *state, void *user_data);
void copypaste_reset(tap_dance_state_t *state, void *user_data);
