#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _SIMBOLS, 
};

enum {
    TD_PARENTESIS_CAPS,
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

/**qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ( twice por {
    [TD_PARENTESIS_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_one, dance_one_reset),
};**/

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ( twice por {
    [TD_PARENTESIS_CAPS] = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_LBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



[_QWERTY] = LAYOUT(
    //----------------------------------                            -------------------------------------
    MT(KC_LSFT, KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5,              KC_6, KC_7, KC_8, KC_9, KC_0, MT(KC_RSFT,KC_BSPC),
    //----------------------------------                            -------------------------------------
    MT(KC_LCTRL,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I, KC_O, KC_P, MT(KC_RCTRL,KC_DEL),
    //----------------------------------                            -------------------------------------
    MT(KC_LALT,ES_SCLN), KC_A, KC_S, KC_D, KC_F, KC_G,                          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_HOME,
    //----------------------------------                            -------------------------------------
    ES_COLN, KC_Z, KC_X, KC_C, KC_V, KC_B,   ES_QUES, ES_EXLM,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_END,
    //----------------------------------                            -------------------------------------
    _______, _______, KC_LGUI, LT(_LOWER, KC_SPC), LT(_SIMBOLS, KC_ENT), LT(_RAISE, ES_ACUT), ES_SLSH, KC_RALT),
 

[_LOWER] = LAYOUT(
    //----------------------------------                            -------------------------------------
    KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______,           ES_ASTR, ES_PIPE, _______, _______, KC_PSCR, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______,           KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______,           ES_BSLS, ES_SLSH, ES_QUOT, ES_GRV, ES_ACUT, _______, _______, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______, _______, _______),
    //----------------------------------                            -------------------------------------
 
[_RAISE] = LAYOUT(
    //----------------------------------                            -------------------------------------
    _______, KC_1, KC_2, KC_3, KC_4, KC_5,                          KC_6, KC_7, KC_8, KC_9, KC_0, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, ES_MINS, ES_PLUS, ES_EQL,            ES_LPRN, ES_RPRN, _______, _______, _______, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, ES_LABK, ES_RABK,           ES_LCBR, ES_RCBR, _______, _______, _______, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______, _______,  ES_SCLN, ES_LBRC, ES_RBRC, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

 
[_SIMBOLS] = LAYOUT(
    //----------------------------------                            -------------------------------------
    _______, ES_PIPE, ES_AT, ES_HASH, ES_DLR, ES_PERC,              ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN, ES_EQL, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______,           ES_ASTR, ES_CIRC, _______, _______, KC_PSCR, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
    //----------------------------------                            -------------------------------------
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    

};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
}
#endif  // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}
