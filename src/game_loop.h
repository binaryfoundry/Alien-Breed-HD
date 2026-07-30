/*
 * Alien Breed 3D I - PC Port
 * game_loop.h - Main per-frame game loop
 *
 * Translated from: AB3DI.s mainLoop (~line 1296)
 *
 * Each frame:
 *   1. Handle pause
 *   2. Wait for vblank (frame sync)
 *   3. Swap screen buffers
 *   4. Handle gun selection / ammo display
 *   5. Animate water
 *   6. Save old positions
 *   7. Multiplayer sync (or single player cheat check)
 *   8. Player control (PLR1_Control / PLR2_Control)
 *   9. Zone brightness updates
 *  10. Visibility checks (multi)
 *  11. Object movement/animation (ObjMoveAnim)
 *  12. Energy/ammo bars
 *  13. Draw display (rendering pipeline)
 *  14. Copy copper buffer
 *  15. Object worry flags
 *  16. Check quit/death/level-end conditions
 *  17. Loop back to 1
 */

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "game_state.h"
#include "player.h"

#include <SDL.h>

typedef enum GameLoopFrontMenuResult {
    GAME_LOOP_FRONT_MENU_NONE = 0,
    GAME_LOOP_FRONT_MENU_NEW_GAME,
    GAME_LOOP_FRONT_MENU_LOAD_AUTOSAVE,
    GAME_LOOP_FRONT_MENU_EXIT
} GameLoopFrontMenuResult;

/* Persistent state for one in-level session (VBlank accums, FPS meter, etc.) */
typedef struct GameLoopCtx {
    int frame_count;
    int logic_count;
    Uint32 last_ticks;
    int pending_vblanks;
    Uint32 vblank_remainder_ms;
    Uint64 fps_sample_start_counter;
    int fps_frames_in_sample;
    int ingame_menu_open;
    int ingame_menu_frontend;
    int ingame_menu_result;
    int front_menu_music_started;
    int ingame_menu_screen;
    int ingame_menu_selected;
    int ingame_menu_autosave_count;
    int ingame_menu_autosave_selected_slot;
    int ingame_menu_autosave_available[PLAYER_AUTOSAVE_SLOT_COUNT];
    int16_t ingame_menu_autosave_level[PLAYER_AUTOSAVE_SLOT_COUNT];
    char ingame_menu_autosave_timestamp[PLAYER_AUTOSAVE_SLOT_COUNT][32];
    int hidden_present_frames;
} GameLoopCtx;

void game_loop_ctx_init(GameLoopCtx *ctx, GameState *state);
void game_loop_tick(GameState *state, GameLoopCtx *ctx);
void game_loop_front_menu_init(GameLoopCtx *ctx, GameState *state);
int game_loop_front_menu_tick(GameState *state, GameLoopCtx *ctx);

/* Run the main game loop until level ends, player dies, or quit */
void game_loop(GameState *state);
void game_loop_with_hidden_start_frames(GameState *state, int hidden_frames);

#endif /* GAME_LOOP_H */
