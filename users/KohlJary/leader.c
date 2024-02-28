#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "leader.h"

void leader_end_user(void) {
  //name and contact info
  if(leader_sequence_one_key(KC_F)) {
    SEND_STRING("Kohlbern");
  }
  if(leader_sequence_one_key(KC_L)) {
    SEND_STRING("Jary");
  }
  if(leader_sequence_one_key(KC_M)) {
    SEND_STRING("Charles");
  }
  if(leader_sequence_one_key(KC_N)) {
    SEND_STRING("Kohlbern Charles Jary");
  }
  if(leader_sequence_one_key(KC_B)) {
    SEND_STRING("10/16/1995");
  }
  if(leader_sequence_one_key(KC_P)) {
    SEND_STRING("6782211508");
  }
  if(leader_sequence_one_key(KC_E)) {
    SEND_STRING("kohlbern@gmail.com");
  }
  if(leader_sequence_two_keys(KC_E, KC_E)) {
    SEND_STRING("kohlbern.jary@ubc.com");
  }

  //address info
  if(leader_sequence_one_key(KC_A)) {
    SEND_STRING("9 C Street");
  }
  if(leader_sequence_one_key(KC_C)) {
    SEND_STRING("Portland");
  }
  if(leader_sequence_one_key(KC_Z)) {
    SEND_STRING("04102");
  }
  if(leader_sequence_one_key(KC_S)) {
    SEND_STRING("ME");
  }
  if(leader_sequence_two_keys(KC_C, KC_C)) {
    SEND_STRING("USA");
  }
  if(leader_sequence_two_keys(KC_A, KC_A)) {
    SEND_STRING("9 C Street, Portland ME 04102");
  }
}
