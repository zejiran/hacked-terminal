#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_20_242_255,
  HSV_129_226_172,
  HSV_0_255_255,
  HSV_215_255_128,
  ST_MACRO_0,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                                          TG(2),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,       
    TG(3),          KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_LBRACKET,                                    KC_RBRACKET,    KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_BSLASH,      
    KC_BSPACE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_D,           KC_QUOTE,                                                                       KC_MINUS,       KC_H,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TAB,         
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_K,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,        
    TD(DANCE_0),    TD(DANCE_1),    KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_ESCAPE,                                                                                                      KC_RCTRL,       KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       TD(DANCE_2),    
    KC_SPACE,       KC_RALT,        KC_LGUI,                        LSFT(KC_LGUI),  LSFT(KC_RCTRL), KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_N,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_LALT,        KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,                                          KC_TRANSPARENT, KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         RESET,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          RGB_SAD,        RGB_SAI,        HSV_20_242_255, HSV_129_226_172,HSV_0_255_255,  HSV_215_255_128,KC_NO,          
    KC_NO,          ST_MACRO_0,     LGUI(LSFT(KC_5)),KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          RGB_SPD,        RGB_SPI,        RGB_HUD,        RGB_HUI,        RGB_MOD,        TOGGLE_LAYER_COLOR,KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          WEBUSB_PAIR,    RGB_VAD,        RGB_VAI,        RGB_SLD,        RGB_TOG,        MOON_LED_LEVEL, 
    DYN_REC_START1, DYN_MACRO_PLAY1,DYN_REC_STOP,   DYN_REC_START2, DYN_MACRO_PLAY2,KC_SYSTEM_SLEEP,                                                                                                KC_PGUP,        MU_TOG,         MU_MOD,         AU_TOG,         KC_NO,          KC_NO,          
    KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_POWER,                       KC_DELETE,      KC_INSERT,      KC_PGDOWN
  ),
  [3] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TO(1),                                          TO(2),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,       
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_LBRACKET,                                    KC_RBRACKET,    KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_BSLASH,      
    KC_BSPACE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_D,           KC_QUOTE,                                                                       KC_MINUS,       KC_H,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TAB,         
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_K,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,        
    TD(DANCE_3),    TD(DANCE_4),    KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_ESCAPE,                                                                                                      KC_RCTRL,       KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       TD(DANCE_6),    
    KC_SPACE,       TD(DANCE_5),    KC_RGUI,                        LSFT(KC_RGUI),  KC_RALT,        TD(DANCE_7)
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {10,225,255}, {197,46,255}, {253,255,255}, {46,235,255}, {158,255,213}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {158,255,213}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {158,255,213}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {116,250,163}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {116,250,163}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {197,46,255}, {10,225,255}, {10,225,255}, {85,255,255}, {122,172,235}, {15,97,236}, {255,192,248}, {10,225,255}, {10,225,255}, {85,255,255}, {46,235,255}, {0,205,155}, {240,248,250}, {10,225,255}, {185,120,255}, {10,225,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {10,225,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {10,225,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {199,61,244}, {10,225,255}, {10,225,255}, {85,255,255}, {31,255,255}, {15,97,236}, {37,255,255} },

    [1] = { {195,61,255}, {0,0,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {19,255,255}, {205,255,255}, {14,255,255}, {195,61,255}, {195,61,255}, {205,255,255}, {205,255,255}, {14,255,255}, {195,61,255}, {195,61,255}, {14,255,255}, {205,255,255}, {19,255,255}, {195,61,255}, {195,61,255}, {14,255,255}, {19,255,255}, {14,255,255}, {195,61,255}, {195,61,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {0,0,255}, {195,61,255}, {14,255,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {19,255,255}, {14,255,255}, {195,61,255}, {195,61,255}, {195,61,255}, {14,255,255}, {14,255,255}, {195,61,255}, {195,61,255}, {195,61,255}, {14,255,255}, {14,255,255}, {19,255,255}, {195,61,255}, {195,61,255}, {14,255,255}, {14,255,255}, {14,255,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255}, {195,61,255} },

    [2] = { {191,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,174}, {191,222,234}, {0,0,0}, {169,120,255}, {0,0,0}, {75,211,182}, {191,222,234}, {0,0,0}, {169,120,255}, {0,0,0}, {146,224,255}, {191,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,205,174}, {191,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {75,211,182}, {191,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {191,222,234}, {0,0,0}, {0,0,0}, {146,224,255}, {146,224,255}, {0,204,255}, {199,255,255}, {48,240,255}, {0,0,0}, {0,0,0}, {132,255,167}, {0,0,0}, {191,222,234}, {205,255,255}, {75,211,182}, {0,0,255}, {0,0,0}, {191,222,234}, {0,151,250}, {33,255,255}, {33,255,255}, {0,183,238}, {191,222,234}, {116,225,167}, {0,255,255}, {141,255,233}, {0,183,238}, {191,222,234}, {16,245,255}, {0,255,255}, {141,255,233}, {0,183,238}, {191,222,234}, {0,255,255}, {75,211,182}, {169,120,255}, {146,255,167}, {0,255,255}, {75,211,182}, {12,225,241}, {194,176,255}, {194,176,255}, {12,225,241} },

    [3] = { {10,225,255}, {197,46,255}, {253,255,255}, {46,235,255}, {158,255,213}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {158,255,213}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {158,255,213}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {116,250,163}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {116,250,163}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {197,46,255}, {10,225,255}, {10,225,255}, {85,255,255}, {122,172,235}, {37,255,255}, {255,192,248}, {10,225,255}, {10,225,255}, {85,255,255}, {46,235,255}, {0,205,155}, {240,248,250}, {10,225,255}, {185,120,255}, {10,225,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {10,225,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {10,225,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {250,159,255}, {240,248,250}, {185,120,255}, {185,120,255}, {185,120,255}, {199,61,244}, {10,225,255}, {10,225,255}, {85,255,255}, {37,255,255}, {37,255,255}, {37,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_L)))));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_20_242_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(20,242,255);
      }
      return false;
    case HSV_129_226_172:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(129,226,172);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_215_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,128);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[8];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_HOME);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HOME); register_code16(KC_HOME);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HOME); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_E));
        tap_code16(LALT(KC_E));
        tap_code16(LALT(KC_E));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_E));
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(LALT(KC_E)); break;
        case SINGLE_HOLD: register_code16(LALT(KC_N)); break;
        case DOUBLE_TAP: register_code16(LALT(KC_E)); register_code16(LALT(KC_E)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_E)); register_code16(LALT(KC_E));
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_E)); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_E)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_E)); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_HOME);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HOME); register_code16(KC_HOME);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HOME); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[7].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
};

