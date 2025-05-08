#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "os_detection.h"
#include "leader.h"

void send_email(bool isWork) {
  SEND_STRING("kohlbern");
  if(isWork) {
    tap_code(KC_DOT);
    SEND_STRING("jary");
  }
  tap_code16(KC_AT);
  if(isWork) {
    SEND_STRING("ubc");
  }
  else {
    SEND_STRING("gmail");
  }
  tap_code(KC_DOT);
  SEND_STRING("com");
}

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
        send_email(true);
    }
    else {
        send_email(false);
    }
  }
  if(leader_sequence_two_keys(KC_E, KC_E)) {
    if(detected_host_os() == OS_WINDOWS) {
        send_email(false);
    }
    else {
        send_email(true);
    }
  }

  //address info
  if(leader_sequence_one_key(KC_A)) {
    SEND_STRING("975 Dorchester Ave");
  }
    if(leader_sequence_one_key(KC_U)) {
        SEND_STRING("#3");
    }
  if(leader_sequence_one_key(KC_C)) {
    SEND_STRING("Dorchester");
  }
  if(leader_sequence_one_key(KC_S)) {
    SEND_STRING("MA");
  }
    if(leader_sequence_one_key(KC_Z)) {
        SEND_STRING("02125");
    }
    if(leader_sequence_one_key(KC_D)) {
        SEND_STRING("975 Dorchester Ave, Dorchester MA 02125");
    }

  if(leader_sequence_one_key(KC_L)) {
    SEND_STRING("localhost:");
  }

    //Git quick feature branch stub
    if(leader_sequence_one_key(KC_G))
    {
        SEND_STRING("feature/kj/");
    }

  //test npi number
  if(leader_sequence_one_key(KC_I)) {
    SEND_STRING("1043870686");
  }
}
