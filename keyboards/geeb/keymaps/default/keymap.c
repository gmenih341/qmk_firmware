#include "kb.h"
#include "macros.c"

enum custom_keycodes {
  M_RGB_MODE = SAFE_RANGE,
  M_RGB_H,
  M_RGB_S,
  M_RGB_V,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,    KC_6,    KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,    KC_Y,    KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC,
		MO(2),   KC_A,    KC_S,    KC_D,   KC_F,  KC_G,    KC_H,    KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT, KC_HASH,  KC_ENT,
		KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,  KC_V,    KC_B,    KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, KC_LSFT,
		KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                          MO(1), KC_DOWN, KC_LEFT, KC_RIGHT),

	KEYMAP(
		RGB_TOG,    KC_TRNS,    KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_VOLD,   KC_VOLU,  KC_DEL,
		M_RGB_MODE, KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,
		KC_TRNS,    KC_TRNS,    M_RGB_S,    KC_TRNS,    KC_TRNS,    KC_TRNS,    M_RGB_H,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    M_RGB_V,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_UP,    KC_HOME,    KC_END),

	KEYMAP(
		KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,  KC_TRNS,   RESET,
		KC_TRNS,    KC_TRNS,    KC_UP,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_VOLD,    KC_VOLU,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPLY,    KC_MPRV,    KC_MNXT),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // MO(1) + Tab = RGB_MOD
  // MO(1) + Shift + Tab = RGB_RMOD
  macro_tab_rgb(M_RGB_MODE == keycode, record);

  // MO(1) + {H,S,V} = Increase {H,S,V}
  // MO(1) + Shift + {H,S,V} = Decrease {H,S,V}
  macro_change_color(M_RGB_H == keycode, record, 10, 0, 0);
  macro_change_color(M_RGB_S == keycode, record, 0, 8, 0);
  macro_change_color(M_RGB_V == keycode, record, 0, 0, 8);

  return true;
}
v
