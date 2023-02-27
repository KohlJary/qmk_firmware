#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "leader.h"

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    //name and contact info
    SEQ_TWO_KEYS(KC_N, KC_F) {
      SEND_STRING("Kohlbern");
    }
    SEQ_TWO_KEYS(KC_N, KC_L) {
      SEND_STRING("Jary");
    }
    SEQ_TWO_KEYS(KC_N, KC_M) {
      SEND_STRING("Charles");
    }
    SEQ_TWO_KEYS(KC_N, KC_P) {
      SEND_STRING("6782211508");
    }
    SEQ_TWO_KEYS(KC_N, KC_E) {
      SEND_STRING("kohlbern@gmail.com");
    }
    SEQ_THREE_KEYS(KC_N, KC_E, KC_E) {
      SEND_STRING("kohlbern.jary@ubc.com");
    }
    SEQ_TWO_KEYS(KC_N, KC_B) {
      SEND_STRING("10/16/1995");
    }

    //address info
    SEQ_TWO_KEYS(KC_A, KC_A) {
      SEND_STRING("125 West Ave");
    }
    SEQ_TWO_KEYS(KC_A, KC_C) {
      SEND_STRING("Brockport");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      SEND_STRING("NY");
    }
    SEQ_TWO_KEYS(KC_A, KC_O) {
      SEND_STRING("USA");
    }
    SEQ_TWO_KEYS(KC_A, KC_Z) {
      SEND_STRING("14420");
    }
    SEQ_TWO_KEYS(KC_A, KC_D) {
      SEND_STRING("125 West Ave, Brockport NY 14420");
    }
  }
}
