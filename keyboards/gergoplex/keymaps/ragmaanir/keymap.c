/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define _X_ KC_NO
#define _T_ KC_TRNS

#define KC_LSQBR  KC_LBRACKET
#define KC_RSQBR  KC_RBRACKET

// Combos
// enum combos {
//   QW,IO,OP,
//   AS,HJ,JK,KL,LSCLN,
//   FV,GB,
//   DQ,
//   FT,FF,FS,FN,FE,
//   VV,LR
// };

// NOTE: If you're using MT,LT or anything you must
// define it here. Note this if you change your layout!

/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    TAB    |     |     |      |      |     |     |    MINS  BSLH      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |    ESC    |     |     |      |      |    LES   ESC   GRT    |        |
 * |-----+-----+-----+-RMB-+-LMB--|      |--------------------------------|
 * |     |     |     |     |      |      |     |     |     |     |        |
 * `-----+-----+-----+-----+------'      `--------------------------------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |     |     |     |
 *  '-------------------------'           '-----------------'
 */
// const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

// const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
// const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};

// const uint16_t PROGMEM fv_combo[] = {KC_F, KC_V, COMBO_END};
// const uint16_t PROGMEM gb_combo[] = {KC_G, KC_B, COMBO_END};

// const uint16_t PROGMEM dq_combo[] = {KC_DLR, KC_QUOT, COMBO_END};

// const uint16_t PROGMEM ft_combo[] = {KC_F1, KC_F3, COMBO_END};
// const uint16_t PROGMEM ff_combo[] = {KC_F3, KC_F5, COMBO_END};
// const uint16_t PROGMEM fs_combo[] = {KC_F5, KC_F7, COMBO_END};
// const uint16_t PROGMEM fn_combo[] = {KC_F8, KC_F10, COMBO_END};
// const uint16_t PROGMEM fe_combo[] = {KC_F10, KC_F12, COMBO_END};

// const uint16_t PROGMEM vv_combo[] = {KC_VOLU, KC_VOLD, COMBO_END};
// const uint16_t PROGMEM lr_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   // Horizontal Chords
//   [QW] = COMBO(qw_combo, KC_TAB),
//   [IO] = COMBO(io_combo, KC_MINS),
//   [OP] = COMBO(op_combo, KC_BSLS),

//   [AS] = COMBO(as_combo, KC_ESC),
//   [HJ] = COMBO(hj_combo, KC_LT),
//   [JK] = COMBO(jk_combo, KC_ESC),
//   [KL] = COMBO(kl_combo, KC_GT),
//   [LSCLN] = COMBO(lscln_combo, KC_QUOT),

//   // Vertical
//   [GB] = COMBO(gb_combo, KC_BTN1),
//   [FV] = COMBO(fv_combo, KC_BTN2),

//   // Symbols
//   [DQ] = COMBO(dq_combo, KC_PIPE),
//   [FT] = COMBO(ft_combo, KC_F2),
//   [FF] = COMBO(ff_combo, KC_F4),
//   [FS] = COMBO(fs_combo, KC_F6),
//   [FN] = COMBO(fn_combo, KC_F9),
//   [FE] = COMBO(fe_combo, KC_F11),

//   // Pad
//   [VV] = COMBO(vv_combo, KC_MUTE),
//   [LR] = COMBO(lr_combo, KC_BTN3),
// };

// https://www.reddit.com/r/olkb/comments/72wuxs/qmk_best_way_to_setup_a_key_to_switch_to_layer_a/

enum Layer {
  LAYER_0 = 0,
  LAYER_1,
  LAYER_2,
  LAYER_3,
  LAYER_A,
  LAYER_S,
  LAYER_F,
  LAYER_G
};

enum CustomKeycodes {
    CX_A = SAFE_RANGE,
    CX_S,
    CX_F,
    CX_G
};

static uint16_t tap_timers[4];

// remember whether a key was pressed in a tap-hold layer so the tapping-function is skipped
bool key_pressed_in_taphold_layer = false;

#define NO_FALLTHROUGH false
#define FALLTHROUGH true

bool hold_or_fallthrough(bool pressed, uint16_t kc, uint8_t held_layer, uint16_t mod_bits, uint16_t *p_timer) {
  if(pressed){
    *p_timer = timer_read();
    layer_on(held_layer);
    register_mods(mod_bits);
    key_pressed_in_taphold_layer = false;
    return FALLTHROUGH; // dont fallback to default behavior
  } else {
    unregister_mods(mod_bits);
    layer_off(held_layer);

    // use default behavior if key tapped and no other key pressed while held
    // return timer_elapsed(*p_timer) < 300 && !key_pressed_in_taphold_layer;
    if(timer_elapsed(*p_timer) < 300 && !key_pressed_in_taphold_layer) {
      tap_code16(kc);
    }

    return NO_FALLTHROUGH;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case CX_A:
      return hold_or_fallthrough(record->event.pressed, KC_A, LAYER_A, MOD_BIT(KC_LCTRL), &tap_timers[0]);
    case CX_S:
      return hold_or_fallthrough(record->event.pressed, KC_S, LAYER_S, 0, &tap_timers[0]);
    case CX_F:
      return hold_or_fallthrough(record->event.pressed, KC_F, LAYER_F, 0, &tap_timers[0]);
    case CX_G:
      return hold_or_fallthrough(record->event.pressed, KC_G, LAYER_G, 0, &tap_timers[0]);
    default:
      key_pressed_in_taphold_layer = true;
      return FALLTHROUGH; // use default
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_0] = LAYOUT_gergoplex(
    KC_B,  KC_W, KC_E, KC_R, KC_T,    KC_Z, KC_U, KC_I, KC_O, KC_P,
    CX_A, CX_S, KC_D, CX_F, CX_G,    KC_H, KC_J, KC_K, KC_L, KC_Y,
    _X_,  KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_Q, KC_P, KC_N,

   	_X_, MO(1), MO(3),            KC_LSFT, MO(2), MO(4)
  ),

  [LAYER_1] = LAYOUT_gergoplex(
    KC_PAUSE, _X_, KC_SPACE, KC_TAB, KC_ESC,         _X_,     KC_BSPC, KC_UP,   KC_DEL,   _X_,
    _X_,      KC_TAB, _X_,   KC_ENT, KC_LWIN,       KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
    _X_,      KC_TAB, _X_,   _X_,    _X_,            _X_,     KC_BSPC, _X_,     _X_,      _X_,

    _X_, _T_, _X_,                                  KC_LSFT, _X_,   _X_
  ),

  // [LAYER_1_TAP] = LAYOUT_gergoplex(
  //   _X_, _X_, KC_MS_BTN2, _X_,        _X_,        _X_, _X_,        KC_MS_UP,   _X_,         _X_,
  //   _X_, _X_, _X_,        KC_MS_BTN1, _X_,        _X_, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _X_,
  //   _X_, _X_, _X_,        _X_,        _X_,        _X_, _X_,        _X_,        _X_,         _X_,

  //   _X_, _T_, KC_LCTRL,                           KC_LSFT, KC_LALT, _T_
  // ),

  [LAYER_2] = LAYOUT_gergoplex(
    KC_AMPR,  KC_PIPE, KC_UNDS, KC_EQL,  KC_COLN,      KC_DLR,  KC_LSQBR, KC_RSQBR, KC_LT,  KC_HASH,
    KC_EXLM,  KC_COMM, KC_DOT,  KC_MINS, KC_ASTR,      KC_DQT,  KC_LPRN,  KC_RPRN,  KC_GT,  KC_PERC,
    KC_QUES,  KC_SCLN, KC_BSLS, KC_PLUS, KC_SLASH,     KC_QUOT, KC_LCBR,  KC_RCBR,  KC_AT,  KC_TILD,

    _X_, _X_, KC_LCTRL,                                _X_, _T_, _X_
  ),

  [LAYER_3] = LAYOUT_gergoplex(
    KC_COMM,  KC_DOT, KC_0, KC_PLUS, KC_MINS,         _X_,    KC_BSPC, KC_9, KC_DEL, _X_,
    KC_1,     KC_2,   KC_3, KC_4,    KC_SPACE,        KC_ENT, KC_5,    KC_6, KC_7,   KC_8,
    _X_,      _X_,    _X_,  KC_BSLS, KC_ASTR,         _X_,    _X_,     _X_,  _X_,    _X_,

    _T_, _X_, _X_,                                       KC_LSFT, KC_LCTRL, KC_LALT
  ),

  /* Copy-paste, select all, save, undo, redo, ... */
  [LAYER_A] = LAYOUT_gergoplex(
    _X_, _X_, _X_, _X_,  _X_,        KC_A, KC_N, KC_S, KC_O, _X_,
    _T_, _X_, _X_, KC_C, KC_V,       KC_P,  _X_, KC_X, KC_Z, KC_Y,
    _X_, _X_, _X_, _X_,  _X_,        _X_,  KC_F,  _X_,  _X_, _X_,

    _X_, _X_, _X_,                            _X_, _X_, _X_
  ),

  [LAYER_S] = LAYOUT_gergoplex(
    _X_, _X_, _X_, _X_, _X_,        _X_, _X_, _X_, _X_, _X_,
    _X_, _T_, _X_, _X_, _X_,        _X_, _X_, _X_, _X_, _X_,
    _X_, _X_, _X_, _X_, _X_,        _X_, _X_, _X_, _X_, _X_,

    _X_, _X_, _X_,                            _X_, _X_, _X_
  ),

  [LAYER_F] = LAYOUT_gergoplex(
    _X_, _X_, _X_, _X_, _X_,       KC_MS_WH_UP, KC_MS_BTN3,   KC_MS_UP,          _X_, _X_,
    _X_, _X_, _X_, _T_, _X_,     KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT, _X_,
    _X_, _X_, _X_, _X_, _X_,               _X_,        _X_,        _X_,          _X_, _X_,

    _X_, _X_, _X_,                  KC_MS_BTN2, KC_MS_BTN1, _X_
  ),

  [LAYER_G] = LAYOUT_gergoplex(
    _X_, _X_, _X_, _X_, _X_,        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,
    _X_, _X_, _X_, _X_, _T_,        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
    _X_, _X_, _X_, _X_, _X_,        KC_F11, KC_F12, _X_, _X_, _X_,

    _X_, _X_, _X_,                            _X_, _X_, _X_
  )

  // [LAYER_3_TAP] = LAYOUT_gergoplex(
  //   KC_F1, KC_F2,    KC_F3, KC_F4,   KC_F5,       KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10,
  //   _X_,   KC_TILDE, _X_,   KC_LWIN, KC_F11,      KC_F12, KC_TAB, KC_GRAVE, _X_, _X_,
  //   _X_,   _X_,      _X_,   _X_,     _X_,         _X_,    _X_,    _X_, _X_, _X_,

  //   _T_, _X_, KC_LCTRL,                           KC_LSFT, KC_LALT, _T_
  // ),

  // [LAYER_4] = LAYOUT_gergoplex(
  //   _X_, _X_,         KC_UP,      _X_,          _X_,        _X_, _X_, _X_, _X_, _X_,
  //   _X_, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,  _X_,        _X_, _X_, _X_, _X_, _X_,
  //   _X_, _X_,         _X_,        _X_,          _X_,        _X_, _X_, _X_, _X_, _X_,

  //   _X_, _X_, _X_,                                          _X_, _X_, _T_
  // ),

  /*
  [LAYER_4] = LAYOUT_gergoplex(
    _X_, _X_, _X_, _X_, _X_,        _X_, _X_, _X_, _X_, _X_,
    _X_, _X_, _X_, _X_, _X_,        _X_, _X_, _X_, _X_, _X_,
    _X_, _X_, _X_, _X_, _X_,        _X_, _X_, _X_, _X_, _X_,

    _X_, _X_, _X_,                            _X_, _X_, _T_
  ),
  */
};
