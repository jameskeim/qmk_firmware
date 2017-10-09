/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "config.h"
#include "quantum.h"
#include "action_layer.h"
#include "version.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SPACEFN,
  _GR,
  _GR_S,
  _QUOTFN,
  _MAUS,
  _ADJUST,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER = LT(_LOWER, KC_BSPC),
  RAISE = LT(_RAISE, KC_ENT),
  // Raise and Lower hack to allow keys to also be used as Enter and BkSpc 
  // see https://www.reddit.com/r/olkb/comments/4x3dei/hack_too_ugly_to_live/?st=j8d81346&sh=416ceb39
  SPACEFN = LT(_SPACEFN, KC_SPC),
  MAUS_K = LT(_MAUS, KC_K),
  QUOTFN = LT(_QUOTFN, KC_QUOT),
  INTL = LT(_GR, KC_APP),
  CTL_AD = LALT(LCTL(KC_DEL)),
  M_USERNAME,
  M_VERSION,
  M_WINDOWS,          // Sets Unicode handler to windows
  M_LINUX,        // Sets Unicode handler to linux
  M_OSX,          // Sets Unicode handler to OSX
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"
    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Back |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  | MS_K |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | Alt  | GUI  |  App |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    MAUS_K,    KC_L,    KC_SCLN, QUOTFN},
  {LSFT_T(KC_GRV), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT)},
  {CTL_T(KC_DEL), KC_LGUI, KC_LALT, INTL, LOWER, SPACEFN, SPACEFN, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |ISO ~ |ISO | | Inst | PrSc |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Backspace  |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TAB,  KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_CAPS, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, S(KC_NUHS), S(KC_NUBS), KC_INS,  KC_PSCR, _______},
  {_______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Prev | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CTL_AD},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_MPRV, KC_MNXT,  _______},
  {_______, _______, _______, _______, _______, KC_ENT, KC_ENT, _______, KC_MUTE,  KC_VOLD, KC_VOLU, KC_MPLY}
},

/* SpaceFN
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Back |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  | Left | Down |  Up  |Right |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  | MAUS |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | Alt  | GUI  |  App |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SPACEFN] = {
  {_______,  KC_Q,  KC_W,  M_USERNAME,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______},
  {_______,  _______,  _______,    KC_D,    KC_F,    KC_G,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_SCLN, KC_ENT},
  {_______, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,    KC_C,    M_VERSION,    KC_SPC,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______},
  {_______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______}
},

/* MarkDown
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Back |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  | Left | Down |  Up  |Right |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |  M   |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | Alt  | GUI  |  App |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MKDN] = {
   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
   {_______, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP, _______, _______, _______, M_WINDOWS, M_LINUX, M_OSX, _______, _______},
   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|Windoz|Linux | OSX  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,   M_WINDOWS, M_LINUX, M_OSX, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* Gr layer / international keys
 * ,-----------------------------------------------------------------------------------.
 * |      |  ä   |  å   |      |  ¢£  |  €¥  |      |  ë   |  ê   |  ü   |  ù   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  â   |  à   |  ß   |      |      |      |  è   |  é   |  ï   |  ö   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  æ   |  ô   |  ç   |  œ   |      |      |  û   |  «   |  »   |  î   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_GR] = {
  {_______,  UC(0xE4),UC(0xE5), _______,UC(0xA2), UC(0x20AC),_______,UC(0xEB),UC(0xEA),UC(0xFC),UC(0xF9), _______},
  {_______,  UC(0xE2),UC(0xE0),UC(0xDF), _______, _______,   _______,UC(0xE8),UC(0xE9),UC(0xEF),UC(0xF6), _______},
  {MO(_GR_S),UC(0xE6),UC(0xF4),UC(0xE7),UC(0x153),_______,   _______,UC(0xFB),UC(0xAB),UC(0xBB),UC(0xEE), MO(_GR_S)},
  {_______,  _______, _______, _______, _______,  _______,   _______, _______, _______, _______, _______, _______}
},

// Shifted layer of the above
[_GR_S] = {
  {_______,  UC(0xC4),UC(0xC5), _______, UC(0xA3), UC(0xA5),_______, UC(0xCB),UC(0xCA),UC(0xDC),UC(0xD9),_______},
  {_______,  UC(0xC2),UC(0xC0), UC(0xDF),_______,  _______, _______, UC(0xC8),UC(0xC9),UC(0xCF),UC(0xD6),_______},
  {MO(_GR_S),UC(0xC6),UC(0xD4), UC(0xC7),UC(0x152),_______, _______, UC(0xDB),UC(0xAB),UC(0xBB),UC(0xCE),MO(_GR_S)},
  {_______,  _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______}
},

/* MOUSEKEYS
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Back |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | Alt  | GUI  |  App |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MAUS] = {
  {_______,  QWERTY, _______, KC_MS_U, _______, KC_WH_U, _______, KC_BTN4, _______, KC_BTN5, _______, _______},
  {_______,  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_BTN1, _______, KC_BTN2, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______}
}
};

void matrix_init_user(){
  set_unicode_input_mode(UC_WIN);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
  }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
//   return false;
//   Raise and Lower hack to allow keys to also be used as Enter and BkSpc 
//   see https://www.reddit.com/r/olkb/comments/4x3dei/hack_too_ugly_to_live/?st=j8d81346&sh=416ceb39
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
//   return false;
//   Raise and Lower hack to allow keys to also be used as Enter and BkSpc 
//   see https://www.reddit.com/r/olkb/comments/4x3dei/hack_too_ugly_to_live/?st=j8d81346&sh=416ceb39
      break;
    case SPACEFN:
      if (record->event.pressed) {
        layer_on(_SPACEFN);
      } else {
        layer_off(_SPACEFN);
      }
 //  return false;
      break;
    case QUOTFN:
      if (record->event.pressed) {
        layer_on(_QUOTFN);
      } else {
        layer_off(_QUOTFN);
      }
 //  return false;
      break;
    case MAUS_K:
      if (record->event.pressed) {
        layer_on(_MAUS);
      } else {
        layer_off(_MAUS);
      }
 //     return false;
      break;
    case INTL:
      if (record->event.pressed) {
        layer_on(_GR);
      } else {
        layer_off(_GR);
      }
 //     return false;
      break;
    case M_WINDOWS:
      set_unicode_input_mode(UC_WIN);
      break;
    case M_LINUX:
      set_unicode_input_mode(UC_LNX);
      break;
    case M_OSX:
      set_unicode_input_mode(UC_OSX);
      break;
    case M_USERNAME:
      if (record->event.pressed) {
        SEND_STRING("email@jameskeim.com");
      }
      break;
    case M_VERSION:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
      }
      break;

  }
  return true;
}