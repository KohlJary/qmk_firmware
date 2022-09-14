#include QMK_KEYBOARD_H

void dance_sen_par(qk_tap_dance_state_t *state, void *user_data);
void dance_dir(qk_tap_dance_state_t *state, void *user_data);
void dance_hom_end(qk_tap_dance_state_t *state, void *user_data);
void dance_pg_up_dn(qk_tap_dance_state_t *state, void *user_data);
void dance_cut_copy(qk_tap_dance_state_t *state, void *user_data);

enum TD_KEYCODES{
  T_CN, //1: scln, 2: cln
  T_NS, //1: nxt sen, 2: nxt par
  T_DR, //1: cur dir, 2: up dir
  T_HE, //1: home, 2: end
  T_UD, //1: pgup, 2: pgdn
  T_CC, //1: copy, 2: cut
};

extern enum TD_KEYCODES td_keycodes;
