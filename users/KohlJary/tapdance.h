#include QMK_KEYBOARD_H

#pragma once

enum TD_KEYCODES{
  T_CN, //1: scln, 2: cln
  T_DR, //1: cur dir, 2: up dir
  T_IN, //1: --, 2: ++
  T_AQ, //Hold: alt, 1: quote, Double Hold: ctrl+alt, 2: grave
  T_LS, //Hold: Left Shift, Double Hold: Ctrl+Shft, 1: Open par/bra, 2: Close par/bra
  T_RS, //Hold: Right Shift, Double Hold: Ctrl+Shft, 1: Oneshot Shft, 2: Caps Word
  T_CE, //Hold: Control, 1: Escape, Double Hold: Control+Alt
  T_CP, //Hold: Paste, 1: Copy, 2: Cut
  T_BR, //Hold: Paste, 1: Open par/bra, 2: Close par/bra
  T_OB, //Hold: Open curly, Tap: Open paran, Double Tap: Open brace, Double Hold: Open angle brack
  T_CB, //Hold: Closed curly, Tap: Closed paran, Double Tap: Closed brace, Double Hold: Closed angle brack
  T_GE, //Hold: GUI, 1: =, 2:==, Double Hold: !=
  T_UX, //
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

void dance_dir(tap_dance_state_t *state, void *user_data);
void dance_dec_inc(tap_dance_state_t *state, void *user_data);

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

void altquote_finished(tap_dance_state_t *state, void *user_data);
void altquote_reset(tap_dance_state_t *state, void *user_data);

void leftshift_finished(tap_dance_state_t *state, void *user_data);
void leftshift_reset(tap_dance_state_t *state, void *user_data);

void rightshift_finished(tap_dance_state_t *state, void *user_data);
void rightshift_reset(tap_dance_state_t *state, void *user_data);

void ctrlesc_finished(tap_dance_state_t *state, void *user_data);
void ctrlesc_reset(tap_dance_state_t *state, void *user_data);

void copypaste_finished(tap_dance_state_t *state, void *user_data);
void copypaste_reset(tap_dance_state_t *state, void *user_data);

void bracedance_finished(tap_dance_state_t *state, void *user_data);
void bracedance_reset(tap_dance_state_t *state, void *user_data);

void openbrace_finished(tap_dance_state_t *state, void *user_data);
void openbrace_reset(tap_dance_state_t *state, void *user_data);

void closebrace_finished(tap_dance_state_t *state, void *user_data);
void closebrace_reset(tap_dance_state_t *state, void *user_data);

void guieq_finished(tap_dance_state_t *state, void *user_data);
void guieq_reset(tap_dance_state_t *state, void *user_data);

void utility_finished(tap_dance_state_t *state, void *user_data);
void utility_reset(tap_dance_state_t *state, void *user_data);
