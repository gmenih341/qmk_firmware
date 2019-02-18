#include "kb.h"
#include "rgblight.h"

void macro_tab_rgb (bool key_pressed, keyrecord_t *record) {
  if (!key_pressed) {
    return;
  }
  uint8_t shift_pressed = keyboard_report->mods & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
  if (record->event.pressed) {
    if (shift_pressed == 0) {
      rgblight_mode((rgblight_get_mode() + 1) % RGBLIGHT_MODES);
    } else {
      rgblight_mode((rgblight_get_mode() + RGBLIGHT_MODES - 1) % RGBLIGHT_MODES);
    }
  }
}

void macro_change_color (bool key_pressed, keyrecord_t *record, int16_t h, int16_t s, int16_t v) {
  if (!key_pressed) {
    return;
  }
  uint8_t shift_pressed = keyboard_report->mods & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
  int8_t shift_modifier = shift_pressed > 0 ? -1 : 1;
  if (record->event.pressed) {
    rgblight_sethsv(
      (uint16_t) rgblight_get_hue() + (h * shift_modifier) % 361,
      (uint8_t) rgblight_get_sat() + (s * shift_modifier) % 256,
      (uint8_t) rgblight_get_val() + (v * shift_modifier) % 256);
  }
}
