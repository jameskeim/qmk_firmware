/* Copyright 2018 Alexander Fougner <fougner89 at gmail.com>
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


/* Macros need to be uniquely identified; using an enum to do this
   automatically
 */

enum macro_id {
  M_USERNAME,
  M_VERSION,
  M_THINGS,
  M_MYKEEB,
};


/* Fillers to make layering more clear */
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

/* Custom keycodes so that they fit into
   limited-width cells */

enum my_keycodes {
  QWERTY = SAFE_RANGE,
  USERNAME,
  CTLENT,
  CTLESC,
  SFTBSPC,
  SFTDEL,
  MVERSION,
  MFUNC,
  FN_TAB,
  SPCFUNC,
  MADJUST,
  CTLCAPS,
  MTHINGS,
  CTLALTD,
  MMYKEEB,
  GM_LAYR,
  /* DYNAMIC_MACRO_RANGE, */
};

/*
#include "dynamic_macro.h"
*/
#define QWERTY DF(0)   /* Switch to QWERTY layout */
/* #define QCENT2 DF(_QCENT2)  Switch to QWERTY-with-centre layout */
#define USERNAME M(M_USERNAME) /* shortcut for username */
#define CTLENT MT(MOD_RCTL, KC_ENT)
#define CTLESC CTL_T(KC_ESC)
#define SFTBSPC MT(MOD_LSFT, KC_BSPC)
#define SFTDEL MT(MOD_RSFT, KC_DEL)
/*#define ALTRIGHT MT(MOD_LALT, KC_RGHT) NO ALT RIGHT IN THIS KEYBOARD! */
#define MVERSION M(M_VERSION)
#define MFUNC MO(1)
#define FN_TAB LT(1, KC_TAB)
#define SPCFUNC LT(3, KC_SPC)
#define MADJUST MO(2)
#define CTLCAPS CTL_T(KC_CAPS)
#define MTHINGS M(M_THINGS)
#define CTLALTD LCTL(LALT(KC_DEL))
#define MMYKEEB M(M_MYKEEB)
#define GM_LAYR DF(4)





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_tkl_ansi(
                KC_ESC,   KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS,
                KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
                FN_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
                CTLESC,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,           CTLENT,
                SFTBSPC,           KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,           SFTDEL,            KC_UP,
                KC_LCTL,KC_LGUI,KC_LALT,                SPCFUNC,                         KC_RALT,KC_RGUI, MFUNC,   KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT),

[1] = LAYOUT_tkl_ansi(
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, CTLALTD,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_MPLY, KC_MNXT, KC_VOLU,
                 FN_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_MSTP, KC_MPRV, KC_VOLD,
                _______, _______, MADJUST, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,          _______,
                _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
                _______, _______, _______,               KC_ENT,                                          _______, _______,   MFUNC, _______,    _______, _______, _______),

[2] = LAYOUT_tkl_ansi(
                _______,  QWERTY, GM_LAYR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, XXXXXXX,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_MPLY, KC_MNXT, KC_VOLU,
                _______, _______, _______,USERNAME,   RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_MSTP, KC_MPRV, KC_VOLD,
                _______, _______, MADJUST, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
                _______,          _______, _______, MMYKEEB,MVERSION, _______, _______, _______, _______, _______, _______,          _______,             _______,
                _______, _______, _______,              KC_SPC,                                           _______, _______,   MFUNC, _______,    _______, _______, _______),

[3] = LAYOUT_tkl_ansi(
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______, MTHINGS,
                 KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,    KC_MPLY, KC_MNXT, KC_VOLU,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_MSTP, KC_MPRV, KC_VOLD,
                KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
                _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
                _______, _______, _______,              SPCFUNC,                                          _______, _______,   MFUNC, _______,    _______, _______, _______),
 
[4] = LAYOUT_tkl_ansi(
                KC_ESC,   KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS,
                KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
                KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
                KC_CAPS,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,           KC_ENT,
                KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,           KC_RSFT,            KC_UP,
                KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                                   KC_RALT,KC_RGUI, MFUNC,   KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT)

};
const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
  /* MACRODOWN only works in this function */
  	switch(id) {
    	case M_USERNAME:
      		if (record->event.pressed) {
        		SEND_STRING("email@jameskeim.com");}
      	break;
    	case M_VERSION:
      		if (record->event.pressed) {
        		SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);}
      	break;
      	case M_THINGS:
      		if (record->event.pressed) {
        		SEND_STRING("8Sexutime1Xe"SS_TAP(X_ENTER));}
      	break;
      	case M_MYKEEB:
      		if (record->event.pressed) {
        		SEND_STRING("This keyboard belongs to James Keim"SS_TAP(X_ENTER));}
      	break;
      	
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
	if (!process_record_dynamic_macro(keycode, record)) {
     	return false;
    }
*/
  return true;
}

void led_set_user(uint8_t usb_led) {

}
