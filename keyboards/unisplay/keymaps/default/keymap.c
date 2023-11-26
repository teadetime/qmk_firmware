/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _SYMNAV,
  _BRACK,
  _NUM,
  _CONFIG,
};

#define SYMNAV MO(_SYMNAV)
#define BRACK  MO(_BRACK)
#define NUM  MO(_NUM)

#define SYM_SP LT(SYMNAV, KC_SPC)
#define BRCK_D LT(BRACK, KC_D)
#define BRCK_BSPC LT(BRACK, KC_BSPC)
#define NUM_S LT(NUM, KC_S)


#define CTRL_A RCTL_T(KC_A)
#define CTRL_DE RCTL_T(KC_DEL)
#define SF_Z RSFT_T(KC_Z)
#define SF_DQ RSFT_T(KC_DQT)
#define AL_SEM RALT_T(KC_SCLN)
#define AL_ENT RALT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,    KC_W,     KC_E,       KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    CTRL_A,  NUM_S,    BRCK_D,     KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    AL_SEM,
    SF_Z,    KC_X,     KC_C,       KC_V,    KC_P,           KC_N,    KC_M,    KC_COMM,   KC_DOT,   SF_DQ,
           CTRL_DE,  BRCK_BSPC,     KC_NO,        KC_NO, KC_NO,        KC_NO, SYM_SP,  AL_ENT
  ),

  // [_SYMNAV] = LAYOUT(
  //   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,
  //   KC_LSFT, KC_ESC,  KC_LGUI, KC_LALT, KC_QUOT, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_RSFT,
  //   _______,                                _______,                                 _______
  // ),
  
  // [_RAISE] = LAYOUT(
  //   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, XXXXXXX, KC_GRV,  KC_TILD, KC_COLN,
  //   KC_LSFT, KC_ESC,  KC_RGUI, KC_LALT, KC_DQUO, KC_TAB,  KC_RALT, KC_RCTL, KC_RALT, KC_RSFT,
  //   _______,                                KC_DEL,                                  _______
  // ),
  
  // [_ADJUST] = LAYOUT(
  //   RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  
  //   RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, 
  //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,   KC_F11,  KC_F12,  KC_CAPS, XXXXXXX, KC_PSCR,
  //   _______,                                 _______,                                _______
  // ),
};

#define ENCODER_MAP_KEY_DELAY 100
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
    // [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    // [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    // [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMNAV, _BRACK, _CONFIG);
}
