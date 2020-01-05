/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

#define NAV_SCLN LT(NAV_LAYER, KC_SCLN)

// Keymap layers
enum {
    QWERTY_LAYER,
    FN_LAYER,
    NAV_LAYER,
};

// Tap dance declarations
enum {
  TD_TOG_M = 0,
  TD_TOG_C,
  TD_TOG_FILES,
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {

  // once: /, twice: CTRL+/ to comment out sections in Sublime
  [TD_TOG_C]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LCTL(KC_SLSH)),

};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: QWERTY Layer
     * ,--------------------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backs | Del |  `  |
     * |--------------------------------------------------------------------------------------------------|
     * | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |      \     | Del |
     * |--------------------------------------------------------------------------------------------------|
     * | CAPL    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter      | PgU |
     * |--------------------------------------------------------------------------------------------------|
     * | Shift     |     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift |  Up  | PgD |
     * |--------------------------------------------------------------------------------------------------|
     * | Ctrl |  LGUI  |  LAlt  |         Space         |  Fn1  |  Ctrl  |              | Lef | Dow | Rig |
     * `--------------------------------------------------------------------------------------------------'
     */
    [QWERTY_LAYER] = LAYOUT( \
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4,  KC_5,   KC_6, KC_7, KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, KC_GRV,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,  KC_T,   KC_Y, KC_U, KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC,         KC_BSLS, KC_DEL,  \
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F,  KC_G,   KC_H, KC_J, KC_K,   KC_L,    NAV_SCLN, KC_QUOT, KC_NUHS,         KC_ENT, KC_PGUP, \
        KC_LSFT, KC_NUBS, KC_Z,    KC_X, KC_C,  KC_V,   KC_B, KC_N, KC_M,   KC_COMM, KC_DOT,  TD(TD_TOG_C), KC_RSFT,      KC_UP, KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,              KC_SPC,             KC_FN0, KC_RCTL,                  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    /* Layer 1: FN Layer
     * ,---------------------------------------------------------------------------------------------------.
     * |     |  F1  | F2   | F3  |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 |     |     |     |     |  MUTE |
     * |---------------------------------------------------------------------------------------------------|
     * |       |     |     |     |     |     |     |     |     |     |     |     |     |            |      |
     * |---------------------------------------------------------------------------------------------------|
     * |         |     |     |     |     |     |     |     |     |     |     |     |                | VOL+ |
     * |---------------------------------------------------------------------------------------------------|
     * |           |     |     |     |     |     |     |     |     |     |     |     |       | PgUP | VOL- |
     * |---------------------------------------------------------------------------------------------------|
     * |      |        |        |                       |       |        |              | HOME| PgDN| END  |
     * `---------------------------------------------------------------------------------------------------'
     */
    [FN_LAYER] = LAYOUT( \
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_TRNS,KC_TRNS,KC_MUTE,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,  KC_VOLU,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_PGUP,  KC_VOLD,\
        KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS, KC_TRNS,                  KC_TRNS,           KC_HOME,KC_PGDN,  KC_END  \
    ),
    /* Layer 0: QWERTY Layer
     * ,--------------------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |        |     |     |
     * |--------------------------------------------------------------------------------------------------|
     * |       |     |     |     |     |     |     |     |     |     |     |     |     |      \     |     |
     * |--------------------------------------------------------------------------------------------------|
     * |         |     |HOME | PgUp| PgDN| END |Left | Down| Up  |Right|     |     |                |     |
     * |--------------------------------------------------------------------------------------------------|
     * |           |     |     |     |     |     |     |     |     |     |     |     |       |      |     |
     * |--------------------------------------------------------------------------------------------------|
     * |      |        |        |                       |       |        |              |     |     |     |
     * `--------------------------------------------------------------------------------------------------'
     */
    [NAV_LAYER] = LAYOUT( \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, NAV_SCLN,KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS, KC_TRNS,                  KC_TRNS,              KC_TRNS,KC_TRNS,KC_TRNS \
    ),
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};
