/* (CC) 2020 James Keim
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
#include "config.h"
#include "quantum.h"
#include "version.h"



/* Fillers to make layering more clear */
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

/* Custom keycodes so that they fit into limited-width cells */
enum custom_keycodes {
  BASELR = SAFE_RANGE,
  MUSERNAME,
  CTLENT,
  CTLESC,
  MVERSION,
  MFUNC,
  FN_TAB,
  SPCFUNC,
  MADJUST,
  CTLCAPS,
  MTHINGS,
  CTLALTD,
  MMYKEEB,
  GAMLAYR,
  HYPCAPS,
  HYPRTAB,
  /* DYNAMIC_MACRO_RANGE, */
};

#define BASELR DF(0)   /* Switch to BASE LAYER layout */
#define CTLENT MT(MOD_RCTL, KC_ENT)
#define CTLESC CTL_T(KC_ESC)
#define MFUNC LT(2, KC_SLSH) /* Put the SLASH/QUESTIONMARK on the Tap */
#define FN_TAB LT(2, KC_TAB) /* TAB also functions as a Function key. */
#define SPCFUNC LT(4, KC_SPC)
#define MADJUST MO(3)
#define CTLCAPS CTL_T(KC_CAPS)
#define CTLALTD LCTL(LALT(KC_DEL)) /* Just and easier way to press CTL-ALT-DEL */
#define GAMLAYR DF(5) /* Switch to GAME LAYER layout */
#define HYPCAPS MEH_T(KC_CAPS)
#define HYPRTAB MEH_T(KC_TAB)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  	switch(keycode) {
    case MUSERNAME:
      	if (record->event.pressed) {
        	SEND_STRING("email@jameskeim.com");
        } else {
        // When MUSERNAME is released    
        }
      	break;      
    case MVERSION:
      	if (record->event.pressed) {
        	SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
        } else {
        // when MVERSION is released
        }
      	break;
    case MTHINGS:
      	if (record->event.pressed) {
        	SEND_STRING("Here are some things."SS_TAP(X_ENTER));
        } else {
        // when MTHINGS is released
        }
      	break;
    case MMYKEEB:
      	if (record->event.pressed) {
        	SEND_STRING("This keyboard belongs to James Keim"SS_TAP(X_ENTER));} // I told you I'm vain.
      	break;
      	
    }
    return true;
};

bm60rgb/jameskeim@0.5.129-6570-g825743-dirty@2020-09-06-01:57:09

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // Base Layer -- Main typing layer w/ all the dual action keys I like to use.
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        HYPRTAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CTLESC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, CTLENT,
        KC_LSPO,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSPC,        KC_UP,   MFUNC,
        KC_LEAD,   KC_LGUI,   KC_LAPO,                       SPCFUNC,                              KC_RAPC, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT( // Basic Function Layer -- just the basic extra keys needed.
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, MADJUST,
        KC_CAPS,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT( // Hardware Layer -- Additional FKeys as well as RGB, Volume, and hardware info.
        _______,   KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,  KC_F21,  KC_F22,  CTLALTD,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______,  RGB_M_G, RGB_M_P, _______, _______, KC_LGUI, _______, _______, RGB_M_K, _______, _______, _______, _______,
        _______,           _______, _______, MMYKEEB, MVERSION, RGB_M_B, _______, _______, _______, _______, _______,        KC_VOLU, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, KC_VOLD, _______
    ),
    [3] = LAYOUT( // Main Adjustment Layer. Choose Base Layer or Game Layer. RESET Keyboard. 
        RESET,   BASELR,  GAMLAYR,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, MTHINGS, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        GAMLAYR, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, BASELR, _______
    ),
    [4] = LAYOUT( // Space Function Layer -- All the keys I want to access easily via Space Bar.
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,  _______, _______, MUSERNAME, _______, _______, _______, _______, KC_INS, _______, KC_PSCR, _______, _______, KC_SLSH,
        _______,       _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        KC_PGUP, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, KC_HOME, KC_PGDN, KC_END
    ),
    [5] = LAYOUT( // Game Layer -- Single use keys -- No GUI key.
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,        KC_UP,   KC_SLSH,
        KC_CAPS,   OSL(1),   KC_LALT,                       KC_SPC,                              KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    )
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_G, KC_P) {
            SEND_STRING("git push");
        }
        SEQ_THREE_KEYS(KC_G, KC_F, KC_P) {
            SEND_STRING("git push --force-with-lease");
        }
    }
}



