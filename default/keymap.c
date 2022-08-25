#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER, 
    _RAISE, 
    _TILDE,
    _NUMBER,
    _FUNCTION,
    _ADJUST,
};

enum {
    //TD_PARENTESIS_CAPS,
    TD_QUOTES,
    TD_TILDE,
    TD_SLASH,
    TD_COLONS,
    TD_QUESTION,
    TD_EXCLAMATION
};


void dance_one(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1)
        register_code16(ES_LPRN);
    else
        register_code16(ES_LBRC);
}

void dance_one_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1)
        unregister_code16(ES_LPRN);
    else
        unregister_code16(ES_LBRC);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for " twice por '
    [TD_QUOTES] = ACTION_TAP_DANCE_DOUBLE(ES_QUOT, ES_DQUO),
    // Tap once for ' twice por `
    [TD_TILDE] = ACTION_TAP_DANCE_DOUBLE(ES_ACUT, ES_GRV),
    [TD_SLASH] = ACTION_TAP_DANCE_DOUBLE(ES_SLSH, ES_BSLS),
    [TD_COLONS] = ACTION_TAP_DANCE_DOUBLE(ES_SCLN, ES_COLN),
    [TD_QUESTION] = ACTION_TAP_DANCE_DOUBLE(RSFT(ES_QUES), ES_IQUE),
    [TD_EXCLAMATION] = ACTION_TAP_DANCE_DOUBLE(RSFT(ES_EXLM), ES_IEXL),
};

#define KC_CAPW LGUI(LSFT(KC_3)) // Capture whole screen 
#define KC_CPYW LGUI(LSFT(LCTL(KC_3))) // Copy whole screen 
#define KC_CAPP LGUI(LSFT(KC_4)) // Capture portion of screen 
#define KC_CPYP LGUI(LSFT(LCTL(KC_4))) // Copy portion of screen

#define RALT_TD_TILDE RALT(TD(TD_TILDE)) //tab for tilde, double tab for ` 
#define TD_QUES TD(TD_QUESTION)// tab for ? double tab for ¿
#define TD_EXCL TD(TD_EXCLAMATION) //tab for ! double tab for ¡


#define TTTTTTT KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                  TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    //----------------------------------                                         -------------------------------------  
    KC_TAB, KC_A, KC_S, KC_D, LT(_TILDE, KC_F), KC_G,                      KC_H, KC_J, KC_K, KC_L, ES_COLN, KC_DEL,
    //----------------------------------                                         -------------------------------------
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,          ES_COLN, ES_EQL,      LT(_NUMBER, KC_N), KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL,
    //----------------------------------                            -------------------------------------
               KC_LSFT, KC_LALT, KC_LGUI , LT(_RAISE, KC_SPC), LT(_LOWER, KC_ENT),KC_RGUI, KC_RALT, KC_RSFT),



[_NUMBER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                        TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT,  KC_1, KC_2, KC_3, KC_4, KC_5,                                      TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, KC_PSCR, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT,  KC_6, KC_7, KC_8, KC_9, KC_0,                                      TTTTTTT, TTTTTTT,  TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, ES_PLUS, ES_MINS, ES_ASTR, ES_SLSH, ES_EQL,                        TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT),
    //----------------------------------                                         -------------------------------------

[_LOWER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                         TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, ES_HASH, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK,                        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, ES_AMPR, ES_LCBR, ES_RCBR, ES_SLSH, ES_BSLS,                        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, ES_AT, ES_LBRC, ES_RBRC, ES_ASTR, ES_EQL,     TTTTTTT,  TTTTTTT,    KC_F11, KC_F12, KC_CAPP, KC_CPYP, TTTTTTT,TTTTTTT,
    //----------------------------------                                         -------------------------------------
                                       TTTTTTT, TTTTTTT, ES_PIPE, ES_PERC, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT),

[_RAISE] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                        TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                        KC_PGDN, KC_PGUP, KC_HOME, KC_END,  TTTTTTT,TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT,LGUI(KC_R), LGUI(KC_O), LGUI(KC_F9), KC_CAPS,               KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INS, TTTTTTT,
    //----------------------------------                                         -------------------------------------
    TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,   TTTTTTT,  TTTTTTT,   TTTTTTT,  KC_RSFT, ES_SCLN, ES_COLN, LCTL_T(ES_UNDS), TTTTTTT,
    //----------------------------------                                         -------------------------------------
                                       TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT),


  [_TILDE] = LAYOUT(
  TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                   TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,
  TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                   ES_CIRC, ES_TILD, ES_DIAE, ES_IQUE, ES_QUES, TTTTTTT,
  TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,                   ES_GRV, ES_ACUT , ES_QUOT, ES_DQUO, TTTTTTT, TTTTTTT,
  TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, KC_SCLN, ES_IEXL, ES_EXLM, TTTTTTT, TTTTTTT,TTTTTTT,
                             TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT, TTTTTTT,  TTTTTTT, TTTTTTT, TTTTTTT
  ),



  

};
 

