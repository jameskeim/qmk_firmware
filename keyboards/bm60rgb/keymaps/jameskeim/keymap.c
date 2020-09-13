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

// Make macros a bit simpler with this shortcut.
#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

// Is shift being held? Let's store this in a bool.
// static bool shift_held = false;

// unicode map

enum unicode_name {
  GRIN, // grinning face 😊
  SHRUG, // Shrugging person
  TJOY, // tears of joy 😂
  SMILE, // grining face with smiling eyes 😁
  HEART, // heart ❤
  EYERT, // smiling face with heart shaped eyes 😍
  CRY, // crying face 😭
  SMEYE, // smiling face with smiling eyes 😊
  UNAMU, // unamused 😒
  KISS, // kiss 😘
  HART2, // two hearts 💕
  WEARY, // weary 😩
  OKHND, // ok hand sign 👌
  PENSV, // pensive 😔
  SMIRK, // smirk 😏
  RECYC, // recycle ♻
  WINK, // wink 😉
  THMUP, // thumb up 👍
  THMDN, // thumb down 👎
  PRAY, // pray 🙏
  PHEW, // relieved 😌
  MUSIC, // musical notes
  FLUSH, // flushed 😳
  CELEB, // celebration 🙌
  CRY2, // crying face 😢
  COOL, // smile with sunglasses 😎
  NOEVS, // see no evil
  NOEVH, // hear no evil
  NOEVK, // speak no evil
  POO, // pile of poo
  EYES, // eyes
  VIC, // victory hand
  BHART, // broken heart
  SLEEP, // sleeping face
  SMIL2, // smiling face with open mouth & sweat
  HUNRD, // 100
  CONFU, // confused
  TONGU, // face with tongue & winking eye
  DISAP, // disappointed
  YUMMY, // face savoring delicious food
  CLAP, // hand clapping
  FEAR, // face screaming in fear
  HORNS, // smiling face with horns
  HALO, // smiling face with halo
  BYE, // waving hand
  SUN, // sun
  MOON, // moon
  SKULL, // skull

  // greek letters
  UALPH,
  UBETA,
  UGAMM,
  UDELT,
  UEPSI,
  UZETA,
  UETA,
  UTHET,
  UIOTA,
  UKAPP,
  ULAMB,
  UMU,
  UNU,
  UXI,
  UOMIC,
  UPI,
  URHO,
  USIGM,
  UTAU,
  UUPSI,
  UPHI,
  UCHI,
  UPSI,
  UOMEG,

  LALPH,
  LBETA,
  LGAMM,
  LDELT,
  LEPSI,
  LZETA,
  LETA,
  LTHET,
  LIOTA,
  LKAPP,
  LLAMB,
  LMU,
  LNU,
  LXI,
  LOMIC,
  LPI,
  LRHO,
  LSIGM,
  LTAU,
  LUPSI,
  LPHI,
  LCHI,
  LPSI,
  LOMEG,

  FSIGM,

  LTEQ,
  GTEQ,
  NOTEQ,
  PLMIN,
};

const uint32_t PROGMEM unicode_map[] = {
  [GRIN] = 0x1F600,
  [SHRUG] = 0x1F937,
  [TJOY] = 0x1F602,
  [SMILE] = 0x1F601,
  [HEART] = 0x2764,
  [EYERT] = 0x1f60d,
  [CRY] = 0x1f62d,
  [SMEYE] = 0x1F60A,
  [UNAMU] = 0x1F612,
  [KISS] = 0x1F618,
  [HART2] = 0x1F495,
  [WEARY] = 0x1F629,
  [OKHND] = 0x1F44C,
  [PENSV] = 0x1F614,
  [SMIRK] = 0x1F60F,
  [RECYC] = 0x267B,
  [WINK] = 0x1F609,
  [THMUP] = 0x1F44D,
  [THMDN] = 0x1F44E,
  [PRAY] = 0x1F64F,
  [PHEW] = 0x1F60C,
  [MUSIC] = 0x1F3B6,
  [FLUSH] = 0x1F633,
  [CELEB] = 0x1F64C,
  [CRY2] = 0x1F622,
  [COOL] = 0x1F60E,
  [NOEVS] = 0x1F648,
  [NOEVH] = 0x1F649,
  [NOEVK] = 0x1F64A,
  [POO] = 0x1F4A9,
  [EYES] = 0x1F440,
  [VIC] = 0x270C,
  [BHART] = 0x1F494,
  [SLEEP] = 0x1F634,
  [SMIL2] = 0x1F605,
  [HUNRD] = 0x1F4AF,
  [CONFU] = 0x1F615,
  [TONGU] = 0x1F61C,
  [DISAP] = 0x1F61E,
  [YUMMY] = 0x1F60B,
  [CLAP] = 0x1F44F,
  [FEAR] = 0x1F631,
  [HORNS] = 0x1F608,
  [HALO] = 0x1F607,
  [BYE] = 0x1F44B,
  [SUN] = 0x2600,
  [MOON] = 0x1F314,
  [SKULL] = 0x1F480,

  // greek letters
  [UALPH] = 0x0391,
  [UBETA] = 0x0392,
  [UGAMM] = 0x0393,
  [UDELT] = 0x0394,
  [UEPSI] = 0x0395,
  [UZETA] = 0x0396,
  [UETA] = 0x0397,
  [UTHET] = 0x0398,
  [UIOTA] = 0x0399,
  [UKAPP] = 0x039A,
  [ULAMB] = 0x039B,
  [UMU] = 0x039C,
  [UNU] = 0x039D,
  [UXI] = 0x039E,
  [UOMIC] = 0x039F,
  [UPI] = 0x03A0,
  [URHO] = 0x03A1,
  [USIGM] = 0x03A3,
  [UTAU] = 0x03A4,
  [UUPSI] = 0x03A5,
  [UPHI] = 0x03A6,
  [UCHI] = 0x03A7,
  [UPSI] = 0x03A8,
  [UOMEG] = 0x03A9,
  [LALPH] = 0x03B1,
  [LBETA] = 0x03B2,
  [LGAMM] = 0x03B3,
  [LDELT] = 0x03B4,
  [LEPSI] = 0x03B5,
  [LZETA] = 0x03B6,
  [LETA] = 0x03B7,
  [LTHET] = 0x03B8,
  [LIOTA] = 0x03B9,
  [LKAPP] = 0x03BA,
  [LLAMB] = 0x03BB,
  [LMU] = 0x03BC,
  [LNU] = 0x03BD,
  [LXI] = 0x03BE,
  [LOMIC] = 0x03BF,
  [LPI] = 0x03C0,
  [LRHO] = 0x03C1,
  [LSIGM] = 0x03C3,
  [LTAU] = 0x03C4,
  [LUPSI] = 0x03C5,
  [LPHI] = 0x03C6,
  [LCHI] = 0x03C7,
  [LPSI] = 0x03C8,
  [LOMEG] = 0x03C9,
  [FSIGM] = 0x03C2,

  // other
  [LTEQ] = 0x2264, // less than or equal
  [GTEQ] = 0x2265, // greater than or equal
  [NOTEQ] = 0x2260, // not equal
  [PLMIN] = 0xB1, // plus minus
};


/* Custom keycodes so that they fit into limited-width cells */
enum custom_keycodes {
  BASELR = SAFE_RANGE,
  MUSERNAME,
  CTLENT,
  CTLESC,
  MVERSION,
  FUNC_1,
  FUNC_2,
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

#define BASELR DF(0)   // Switch to BASE LAYER layout
#define GAMLAYR DF(1) // Switch to GAME LAYER layout 
#define CTLENT MT(MOD_RCTL, KC_ENT) // ENTER/RETURN work same but can be held for RCTRL
#define CTLESC CTL_T(KC_ESC) // Put CTL and ESC on the same key. (replace CAPSLOCK)
#define FUNC_1 LT(2, KC_MENU) // Windows MENU key doubles as Primary Function Key
#define FUNC_2 LT(3, KC_SLSH) // Put the SLASH/QUESTIONMARK on the Tap
#define FN_TAB LT(3, KC_TAB) // TAB also functions as a Function key.
#define SPCFUNC LT(5, KC_SPC) // Use the SPACE BAR as a Function key when held.
#define MADJUST MO(4) // Hold for keyboard adjustment layer
#define CTLCAPS CTL_T(KC_CAPS) // When you want to include CTRL and CAPSLOCK on same key.
#define CTLALTD LCTL(LALT(KC_DEL)) // Just and easier way to press CTL-ALT-DEL 
#define HYPCAPS MEH_T(KC_CAPS)
#define HYPRTAB MEH_T(KC_TAB)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  	switch(keycode) {
    case MUSERNAME:
      	if (record->event.pressed) {
        	SEND_STRING("email");
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( // Base Layer -- Main typing layer w/ all the dual action keys I like to use.
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        HYPRTAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CTLESC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, CTLENT,
        KC_LSPO,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSPC,        KC_UP,   FUNC_2,
        KC_LEAD,   KC_LGUI,   KC_LAPO,                       SPCFUNC,                              KC_RAPC, FUNC_1,   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT( // Game Layer -- Single use keys -- No GUI key.
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,        KC_UP,   KC_SLSH,
        KC_LEAD,   OSL(2),   KC_LALT,                       KC_SPC,                              KC_RALT, FUNC_1,   KC_LEFT, KC_DOWN, KC_RGHT
    ),    
    [2] = LAYOUT( // Basic Function Layer -- just the basic extra keys needed.
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        GAMLAYR, MADJUST,
        KC_CAPS,   _______,   _______,                      _______,                              _______, _______, _______, BASELR, _______
    ),
    [3] = LAYOUT( // Hardware Layer -- Additional FKeys as well as RGB, Volume, and hardware info.
        _______,   KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,  KC_F21,  KC_F22,  CTLALTD,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______,  RGB_M_G, RGB_M_P, _______, _______, KC_LGUI, _______, _______, RGB_M_K, _______, _______, _______, _______,
        _______,           _______, _______, _______, _______, RGB_M_B, _______, _______, _______, _______, _______,        KC_VOLU, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, KC_VOLD, _______
    ),
    [4] = LAYOUT( // Main Adjustment Layer. Choose Base Layer or Game Layer. RESET Keyboard. 
        RESET,   BASELR,  GAMLAYR,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, MTHINGS, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, MMYKEEB, MVERSION, _______, _______, _______, _______, _______, _______,        _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______
    ),
    [5] = LAYOUT( // Space Function Layer -- All the keys I want to access easily via Space Bar.
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,  _______, _______, MUSERNAME, _______, _______, _______, _______, KC_INS, _______, KC_PSCR, _______, _______, KC_SLSH,
        _______,       _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        KC_PGUP, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, KC_HOME, KC_PGDN, KC_END
    )
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // Start keyboard in Windows Unicode mode.  ¯\_(ツ)_/¯
    set_unicode_input_mode(UC_WINC);
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Test to make sure LEADER key in working.
        SEQ_TWO_KEYS(KC_H, KC_W) {
            SEND_STRING("Hello World!");
        }
        // Shrug emoji
        SEQ_THREE_KEYS(KC_S, KC_H, KC_G) {
            SEND_STRING(X(SHRUG));
        }
        // Personal Email
        SEQ_TWO_KEYS(KC_E, KC_M) {
            SEND_STRING("email@jameskeim.com");
        }
        // Work Email
        SEQ_TWO_KEYS(KC_W, KC_E) {
            SEND_STRING("jkeim@arborday.org");
        }
        // Select All and Copy
         SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        }
        // Turn on OSX Unicode mode.
         SEQ_THREE_KEYS(KC_O, KC_S, KC_X) {
            set_unicode_input_mode(UC_OSX);
        }    
        // Turn on Windows Unicode mode.
         SEQ_THREE_KEYS(KC_W, KC_I, KC_N) {
            set_unicode_input_mode(UC_WINC);
        }  
        // Turn on Linux Unicode mode.
         SEQ_THREE_KEYS(KC_L, KC_I, KC_N) {
            set_unicode_input_mode(UC_LNX);
        }
        // Unicode Shrug
        SEQ_ONE_KEY (KC_1) {
          // ¯\_(ツ)_/¯
          unicode_input_start(); register_hex(0xaf); unicode_input_finish();
          TAP_ONCE (KC_BSLS); register_code (KC_RSFT); TAP_ONCE (KC_MINS); 
          TAP_ONCE (KC_9); unregister_code (KC_RSFT);
          unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
          register_code (KC_RSFT); TAP_ONCE (KC_0); TAP_ONCE(KC_MINS); 
          unregister_code (KC_RSFT); TAP_ONCE (KC_SLSH);
          unicode_input_start (); register_hex(0xaf); unicode_input_finish();
        }
        // Unicode Thumbs Up
        SEQ_ONE_KEY (KC_2) {
          // 凸(ツ)凸
          unicode_input_start(); register_hex(0x51F8); unicode_input_finish();
          register_code (KC_RSFT); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
          unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
          register_code (KC_RSFT); TAP_ONCE (KC_0); unregister_code (KC_RSFT);
          unicode_input_start (); register_hex(0x51F8); unicode_input_finish();
        }
    }
}



