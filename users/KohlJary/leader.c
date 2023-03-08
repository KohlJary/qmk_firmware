#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "leader.h"

void leader_end_user(void) {
  //name and contact info
  if(leader_sequence_two_keys(KC_N, KC_F)) {
    SEND_STRING("Kohlbern");
  }
  if(leader_sequence_two_keys(KC_N, KC_L)) {
    SEND_STRING("Jary");
  }
  if(leader_sequence_two_keys(KC_N, KC_M)) {
    SEND_STRING("Charles");
  }
  if(leader_sequence_two_keys(KC_N, KC_P)) {
    SEND_STRING("6782211508");
  }
  if(leader_sequence_two_keys(KC_N, KC_E)) {
    SEND_STRING("kohlbern@gmail.com");
  }
  if(leader_sequence_three_keys(KC_N, KC_E, KC_E)) {
    SEND_STRING("kohlbern.jary@ubc.com");
  }
  if(leader_sequence_two_keys(KC_N, KC_B)) {
    SEND_STRING("10/16/1995");
  }

  //address info
  if(leader_sequence_two_keys(KC_A, KC_A)) {
    SEND_STRING("125 West Ave");
  }
  if(leader_sequence_two_keys(KC_A, KC_C)) {
    SEND_STRING("Brockport");
  }
  if(leader_sequence_two_keys(KC_A, KC_S)) {
    SEND_STRING("NY");
  }
  if(leader_sequence_two_keys(KC_A, KC_O)) {
    SEND_STRING("USA");
  }
  if(leader_sequence_two_keys(KC_A, KC_Z)) {
    SEND_STRING("14420");
  }
  if(leader_sequence_two_keys(KC_A, KC_D)) {
    SEND_STRING("125 West Ave, Brockport NY 14420");
  }
}
