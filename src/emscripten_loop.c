/*
 * Emscripten browser main loop: one frame per requestAnimationFrame callback.
 */

#include "emscripten_loop.h"

#include "control_loop.h"
#include "display.h"
#include "game_loop.h"
#include "logging.h"

#include <emscripten.h>
#include <stdbool.h>
#include <stdio.h>

#define printf ab3d_log_printf

extern void tear_down_game(GameState *state);

static GameState *g_em_st;

typedef enum {
    EM_TEXT_FADE_IN,
    EM_PREP,
    EM_TEXT_WAIT,
    EM_TEXT_FADE_OUT,
    EM_TEXT_CLEAR,
    EM_GAME,
    EM_AFTER,
    EM_OUTER_POST
} EmPhase;

static EmPhase g_em_phase = EM_PREP;
static bool g_em_copper_ready;
static GameLoopCtx g_em_gl_ctx;
static bool g_em_show_level_text;
static int g_em_text_step;
/* 0 = run begin, 1 = fading music, 2 = run finish */
static int g_em_outer_sub;

static void em_begin_level_phase(GameState *st)
{
    g_em_show_level_text = play_the_game_should_show_level_text(st) ? true : false;
    g_em_text_step = 0;
    g_em_phase = g_em_show_level_text ? EM_TEXT_FADE_IN : EM_PREP;
}

static void em_frame(void)
{
    GameState *st = g_em_st;

    switch (g_em_phase) {
    case EM_TEXT_FADE_IN:
        play_the_game_present_level_text(st,
            play_the_game_level_text_alpha_for_step(g_em_text_step));
        g_em_text_step++;
        if (g_em_text_step >= play_the_game_level_text_fade_steps()) {
            g_em_phase = EM_PREP;
        }
        return;
    case EM_PREP:
        play_the_game_prepare_level(st, &g_em_copper_ready);
        if (g_em_show_level_text) {
            if (play_the_game_drain_level_text_input(st) < 0) {
                st->running = false;
                st->finished_level = 0;
                g_em_phase = EM_AFTER;
            } else {
                g_em_phase = EM_TEXT_WAIT;
            }
        } else {
            game_loop_ctx_init(&g_em_gl_ctx, st);
            g_em_phase = EM_GAME;
        }
        return;
    case EM_TEXT_WAIT:
    {
        play_the_game_present_level_text(st, 255);
        int input = play_the_game_poll_level_text_input(st);
        if (input < 0) {
            st->running = false;
            st->finished_level = 0;
            g_em_phase = EM_AFTER;
        } else if (input > 0) {
            g_em_text_step = play_the_game_level_text_fade_steps() - 1;
            g_em_phase = EM_TEXT_FADE_OUT;
        }
        return;
    }
    case EM_TEXT_FADE_OUT:
        play_the_game_present_level_text(st,
            play_the_game_level_text_alpha_for_step(g_em_text_step));
        g_em_text_step--;
        if (g_em_text_step < 0) {
            play_the_game_clear_level_text(st);
            g_em_phase = EM_TEXT_CLEAR;
        }
        return;
    case EM_TEXT_CLEAR:
        display_present_text_screen_alpha(0);
        game_loop_ctx_init(&g_em_gl_ctx, st);
        g_em_gl_ctx.hidden_present_frames = 2;
        g_em_phase = EM_GAME;
        return;
    case EM_GAME:
        game_loop_tick(st, &g_em_gl_ctx);
        if (!st->running) g_em_phase = EM_AFTER;
        return;
    case EM_AFTER:
        if (play_the_game_after_game_loop(st)) {
            em_begin_level_phase(st);
        } else {
            play_the_game_finalize_session(st);
            g_em_phase = EM_OUTER_POST;
        }
        return;
    case EM_OUTER_POST:
        if (g_em_outer_sub == 0) {
            int need_fade = play_game_outer_emscripten_begin(st);
            g_em_outer_sub = need_fade ? 1 : 2;
            if (g_em_outer_sub == 1)
                return;
        }
        if (g_em_outer_sub == 1) {
            if (!play_game_outer_emscripten_fade_frame(st))
                return;
            g_em_outer_sub = 2;
        }
        if (g_em_outer_sub == 2) {
            int cont = play_game_outer_emscripten_finish(st);
            g_em_outer_sub = 0;
            if (cont) {
                g_em_copper_ready = false;
                em_begin_level_phase(st);
            } else {
                display_release_panel_memory();
                printf("[CONTROL] PlayGame finished\n");
                tear_down_game(st);
                printf("\n=== Exit (code 0) ===\n");
                ab3d_log_shutdown();
                emscripten_cancel_main_loop();
            }
        }
        return;
    default:
        return;
    }
}

void emscripten_run_game(GameState *state)
{
    play_game_load_shared_assets(state);
    g_em_st = state;
    g_em_copper_ready = false;
    g_em_show_level_text = false;
    g_em_text_step = 0;
    g_em_outer_sub = 0;
    em_begin_level_phase(state);
    emscripten_set_main_loop(em_frame, 0, 1);
}
