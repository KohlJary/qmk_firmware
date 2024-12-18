#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "os_detection.h"
#include "leader.h"

void leader_end_user(void) {
  //name and contact info
  if(leader_sequence_one_key(KC_N)) {
    SEND_STRING("Kohlbern");
  }
  if(leader_sequence_two_keys(KC_N, KC_N)) {
    SEND_STRING("Jary");
  }
  if(leader_sequence_three_keys(KC_N, KC_N, KC_N)) {
    SEND_STRING("Kohlbern Charles Jary");
  }
  if(leader_sequence_four_keys(KC_N, KC_N, KC_N, KC_N)) {
    SEND_STRING("Charles");
  }
  if(leader_sequence_one_key(KC_B)) {
    SEND_STRING("10/16/1995");
  }
  if(leader_sequence_one_key(KC_P)) {
    SEND_STRING("6782211508");
  }
  if(leader_sequence_one_key(KC_E)) {
    if(detected_host_os() == OS_WINDOWS) {
        SEND_STRING("kohlbern.jary@ubc.com");
    }
    else {
        SEND_STRING("kohlbern@gmail.com");
    }
  }
  if(leader_sequence_two_keys(KC_E, KC_E)) {
    if(detected_host_os() == OS_WINDOWS) {
        SEND_STRING("kohlbern@gmail.com");
    }
    else {
        SEND_STRING("kohlbern.jary@ubc.com");
    }
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
  if(leader_sequence_one_key(KC_U)) {
    SEND_STRING("USA");
  }
  if(leader_sequence_one_key(KC_D)) {
    SEND_STRING("9 C Street, Portland ME 04102");
  }

  if(leader_sequence_one_key(KC_L)) {
    SEND_STRING("localhost:");
  }

  //test npi number
  if(leader_sequence_one_key(KC_I)) {
    SEND_STRING("1043870686");
  }
}
