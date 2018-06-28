#include "levinson.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _TARMAK_1 1
#define _TARMAK_2 2
#define _TARMAK_3 3
#define _TARMAK_4 4
#define _COLEMAK 5
#define _LOWER 6
#define _RAISE 7
#define _PAD 8
#define _ADJUST 16

#define ESC_CTRL MT(MOD_LCTL, KC_ESC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  TARMAK_1,
  TARMAK_2,
  TARMAK_3,
  TARMAK_4,
  LOWER,
  RAISE,
  ADJUST,
  PAD
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EsCtrl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PAD  | Ctrl | Alt  | GUI  |Lower |Space | Shift| Raise| GUI  | Alt  | Ctrl | PAD  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  ESC_CTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  PAD,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, PAD \
),

/* Tarmak 1
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   J  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EsCtrl|   A  |   S  |   D  |   F  |   G  |   H  |   N  |   E  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PAD  | Ctrl | Alt  | GUI  |Lower |Space | Shift| Raise| GUI  | Alt  | Ctrl | PAD  |
 * `-----------------------------------------------------------------------------------'
 */
[_TARMAK_1] = LAYOUT_ortho_4x12( \
  KC_TAB,   KC_Q,    KC_W,    KC_J,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  ESC_CTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_N,    KC_E,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  PAD,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, PAD \
),

/* Tarmak 2
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   R  |   G  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EsCtrl|   A  |   S  |   D  |   T  |   J  |   H  |   N  |   E  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PAD  | Ctrl | Alt  | GUI  |Lower |Space | Shift| Raise| GUI  | Alt  | Ctrl | PAD  |
 * `-----------------------------------------------------------------------------------'
 */
[_TARMAK_2] = LAYOUT_ortho_4x12( \
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_R,    KC_G,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  ESC_CTRL, KC_A,    KC_S,    KC_D,    KC_T,    KC_J,    KC_H,    KC_N,    KC_E,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  PAD,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, PAD \
),

/* Tarmak 3
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   J  |   G  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EsCtrl|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PAD  | Ctrl | Alt  | GUI  |Lower |Space | Shift| Raise| GUI  | Alt  | Ctrl | PAD  |
 * `-----------------------------------------------------------------------------------'
 */
[_TARMAK_3] = LAYOUT_ortho_4x12( \
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_J,    KC_G,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  ESC_CTRL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  PAD,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, PAD \
),

/* Tarmak 4
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   R  |   G  |   J  |   U  |   I  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EsCtrl|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   L  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PAD  | Ctrl | Alt  | GUI  |Lower |Space | Shift| Raise| GUI  | Alt  | Ctrl | PAD  |
 * `-----------------------------------------------------------------------------------'
 */
[_TARMAK_4] = LAYOUT_ortho_4x12( \
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_U,    KC_I,    KC_Y,    KC_SCLN,    KC_BSPC, \
  ESC_CTRL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_L,    KC_O, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  PAD,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, PAD \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PAD  | Ctrl | Alt  | GUI  |Lower |Space | Shift| Raise| GUI  | Alt  | Ctrl | PAD  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  PAD,     KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_RSFT, RAISE,   KC_RGUI, KC_RALT, KC_RCTL, PAD \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   -  |   =  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |  (   |   {  |   }  |   )  |   _  |   +  |   \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  <   |   [  |   ]  |   >  |   ;  |   =  |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Enter|      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_EQUAL, KC_BSPC, \
  KC_DEL,  _______, _______, _______, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_UNDS, KC_PLUS,  KC_BSLS,  KC_PIPE, \
  _______, _______, _______, _______, KC_LT,   KC_LBRC, KC_RBRC, KC_GT,   KC_SCLN, KC_EQUAL,  _______,  _______, \
  _______, _______, _______, _______, _______, _______, KC_ENT , _______, KC_MNXT, KC_VOLD,  KC_VOLU,  KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      | Tab  |      | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Bksp |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC, \
  KC_DEL,  _______, _______, _______, KC_TAB, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, KC_BSPC, _______, _______, KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |   1  |   2  |   3  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   0  |   .  |   *  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PAD] = LAYOUT_ortho_4x12( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_7, KC_8, KC_9, KC_MINUS,  KC_BSPC, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_4, KC_5, KC_6, KC_PLUS,   _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_1, KC_2, KC_3, KC_SLASH,  KC_ENTER, \
  _______, _______, _______, _______, _______, _______, _______, KC_0, KC_0, KC_DOT, KC_ASTR, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD,  RGB_SAI,  RGB_VAD,  RGB_VAI,  _______, _______, \
  _______, _______, _______, _______, _______, _______, QWERTY ,  _______,  _______,  _______,  _______, _______, \
  _______, _______, BL_DEC , BL_INC , BL_TOGG, BL_BRTG, TARMAK_1, TARMAK_2, TARMAK_3, TARMAK_4, COLEMAK, _______, \
  _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case TARMAK_1:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_TARMAK_1);
      }
      return false;
      break;
    case TARMAK_2:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_TARMAK_2);
      }
      return false;
      break;
    case TARMAK_3:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_TARMAK_3);
      }
      return false;
      break;
    case TARMAK_4:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_TARMAK_4);
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
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case PAD:
      if (record->event.pressed) {
        layer_on(_PAD);
      } else {
        layer_off(_PAD);
      }
      return false;
      break;

  }
  return true;
}
