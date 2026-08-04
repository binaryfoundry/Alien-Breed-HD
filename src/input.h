/*
 * Alien Breed 3D I - PC Port
 * input.h - SDL2 input backend
 *
 * Implements keyboard/mouse/joystick handling via SDL2 for the PC port.
 */

#ifndef INPUT_H
#define INPUT_H

#include "game_types.h"
#include <stdint.h>
#include <stdbool.h>

/* Lifecycle */
void input_init(void);
void input_shutdown(void);

/* Per-frame polling */
void input_update(uint8_t *key_map, uint8_t *last_pressed);
bool input_quit_requested(void);

/* Mouse */
typedef struct {
    int16_t dx;
    int16_t dy;
    int16_t wheel_y;
    bool    left_button;
    bool    right_button;
} MouseState;

void input_read_mouse(MouseState *out);
void input_consume_mouse_deltas(void);

typedef struct {
    int     x;
    int     y;
    int16_t wheel_y;
    bool    valid;
    bool    moved;
    bool    left_pressed;
    bool    right_pressed;
} MenuMouseState;

void input_set_menu_mouse_active(bool active, uint8_t *key_map);
void input_read_menu_mouse(MenuMouseState *out);
void input_consume_menu_mouse_events(void);

/* Joystick */
typedef struct {
    int16_t dx;
    int16_t dy;
    bool    fire;
} JoyState;

void input_read_joy1(JoyState *out);
void input_read_joy2(JoyState *out);

/* Gamepad one-shot actions (queued between display frames and consumed on logic ticks). */
bool input_gamepad_fire_held(void);
bool input_gamepad_duck_toggle_requested(void);
int16_t input_consume_gamepad_weapon_cycle_steps(void);

/* Keyboard one-shot key-down actions latched between display frames and logic ticks. */
bool input_consume_key_press(uint8_t keycode);

/* Convenience: check if a specific key is pressed */
bool input_key_pressed(const uint8_t *key_map, uint8_t keycode);

/* Clear keyboard state */
void input_clear_keyboard(uint8_t *key_map);

/* F5 quicksave request. Returns true once when F5 was pressed. */
bool input_f5_save_requested(void);
/* F9 quickload request. Returns true once when F9 was pressed. */
bool input_f9_load_requested(void);
bool input_f6_gouraud_visualize_requested(void);
bool input_f7_spill_visualize_requested(void);
/* F2: log center-pick debug info (once per key press). */
bool input_f2_pick_log_requested(void);
/* Tab: toggle automap overlay (once per key press). */
bool input_automap_toggle_requested(void);
/* PgUp/PgDn: automap zoom (once per key press). */
bool input_automap_pgup_requested(void);
bool input_automap_pgdn_requested(void);
/* F12 (and F11): toggle fullscreen desktop (once per key press). */
bool input_fullscreen_toggle_requested(void);

#endif /* INPUT_H */
