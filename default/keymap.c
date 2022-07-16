#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER, 
    _RAISE, 
    _ADJUST,
};

enum {
    //TD_PARENTESIS_CAPS,
    TD_QUOTES,
    TD_TILDE,
    TD_SLASH,
    TD_COLONS,
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
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    KC_ESC , KC_1, KC_2, KC_3, KC_4, KC_5,                                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    //----------------------------------                                         -------------------------------------
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I, KC_O, KC_P, MT(KC_RCTRL,KC_DEL),
    //----------------------------------                                         -------------------------------------
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, MT(KC_RALT,KC_HOME),
    //----------------------------------                                         -------------------------------------
    KC_LCTRL, KC_Z, KC_X, KC_C, KC_V, KC_B,                ES_QUES, ES_EXLM,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT(KC_RSFT,KC_END),
    //----------------------------------                            -------------------------------------
                KC_LALT, _______, KC_LGUI, LT(_RAISE, KC_SPC), LT(_LOWER, KC_ENT), TD(TD_TILDE), TD(TD_QUOTES), KC_RALT),



[_LOWER] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12,
    //----------------------------------                                         -------------------------------------
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, KC_PSCR, _______,
    //----------------------------------                                         -------------------------------------
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    //----------------------------------                                         -------------------------------------
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, _______,
    //----------------------------------                                         -------------------------------------
    _______, _______, _______, _______, _______, _______, _______, _______),
    //----------------------------------                                         -------------------------------------

[_RAISE] = LAYOUT(
    //----------------------------------                                         -------------------------------------
    _______, ES_PIPE, ES_AT, ES_HASH, ES_DLR, ES_PERC,                           ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN, ES_EQL, _______,
    //----------------------------------                                         -------------------------------------
    _______, _______, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK,                        ES_ASTR, ES_TILD, ES_CIRC, _______, KC_PSCR, _______,
    //----------------------------------                                         -------------------------------------
    _______, _______, ES_LCBR, ES_RCBR, ES_MINS, ES_PLUS,                        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
    //----------------------------------                                         -------------------------------------
    _______, _______, ES_LBRC, ES_RBRC, _______, _______,   _______,  _______,    _______,  ES_BSLS, ES_SCLN, ES_COLN , ES_UNDS, _______,
    //----------------------------------                                         -------------------------------------
                                       _______, _______, _______, _______, _______, _______, _______, _______),


  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
  

    

};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST ); }



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}
