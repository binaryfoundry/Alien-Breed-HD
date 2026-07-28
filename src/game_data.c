/*
 * Alien Breed 3D I - PC Port
 * game_data.c - All game data tables translated from assembly
 *
 * Translated from: AB3DI.s, ObjectMove.s, Anims.s, PlayerShoot.s,
 *                  NormalAlien.s, Robot.s, BigRedThing.s, HalfWorm.s,
 *                  FlameMarine.s, ToughMarine.s, MutantMarine.s,
 *                  BigUglyAlien.s, BigClaws.s, FlyingScalyBall.s, Tree.s
 */

#include "game_data.h"
#include <stddef.h>

/* -----------------------------------------------------------------------
 * Gun data for Player 1
 * Translated from AB3DI.s PLR1_GunData (line ~2696-2822)
 *
 * Gun 0: Pistol (instant hit, 1 pellet)
 * Gun 1: Plasma Gun (projectile)
 * Gun 2: Rocket Launcher (projectile, explosive)
 * Gun 3: Flamethrower (projectile, rapid fire)
 * Gun 4: Grenade Launcher (projectile, arc, explosive)
 * Gun 5: (unused - worm gun)
 * Gun 6: (unused - tough marine gun)
 * Gun 7: Shotgun (instant hit, 7 pellets)
 * ----------------------------------------------------------------------- */
const GunDataEntry default_plr1_guns[8] = {
    /* Gun 0: Pistol */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 8,
        .gun_sample     = 3,
        .ammo_in_clip   = 15,
        .fire_bullet    = -1,     /* instant hit */
        .shot_power     = 4,
        .got_gun        = -1,     /* 0xFF = has gun */
        .fire_delay     = 5,
        .bullet_lifetime = -1,
        .click_or_hold  = 1,
        .bullet_speed   = 0,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 1,
    },
    /* Gun 1: Plasma Gun */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 8,
        .gun_sample     = 1,
        .ammo_in_clip   = 20,
        .fire_bullet    = 0,      /* projectile */
        .shot_power     = 16,
        .got_gun        = 0,
        .fire_delay     = 10,
        .bullet_lifetime = -1,
        .click_or_hold  = 0,
        .bullet_speed   = 5,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 1,
    },
    /* Gun 2: Rocket Launcher */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 8,
        .gun_sample     = 9,
        .ammo_in_clip   = 2,
        .fire_bullet    = 0,
        .shot_power     = 12,
        .got_gun        = 0,
        .fire_delay     = 30,
        .bullet_lifetime = -1,
        .click_or_hold  = 0,
        .bullet_speed   = 5,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 1,
    },
    /* Gun 3: Flamethrower */
    {
        .ammo_left      = 90 * 8,
        .ammo_per_shot  = 1,
        .gun_sample     = 22,
        .ammo_in_clip   = 40,
        .fire_bullet    = 0,
        .shot_power     = 8,
        .got_gun        = 0,
        .fire_delay     = 5,
        .bullet_lifetime = 50,
        .click_or_hold  = 1,
        .bullet_speed   = 4,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 1,
    },
    /* Gun 4: Grenade Launcher */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 8,
        .gun_sample     = 9,
        .ammo_in_clip   = 6,
        .fire_bullet    = 0,
        .shot_power     = 8,
        .got_gun        = 0,
        .fire_delay     = 50,
        .bullet_lifetime = 100,
        .click_or_hold  = 1,
        .bullet_speed   = 5,
        .shot_gravity   = 60,
        .shot_flags     = 3,
        .bullet_y_offset = -1000,
        .bullet_count   = 1,
    },
    /* Gun 5: Worm Gun (unused) */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 0,
        .gun_sample     = 0,
        .ammo_in_clip   = 0,
        .fire_bullet    = 0,
        .shot_power     = 0,
        .got_gun        = 0,
        .fire_delay     = 0,
        .bullet_lifetime = -1,
        .click_or_hold  = 0,
        .bullet_speed   = 5,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 1,
    },
    /* Gun 6: Tough Marine Gun (unused) */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 0,
        .gun_sample     = 0,
        .ammo_in_clip   = 0,
        .fire_bullet    = 0,
        .shot_power     = 0,
        .got_gun        = 0,
        .fire_delay     = 0,
        .bullet_lifetime = -1,
        .click_or_hold  = 0,
        .bullet_speed   = 5,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 1,
    },
    /* Gun 7: Shotgun */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 8,
        .gun_sample     = 21,
        .ammo_in_clip   = 15,
        .fire_bullet    = -1,     /* instant hit */
        .shot_power     = 4,
        .got_gun        = 0,
        .fire_delay     = 50,
        .bullet_lifetime = -1,
        .click_or_hold  = 1,
        .bullet_speed   = 0,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 7,
    },
};

/* Player 2 gun data is identical to Player 1 */
const GunDataEntry default_plr2_guns[8] = {
    /* Gun 0: Pistol */
    {
        .ammo_left      = 0,
        .ammo_per_shot  = 8,
        .gun_sample     = 3,
        .ammo_in_clip   = 15,
        .fire_bullet    = -1,
        .shot_power     = 4,
        .got_gun        = -1,
        .fire_delay     = 5,
        .bullet_lifetime = -1,
        .click_or_hold  = 1,
        .bullet_speed   = 0,
        .shot_gravity   = 0,
        .shot_flags     = 0,
        .bullet_y_offset = 0,
        .bullet_count   = 1,
    },
    /* Gun 1-7 same as P1 */
    { 0, 8, 1, 20, 0, 16, 0, 10, -1, 0, 5, 0, 0, 0, 1, {0} },
    { 0, 8, 9, 2,  0, 12, 0, 30, -1, 0, 5, 0, 0, 0, 1, {0} },
    { 90*8, 1, 22, 40, 0, 8, 0, 5, 50, 1, 4, 0, 0, 0, 1, {0} },
    { 0, 8, 9, 6, 0, 8, 0, 50, 100, 1, 5, 60, 3, -1000, 1, {0} },
    { 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 5, 0, 0, 0, 1, {0} },
    { 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 5, 0, 0, 0, 1, {0} },
    { 0, 8, 21, 15, -1, 4, 0, 50, -1, 1, 0, 0, 0, 0, 7, {0} },
};

const char *gun_names[8] = {
    "Pistol",
    "Plasma Gun",
    "Rocket Launcher",
    "Flamethrower",
    "Grenade Launcher",
    "(Worm Gun)",
    "(Marine Gun)",
    "Shotgun",
};

/* -----------------------------------------------------------------------
 * Gun animation frames
 * Translated from AB3DI.s MachineAnim, PlasmaAnim, etc. (line ~2674-2688)
 * ----------------------------------------------------------------------- */
const GunAnim gun_anims[8] = {
    /* Gun 0: Pistol - MachineAnim */
    { .frames = {0, 1, 2, 3}, .num_frames = 3 },
    /* Gun 1: Plasma - PlasmaAnim */
    { .frames = {0, 1, 2, 3, 3, 3}, .num_frames = 5 },
    /* Gun 2: Rocket - RocketAnim */
    { .frames = {0, 1, 2, 3, 3, 3}, .num_frames = 5 },
    /* Gun 3: Flamethrower - FlameThrowerAnim */
    { .frames = {0, 1, 2, 3, 3, 3}, .num_frames = 5 },
    /* Gun 4: Grenade - GrenadeAnim */
    { .frames = {0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3}, .num_frames = 12 },
    /* Gun 5: unused */
    { .frames = {0}, .num_frames = 0 },
    /* Gun 6: unused */
    { .frames = {0}, .num_frames = 0 },
    /* Gun 7: Shotgun - ShotGunAnim (0, 12x2, 19x1, 11x2, 20x0, 3) */
    { .frames = {
        0,
        2,2,2,2,2,2,2,2,2,2,2,2,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,2,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        3
    }, .num_frames = 63 },
};

/* -----------------------------------------------------------------------
 * Collision box table
 * Translated from ObjectMove.s ColBoxTable (line ~1949-1992)
 *
 * 4 words: width, half_height, full_height, 0
 * ----------------------------------------------------------------------- */
const CollisionBox col_box_table[21] = {
    /*  0: red scurrying alien  */ { 40,  60, 120, 0 },
    /*  1: Medipack              */ { 40,  20,  40, 0 },
    /*  2: Bullet                */ { 40,  20,  40, 0 },
    /*  3: Gun                   */ { 40,  20,  40, 0 },
    /*  4: Key                   */ { 40,  20,  40, 0 },
    /*  5: Player1               */ { 40,  40,  80, 0 },
    /*  6: Robot                 */ { 40,  50, 100, 0 },
    /*  7: ?                     */ { 40,  20,  40, 0 },
    /*  8: Flying Nasty          */ { 80,  60, 120, 0 },
    /*  9: Ammo                  */ { 40,  20,  40, 0 },
    /* 10: Barrel (+45% height vs Amiga ColBox for port) */ { 40,  44,  87, 0 },
    /* 11: Player2               */ { 40,  40,  80, 0 },
    /* 12: Mutant Marine          */ { 40,  40,  80, 0 },
    /* 13: Worm                  */ { 80,  60, 120, 0 },
    /* 14: Huge red thing        */ {160, 100, 200, 0 },
    /* 15: Small red thing       */ { 80,  50, 100, 0 },
    /* 16: Tree                  */ { 80,  60, 120, 0 },
    /* 17: Eye ball              */ { 40,  30,  60, 0 },
    /* 18: Tough Marine           */ { 40,  40,  80, 0 },
    /* 19: Shot Gun Marine        */ { 40,  40,  80, 0 },
    /* 20: Gas pipe              */ { 40,  30,  60, 0 },
};

/* -----------------------------------------------------------------------
 * Default world width/height per object type (obj[6], obj[7]).
 * From Amiga .s: Tree 128*256+128, HalfWorm 90*256+100, FlyingScalyBall #$6060, etc.
 * ----------------------------------------------------------------------- */
const ObjectWorldSize default_object_world_size[21] = {
    /*  0 alien       */ { 32,  32 },
    /*  1 Medipack    */ { 20,  20 },
    /*  2 Bullet      */ { 16,  16 },
    /*  3 Gun         */ { 40,  40 },
    /*  4 Key         */ { 20,  20 },
    /*  5 Player1     */ { 40,  40 },
    /*  6 Robot       */ { 32,  32 },
    /*  7 Big Nasty   */ { 80,  80 },
    /*  8 Flying Nasty*/ { 96,  96 },
    /*  9 Ammo        */ { 16,  16 },
    /* 10 Barrel      */ { 48,  50 },
    /* 11 Player2     */ { 40,  40 },
    /* 12 Mutant Marine */ { 32,  32 },
    /* 13 Worm        */ { 90, 100 },
    /* 14 Huge red    */ {128, 128},
    /* 15 Small red   */ {128, 128},
    /* 16 Tree        */ {128, 128},
    /* 17 Eye ball    */ { 16,  32 },
    /* 18 Tough Marine*/ { 69,  69 },
    /* 19 Flame Marine*/ { 69,  69 },
    /* 20 Gas pipe    */ { 40,  60 },
};

/* -----------------------------------------------------------------------
 * Bullet type data
 * Translated from Anims.s BulletSizes, HitNoises, ExplosiveForce
 * ----------------------------------------------------------------------- */
const BulletTypeData bullet_types[8] = {
    /* Type 0: Plasma bolt    */ { 0x10, 0x10,   0,  -1,   0 },
    /* Type 1: Plasma bolt2   */ { 0x10, 0x10,   0,  -1,   0 },
    /* Type 2: Rocket         */ { 0x10, 0x10,  64,  15, 200 },
    /* Type 3: Flame          */ { 0x20, 0x20,   0,  -1,   0 },
    /* Type 4: Grenade        */ { 0x08, 0x08,  40,  15, 200 },
    /* Type 5: Worm spit      */ { 0x10, 0x10,   0,  -1,   0 },
    /* Type 6: Marine shot    */ { 0x10, 0x10,   0,  -1,   0 },
    /* Type 7: Big shot       */ { 0x08, 0x08,   0,  -1,   0 },
};

/* -----------------------------------------------------------------------
 * Bullet animation tables
 * Translated from Anims.s Bul1Anim, Bul2Anim, RockAnim, FlameAnim,
 * grenAnim, Bul4Anim, Bul5Anim.
 * BulletTypes[n] = { anim_ptr, pop_ptr }.
 * ----------------------------------------------------------------------- */

/* Bul1Anim: gun 0 (unused - pistol is instant-hit) and gun 7 */
static const BulletAnimFrame anim_bul1[] = {
    { 20, 15,  6,  8, 0 },
    { 17, 17,  6,  9, 0 },
    { 15, 20,  6, 10, 0 },
    { 17, 17,  6, 11, 0 },
    { .width = -1 }
};

/* Bul2Anim: gun 1 (plasma gun) - uses vect 2 (bigbullet), frames 0-7 */
static const BulletAnimFrame anim_bul2[] = {
    { 25, 25,  2,  0, 0 },
    { 25, 25,  2,  1, 0 },
    { 25, 25,  2,  2, 0 },
    { 25, 25,  2,  3, 0 },
    { 25, 25,  2,  4, 0 },
    { 25, 25,  2,  5, 0 },
    { 25, 25,  2,  6, 0 },
    { 25, 25,  2,  7, 0 },
    { .width = -1 }
};

/* RockAnim: gun 2 (rocket) - uses vect 6 (rockets), frames 0-3 */
static const BulletAnimFrame anim_rock[] = {
    { 16, 16,  6,  0, 0 },
    { 16, 16,  6,  1, 0 },
    { 16, 16,  6,  2, 0 },
    { 16, 16,  6,  3, 0 },
    { .width = -1 }
};

/* FlameAnim: gun 3 (flamethrower) - uses vect 8, full 18-frame growth sequence. */
static const BulletAnimFrame anim_flame[] = {
    {  5,  5,  8, 0, 0 },
    {  9,  9,  8, 1, 0 },
    { 13, 13,  8, 2, 0 },
    { 17, 17,  8, 3, 0 },
    { 21, 21,  8, 4, 0 },
    { 25, 25,  8, 4, 0 },
    { 29, 29,  8, 5, 0 },
    { 33, 33,  8, 5, 0 },
    { 37, 37,  8, 5, 0 },
    { 41, 41,  8, 6, 0 },
    { 45, 45,  8, 6, 0 },
    { 49, 49,  8, 6, 0 },
    { 55, 55,  8, 7, 0 },
    { 63, 63,  8, 7, 0 },
    { 71, 71,  8, 7, 0 },
    { 79, 79,  8, 7, 0 },
    { 87, 87,  8, 8, 0 },
    { 95, 95,  8, 8, 0 },
    { 103,103,  8, 8, 0 },
    { .width = -1 }
};

/* grenAnim: gun 4 (grenade) - uses vect 1 (alien sheet), frames 21-24 */
static const BulletAnimFrame anim_gren[] = {
    { 25, 25,  1, 21, 0 },
    { 25, 25,  1, 22, 0 },
    { 25, 25,  1, 23, 0 },
    { 25, 25,  1, 24, 0 },
    { .width = -1 }
};

/* Bul4Anim: gun 5 (worm spit) - uses vect 6, frames 4-7 */
static const BulletAnimFrame anim_bul4[] = {
    { 25, 25,  6,  4, 0 },
    { 25, 25,  6,  5, 0 },
    { 25, 25,  6,  6, 0 },
    { 25, 25,  6,  7, 0 },
    { .width = -1 }
};

/* Bul5Anim: gun 6 (marine shot) - uses vect 6, frames 4-7, small */
static const BulletAnimFrame anim_bul5[] = {
    { 10, 10,  6,  4, 0 },
    { 10, 10,  6,  5, 0 },
    { 10, 10,  6,  6, 0 },
    { 10, 10,  6,  7, 0 },
    { .width = -1 }
};

/* Explode anim tables: used by gibs (SHOT_SIZE 50-53).
 * All use vect=0 (alien sprite sheet), gib frames 16-31.
 * From Anims.s Explode1Anim..Explode4Anim. */
static const BulletAnimFrame anim_explode1[] = {
    { 25, 25,  0, 16, 0 },
    { 25, 25,  0, 17, 0 },
    { 25, 25,  0, 18, 0 },
    { 25, 25,  0, 19, 0 },
    { .width = -1 }
};
static const BulletAnimFrame anim_explode2[] = {
    { 20, 20,  0, 20, 0 },
    { 20, 20,  0, 21, 0 },
    { 20, 20,  0, 22, 0 },
    { 20, 20,  0, 23, 0 },
    { .width = -1 }
};
static const BulletAnimFrame anim_explode3[] = {
    { 20, 20,  0, 24, 0 },
    { 20, 20,  0, 25, 0 },
    { 20, 20,  0, 26, 0 },
    { 20, 20,  0, 27, 0 },
    { .width = -1 }
};
static const BulletAnimFrame anim_explode4[] = {
    { 30, 30,  0, 28, 0 },
    { 30, 30,  0, 29, 0 },
    { 30, 30,  0, 30, 0 },
    { 30, 30,  0, 31, 0 },
    { .width = -1 }
};

/* -----------------------------------------------------------------------
 * Bullet pop tables (shotstatus != 0)
 * Translated from Anims.s Bul1Pop, Bul2Pop, RockPop, FlamePop,
 * Bul4Pop, Bul5Pop, Explode1Pop..Explode4Pop.
 * ----------------------------------------------------------------------- */

static const BulletAnimFrame pop_bul1[] = {
    { 25, 25, 1,  6,  0 },
    { 25, 25, 1,  7, -4 },
    { 25, 25, 1,  8, -4 },
    { 25, 25, 1,  9, -4 },
    { 25, 25, 1, 10, -4 },
    { 25, 25, 1, 11, -4 },
    { 25, 25, 1, 12, -4 },
    { 25, 25, 1, 13, -4 },
    { 25, 25, 1, 14, -4 },
    { 25, 25, 1, 15, -4 },
    { 25, 25, 1, 16, -4 },
    { .width = -1 }
};

static const BulletAnimFrame pop_bul2[] = {
    { 25, 25, 2,  8, -4 },
    { 29, 29, 2,  9, -4 },
    { 33, 33, 2, 10, -4 },
    { 37, 37, 2, 11, -4 },
    { 41, 41, 2, 12, -4 },
    { 45, 45, 2, 13, -4 },
    { 49, 49, 2, 14, -4 },
    { 53, 53, 2, 15, -4 },
    { 57, 57, 2, 16, -4 },
    { 61, 61, 2, 17, -4 },
    { 65, 65, 2, 18, -4 },
    { 69, 69, 2, 19, -4 },
    { .width = -1 }
};

static const BulletAnimFrame pop_rock[] = {
    { 100, 100, 8, 0, -4 },
    { 110, 110, 8, 1,  0 },
    { 120, 120, 8, 2, -4 },
    { 130, 130, 8, 3, -4 },
    { 140, 140, 8, 4, -4 },
    { 150, 150, 8, 4, -4 },
    { 160, 160, 8, 5, -4 },
    { 170, 170, 8, 5, -4 },
    { 180, 180, 8, 6, -4 },
    { 190, 190, 8, 6, -4 },
    { 200, 200, 8, 7, -4 },
    { 210, 210, 8, 7, -4 },
    { 220, 220, 8, 8, -4 },
    { 230, 230, 8, 8, -4 },
    { .width = -1 }
};

static const BulletAnimFrame pop_flame[] = {
    { 140, 140, 8, 7, 0 },
    { 144, 144, 8, 7, 0 },
    { 148, 148, 8, 7, 0 },
    { 152, 152, 8, 8, 0 },
    { 156, 156, 8, 8, 0 },
    { 160, 160, 8, 8, 0 },
    { .width = -1 }
};

static const BulletAnimFrame pop_bul4[] = {
    { 20, 20, 6, 4, 0 },
    { 15, 15, 6, 5, 0 },
    { 10, 10, 6, 6, 0 },
    {  5,  5, 6, 7, 0 },
    { .width = -1 }
};

static const BulletAnimFrame pop_bul5[] = {
    { 8, 8, 6, 4, 0 },
    { 6, 6, 6, 5, 0 },
    { 4, 4, 6, 6, 0 },
    { .width = -1 }
};

static const BulletAnimFrame pop_explode1[] = {
    { 20, 20, 0, 16, 1 },
    { 20, 20, 0, 16, 1 },
    { 20, 20, 0, 16, 1 },
    { 20, 20, 0, 16, 1 },
    { 20, 20, 0, 16, 1 },
    { 20, 20, 0, 16, 1 },
    { 20, 20, 0, 16, 1 },
    { 20, 20, 0, 16, 1 },
    { 17, 17, 0, 16, 1 },
    { 13, 13, 0, 16, 1 },
    {  9,  9, 0, 16, 1 },
    { .width = -1 }
};

static const BulletAnimFrame pop_explode2[] = {
    { 20, 20, 0, 20, 1 },
    { 20, 20, 0, 20, 1 },
    { 20, 20, 0, 20, 1 },
    { 20, 20, 0, 20, 1 },
    { 20, 20, 0, 20, 1 },
    { 20, 20, 0, 20, 1 },
    { 20, 20, 0, 20, 1 },
    { 20, 20, 0, 20, 1 },
    { 17, 17, 0, 20, 1 },
    { 13, 13, 0, 20, 1 },
    {  9,  9, 0, 20, 1 },
    { .width = -1 }
};

static const BulletAnimFrame pop_explode3[] = {
    { 17, 17, 0, 24, 1 },
    { 17, 17, 0, 24, 1 },
    { 17, 17, 0, 24, 1 },
    { 17, 17, 0, 24, 1 },
    { 17, 17, 0, 24, 1 },
    { 17, 17, 0, 24, 1 },
    { 17, 17, 0, 24, 1 },
    { 17, 17, 0, 24, 1 },
    { 13, 13, 0, 24, 1 },
    {  9,  9, 0, 24, 1 },
    { .width = -1 }
};

static const BulletAnimFrame pop_explode4[] = {
    { 20, 20, 0, 28, 0 },
    { 20, 20, 0, 28, 1 },
    { 20, 20, 0, 28, 1 },
    { 20, 20, 0, 28, 1 },
    { 20, 20, 0, 28, 1 },
    { 20, 20, 0, 28, 1 },
    { 20, 20, 0, 28, 1 },
    { 20, 20, 0, 28, 1 },
    { 17, 17, 0, 28, 1 },
    { 13, 13, 0, 28, 1 },
    {  9,  9, 0, 28, 1 },
    { .width = -1 }
};

/* Indexed by SHOT_SIZE.
 * Indices 0-7: player guns. Indices 8-49: NULL (unused). Indices 50-53: gibs. */
const BulletAnimFrame *const bullet_anim_tables[MAX_BULLET_ANIM_IDX] = {
    anim_bul1,     /* 0 */
    anim_bul2,     /* 1: plasma gun */
    anim_rock,     /* 2: rocket */
    anim_flame,    /* 3: flamethrower */
    anim_gren,     /* 4: grenade */
    anim_bul4,     /* 5: worm spit */
    anim_bul5,     /* 6: marine shot */
    anim_bul1,     /* 7 */
    /* 8-49: NULL */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 8-17 */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 18-27 */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 28-37 */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 38-47 */
    NULL,NULL,                                          /* 48-49 */
    anim_explode1, /* 50 */
    anim_explode2, /* 51 */
    anim_explode3, /* 52 */
    anim_explode4, /* 53 */
};

/* Indexed by SHOT_SIZE.
 * Indices 0-7: player guns. Indices 8-49: NULL (unused). Indices 50-53: gibs. */
const BulletAnimFrame *const bullet_pop_tables[MAX_BULLET_ANIM_IDX] = {
    pop_bul1,     /* 0 */
    pop_bul2,     /* 1: plasma gun */
    pop_rock,     /* 2: rocket */
    pop_flame,    /* 3: flamethrower */
    pop_rock,     /* 4: grenade */
    pop_bul4,     /* 5: worm spit */
    pop_bul5,     /* 6: marine shot */
    pop_bul1,     /* 7 */
    /* 8-49: NULL */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 8-17 */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 18-27 */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 28-37 */
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,  /* 38-47 */
    NULL,NULL,                                          /* 48-49 */
    pop_explode1, /* 50 */
    pop_explode2, /* 51 */
    pop_explode3, /* 52 */
    pop_explode4, /* 53 */
};

/* BulletSizes flying src cols/rows (obj[14]/obj[15]).
 * Indices 0-7: from Anims.s BulletSizes. Indices 8-53: 0 (default 32 in renderer). */
const uint8_t bullet_fly_src_cols[MAX_BULLET_ANIM_IDX] = {
    0x10,0x10,0x10,0x20,0x08,0x10,0x10,0x08,  /* 0-7 */
    /* 8-53: 0 (gibs and unused use renderer default of 32) */
};
const uint8_t bullet_fly_src_rows[MAX_BULLET_ANIM_IDX] = {
    0x10,0x10,0x10,0x20,0x08,0x10,0x10,0x08,  /* 0-7 */
};

/* BulletSizes pop src cols/rows (second word of each BulletSizes entry). */
const uint8_t bullet_pop_src_cols[MAX_BULLET_ANIM_IDX] = {
    0x08,0x10,0x20,0x20,0x20,0x10,0x10,0x08,  /* 0-7 */
};
const uint8_t bullet_pop_src_rows[MAX_BULLET_ANIM_IDX] = {
    0x08,0x10,0x20,0x20,0x20,0x10,0x10,0x08,  /* 0-7 */
};

/* -----------------------------------------------------------------------
 * Enemy type parameters
 * Consolidated from all enemy .s files
 *
 * death_frames: stored in display order (index 0 = first frame shown).
 * Amiga indexes .dyinganim by ThirdTimer which counts DOWN, so table is
 * reversed here to match (Amiga shows table[high] first, we show frames[0] first).
 *   [0] NormalAlien.s .dyinganim: dcb.w 11,33; dcb.w 15,32 -> display: 15×32, 11×33
 *   [1] Robot: no sequence (explodes)
 *   [2] BigRedThing.s: 10(a0) 0..9 (increment each tick)
 *   [3] HalfWorm.s .dyinganim: 6×20,10×19,10×18 -> display: 10×18,10×19,6×20
 *   [4] FlameMarine.s .dyinganim: 6×18,10×17,10×16 -> display: 10×16,10×17,6×18
 *   [5] ToughMarine.s same as FlameMarine
 *   [6] MutantMarine.s same as FlameMarine
 *   [7] BigUglyAlien.s: no sequence (deadframe only)
 *   [8] BigClaws.s: 10(a0) 0..9 like BigRedThing
 * ----------------------------------------------------------------------- */
const EnemyParams enemy_params[] = {
    /* [0] Normal Alien (NormalAlien.s ItsANasty) - Amiga: screamsound #0 = scream */
    {
        .thing_height   = 80 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 80,
        .awayfromwall   = 1,
        .nas_height     = 64,
        .melee_damage   = 2,
        .melee_cooldown = 20,
        .melee_range    = 160,
        .shot_type      = -1,       /* melee only */
        .shot_power     = 0,
        .shot_speed     = 0,
        .shot_shift     = 0,
        .shot_cooldown  = 0,
        .damage_shift   = 0,        /* direct subtraction */
        .min_damage_after_shift = 0,
        .explode_threshold = 40,
        .wander_timer   = 50,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 0,        /* scream (Amiga screamsound #0) */
        .scream_sound   = 0,        /* scream */
        .periodic_vocal1 = 17,      /* howl1 (NormalAlien.s SecTimer) */
        .periodic_vocal2 = 18,      /* howl2 */
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = -1,
        .damage_audio_class = ENEMY_DMG_AUDIO_ALIEN,
        .gib_splat_noisevol = 0,
        .death_frames   = {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
                           33,33,33,33,33,33,33,33,33,33,33, -1},
    },
    /* [1] Robot (Robot.s ItsARobot) */
    {
        .thing_height   = 160 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 160,
        .awayfromwall   = 2,
        .nas_height     = 128,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 0,
        .shot_type      = 4,        /* projectile type 4 */
        .shot_power     = 10,
        .shot_speed     = 16,
        .shot_shift     = 3,
        .shot_cooldown  = 50,
        .damage_shift   = 4,        /* asr.b #4 = divide by 16 */
        .min_damage_after_shift = 0, /* Robot.s: beq -> low hits can do 0 */
        .explode_threshold = 0,     /* always explodes on death */
        .wander_timer   = 100,
        .hiss_timer_min = 0,
        .hiss_timer_range = 0,
        .death_sound    = 15,
        .scream_sound   = 8,
        .periodic_vocal1 = -1,
        .periodic_vocal2 = -1,
        .periodic_vol_idle = 0,
        .periodic_vol_attack = 0,
        .attack_sound   = -1,
        .damage_audio_class = ENEMY_DMG_AUDIO_ROBOT,
        .gib_splat_noisevol = 0,
        .death_frames   = {-1},
    },
    /* [2] Big Red Thing (BigRedThing.s) - death: add.w #1,10(a0) 0..9 then onfloordead */
    {
        .thing_height   = 456 * 128,
        .step_up        = 40 * 256,
        .step_down      = 40 * 256,
        .extlen         = 160,
        .awayfromwall   = 2,
        .nas_height     = 128,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 80,
        .shot_type      = 2,        /* rocket-like */
        .shot_power     = 10,
        .shot_speed     = 32,
        .shot_shift     = 4,
        .shot_cooldown  = 30,
        .damage_shift   = 2,        /* divide by 4 */
        .min_damage_after_shift = 1, /* BigRedThing.s: asr.b #2; bne .notzero; move.b #1,d2 */
        .explode_threshold = 0,
        .wander_timer   = 150,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 27,
        .scream_sound   = 27,
        .periodic_vocal1 = 17,
        .periodic_vocal2 = 18,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = -1,
        .damage_audio_class = ENEMY_DMG_AUDIO_BIG_GIB,
        .gib_splat_noisevol = 0,
        .death_frames   = {0,1,2,3,4,5,6,7,8,9, -1},
    },
    /* [3] Half Worm (HalfWorm.s) */
    {
        .thing_height   = 200 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 80,
        .awayfromwall   = 1,
        .nas_height     = 64,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 80,
        .shot_type      = 5,        /* worm spit */
        .shot_power     = 10,
        .shot_speed     = 16,
        .shot_shift     = 3,
        .shot_cooldown  = 30,
        .damage_shift   = 2,        /* HalfWorm.s: asr.b #2 */
        .min_damage_after_shift = 1, /* HalfWorm.s: shift then force minimum 1 */
        .explode_threshold = 80,
        .wander_timer   = 50,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 27,
        .scream_sound   = 27,
        .periodic_vocal1 = 17,
        .periodic_vocal2 = 18,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = -1,
        .damage_audio_class = ENEMY_DMG_AUDIO_WORM,
        .gib_splat_noisevol = 300,
        .death_frames   = {18,18,18,18,18,18,18,18,18,18, 19,19,19,19,19,19,19,19,19,19,
                           20,20,20,20,20,20, -1},
    },
    /* [4] Flame Marine (FlameMarine.s) - screamsound #0; death: #14@400 if damage>1 then #0@200 if anim */
    {
        .thing_height   = 128 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 80,
        .awayfromwall   = 1,
        .nas_height     = 64,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 80,
        .shot_type      = 3,        /* flame projectile */
        .shot_power     = 7,
        .shot_speed     = 8,
        .shot_shift     = 2,
        .shot_cooldown  = 25,
        .damage_shift   = 0,
        .min_damage_after_shift = 0,
        .explode_threshold = 40,
        .wander_timer   = 50,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 14,       /* splatpop — marine death audio handled in enemy_check_damage */
        .scream_sound   = 0,        /* main scream (Amiga screamsound #0), hurt + death anim */
        .periodic_vocal1 = 17,
        .periodic_vocal2 = 18,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = 1,
        .damage_audio_class = ENEMY_DMG_AUDIO_UNUSED,
        .gib_splat_noisevol = 0,
        .death_frames   = {16,16,16,16,16,16,16,16,16,16, 17,17,17,17,17,17,17,17,17,17,
                           18,18,18,18,18,18, -1},
    },
    /* [5] Tough Marine (ToughMarine.s) - same damage SFX as FlameMarine */
    {
        .thing_height   = 128 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 80,
        .awayfromwall   = 1,
        .nas_height     = 64,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 80,
        .shot_type      = 6,        /* marine shot */
        .shot_power     = 7,
        .shot_speed     = 32,
        .shot_shift     = 4,
        .shot_cooldown  = 50,
        .damage_shift   = 0,
        .min_damage_after_shift = 0,
        .explode_threshold = 40,
        .wander_timer   = 50,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 14,
        .scream_sound   = 0,
        .periodic_vocal1 = 17,
        .periodic_vocal2 = 18,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = 1,        /* ToughMarine.s: Samplenum #1 on shot */
        .damage_audio_class = ENEMY_DMG_AUDIO_UNUSED,
        .gib_splat_noisevol = 0,
        .death_frames   = {16,16,16,16,16,16,16,16,16,16, 17,17,17,17,17,17,17,17,17,17,
                           18,18,18,18,18,18, -1},
    },
    /* [6] Mutant Marine (MutantMarine.s) - fires gun (Amiga: hitscan via ShootPlayer1;
     * marine_hitscan_projectiles can replace this with a fast plasma projectile).
     * Same scream #0 / splat #14 death pattern as other marines. */
    {
        .thing_height   = 128 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 80,
        .awayfromwall   = 1,
        .nas_height     = 64,
        .melee_damage   = 4,
        .melee_cooldown = 50,
        .melee_range    = 80,       /* also used as min range for shot */
        .shot_type      = 0,        /* plasma bolt (Amiga used hitscan, this is approx) */
        .shot_power     = 4,
        .shot_speed     = 32,       /* fast projectile */
        .shot_shift     = 2,
        .shot_cooldown  = 40,
        .damage_shift   = 0,
        .min_damage_after_shift = 0,
        .explode_threshold = 40,
        .wander_timer   = 50,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 14,
        .scream_sound   = 0,
        .periodic_vocal1 = 17,
        .periodic_vocal2 = 18,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = 3,
        .damage_audio_class = ENEMY_DMG_AUDIO_UNUSED,
        .gib_splat_noisevol = 0,
        .death_frames   = {16,16,16,16,16,16,16,16,16,16, 17,17,17,17,17,17,17,17,17,17,
                           18,18,18,18,18,18, -1},
    },
    /* [7] Big Ugly Alien (BigUglyAlien.s ItsABigNasty) */
    {
        .thing_height   = 50 * 256,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 80,
        .awayfromwall   = 1,
        .nas_height     = 64,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 80,
        .shot_type      = 1,        /* plasma bolt 2 */
        .shot_power     = 10,
        .shot_speed     = 16,
        .shot_shift     = 4,
        .shot_cooldown  = 50,
        .damage_shift   = 0,
        .min_damage_after_shift = 0,
        .explode_threshold = 0,
        .wander_timer   = 20,
        .hiss_timer_min = 0,
        .hiss_timer_range = 0,
        .death_sound    = 8,
        .scream_sound   = 8,
        .periodic_vocal1 = -1,
        .periodic_vocal2 = -1,
        .periodic_vol_idle = 0,
        .periodic_vol_attack = 0,
        .attack_sound   = -1,
        .damage_audio_class = ENEMY_DMG_AUDIO_BIGUGLY,
        .gib_splat_noisevol = 0,
        .death_frames   = {-1},
    },
    /* [8] Big Claws (BigClaws.s) - death: add.w #1,10(a0) 0..9 then onfloordead (same as BigRedThing) */
    {
        .thing_height   = 256 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 160,
        .awayfromwall   = 2,
        .nas_height     = 128,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 80,
        .shot_type      = 2,        /* rocket-like */
        .shot_power     = 10,
        .shot_speed     = 64,
        .shot_shift     = 6,
        .shot_cooldown  = 30,
        .damage_shift   = 4,        /* divide by 16 */
        .min_damage_after_shift = 0, /* BigClaws.s: beq -> low hits can do 0 */
        .explode_threshold = 0,
        .wander_timer   = 150,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 27,
        .scream_sound   = 27,
        .periodic_vocal1 = 17,
        .periodic_vocal2 = 18,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = -1,
        .damage_audio_class = ENEMY_DMG_AUDIO_BIG_GIB,
        .gib_splat_noisevol = 0,
        .death_frames   = {0,1,2,3,4,5,6,7,8,9, -1},
    },
    /* [9] Flying Scaly Ball (FlyingScalyBall.s ItsAFlyingNasty) */
    {
        .thing_height   = 96 * 128,
        .step_up        = 0,
        .step_down      = 0x1000000,
        .extlen         = 160,
        .awayfromwall   = 2,
        .nas_height     = 64,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 120,
        .shot_type      = 0,        /* plasma */
        .shot_power     = 5,
        .shot_speed     = 16,
        .shot_shift     = 3,
        .shot_cooldown  = 50,
        .damage_shift   = 0,
        .min_damage_after_shift = 0,
        .explode_threshold = 40,    /* Amiga: ble after cmp #40 → soft kill if damage <= 40 */
        .wander_timer   = 50,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 8,        /* unused on kill path; soft death uses screamsound #8 */
        .scream_sound   = 8,        /* lowscream @200 when killing blow <= 40 */
        .periodic_vocal1 = 16,      /* newhiss (FlyingScalyBall.s SecTimer) */
        .periodic_vocal2 = -1,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 100,
        .attack_sound   = 20,
        .damage_audio_class = ENEMY_DMG_AUDIO_FLYING,
        .gib_splat_noisevol = 0,
        .death_frames   = {-1},
    },
    /* [10] Tree (Tree.s ItsATree) */
    {
        .thing_height   = 200 * 128,
        .step_up        = 20 * 256,
        .step_down      = 20 * 256,
        .extlen         = 80,
        .awayfromwall   = 1,
        .nas_height     = 64,
        .melee_damage   = 0,
        .melee_cooldown = 0,
        .melee_range    = 80,
        .shot_type      = 2,        /* tree shoots rockets */
        .shot_power     = 10,
        .shot_speed     = 16,
        .shot_shift     = 3,
        .shot_cooldown  = 30,
        .damage_shift   = 2,        /* Tree.s: asr.b #2 */
        .min_damage_after_shift = 0, /* Tree.s: beq -> low hits can do 0 */
        .explode_threshold = 80,
        .wander_timer   = 50,
        .hiss_timer_min = 300,
        .hiss_timer_range = 255,
        .death_sound    = 27,
        .scream_sound   = 27,
        .periodic_vocal1 = 17,
        .periodic_vocal2 = 18,
        .periodic_vol_idle = 100,
        .periodic_vol_attack = 800,
        .attack_sound   = -1,
        .damage_audio_class = ENEMY_DMG_AUDIO_BIG_GIB,
        .gib_splat_noisevol = 0,
        .death_frames   = {-1},
    },
};

const int num_enemy_types = sizeof(enemy_params) / sizeof(enemy_params[0]);

/* -----------------------------------------------------------------------
 * Pickup constants
 * ----------------------------------------------------------------------- */
/* Ammo graphic per gun type: from Anims.s AMGR */
const int8_t ammo_graphic_table[8] = { 3, 4, 5, 0, 29, 0, 0, 28 };

/* Raw internal ammo added per gun pickup: from Anims.s AmmoInGuns */
const int8_t ammo_in_guns[8] = { 0, 5, 1, 0, 1, 0, 0, 5 };

/* -----------------------------------------------------------------------
 * Brightness animation tables
 * Translated from Anims.s pulseANIM, flickerANIM, fireFlickerANIM
 * 999 = loop marker
 * ----------------------------------------------------------------------- */
const int16_t pulse_anim[] = {
    -10,-10,-9,-9,-8,-7,-6,-5,-4,-3,-2,-1,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10,
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
    -1,-2,-3,-4,-5,-6,-7,-8,-9,
    999
};

const int16_t flicker_anim[] = {
    10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    -10,
    10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    10,10,10,10,10,10,10,10,10,10,
    -10,
    10,10,10,10,10,
    -10,
    999
};

const int16_t fire_flicker_anim[] = {
    -10,-9,-6,-10,-6,-5,-5,-7,-5,-10,-9,-8,-7,
    -5,-5,-5,-5,-5,-5,-5,-5,-6,-7,-8,-9,-5,
    -10,-9,-10,-6,-5,-5,-5,-5,-5,-5,-5,-5,
    999
};

/* -----------------------------------------------------------------------
 * End zones per level
 * Translated from AB3DI.s ENDZONES (line ~5940)
 * ----------------------------------------------------------------------- */
const int16_t end_zones[16] = {
    132, 149, 155, 107, 67, 132, 203, 166,
    118, 102, 103, 2, 98, 0, 148, 103
};

/* -----------------------------------------------------------------------
 * Level text
 * Translated from LevelBlurb.s LEVELTEXT
 * Headings translated from ControlLoop.s LEVEL_OPTS
 * ----------------------------------------------------------------------- */
const char *level_text_heading[16] = {
    "      LEVEL  1 :          THE GATE      ",
    "      LEVEL  2 :       STORAGE BAY      ",
    "      LEVEL  3 :     SEWER NETWORK      ",
    "      LEVEL  4 :     THE COURTYARD      ",
    "      LEVEL  5 :      SYSTEM PURGE      ",
    "      LEVEL  6 :         THE MINES      ",
    "      LEVEL  7 :       THE FURNACE      ",
    "      LEVEL  8 :  TEST ARENA GAMMA      ",
    "      LEVEL  9 :      SURFACE ZONE      ",
    "      LEVEL 10 :     TRAINING AREA      ",
    "      LEVEL 11 :       ADMIN BLOCK      ",
    "      LEVEL 12 :           THE PIT      ",
    "      LEVEL 13 :            STRATA      ",
    "      LEVEL 14 :      REACTOR CORE      ",
    "      LEVEL 15 :     COOLING TOWER      ",
    "      LEVEL 16 :    COMMAND CENTRE      ",
};

const char *level_text[16][LEVEL_TEXT_ROWS] = {
    {
        "",
        "",
        "",
        "",
        "",
        "The base looms dead and silent in front of me, blotting out the sky. The main",
        "entrance is out of the question; choked with rubble and bodies, not all of them",
        "human. I didn't look too closely. Picking my way through the debris around the",
        "perimeter, I find a way in: a service entrance located in a storage bay below",
        "ground level. I grip my pulse rifle tightly and lower myself into the pit.",
        "No turning back now.",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "",
        "Taking my life in my hands, I jump into the teleporter, hoping it will take me",
        "further into the complex, although I'm pretty hazy about what I'm going to do",
        "when I get there. As I materialize, however, my hopes sink. The transporter was",
        "intended for freight only, and I find myself in a huge empty storage room.",
        "Looks like I'll have to find some other way in. The Breed howl their greetings",
        "as I stride forward....",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "In the computer room I try to call up a map, or blueprint, or anything to tell",
        "me where I ought to be heading. The only plans I can access from this terminal,",
        "however, are some schematics for the sewer system. Poring over them I find a",
        "possible route: there's a waste outlet I can reach from my current location",
        "which seems to lead further into the complex. Unfortunately, the sewers are",
        "partially flooded most of he time, and sloshing through thigh-deep sewage is not",
        "my idea  of fun. It seems to be the only way forward, though, and retreat into",
        "the infested passages behind me is an even less inviting prospect....",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "Shivering and sweating at the same time, I try to shake the icy water from my",
        "clothes and take in my new surroundings. I think I must be somewhere in the",
        "research department; the token military presence I commanded here was always",
        "discouraged from poking their noses into matters that 'didn't concern them.'",
        "Looking around I catch my breath: this place is enormous; even bigger than I had",
        "thought. The purpose of this area eludes me; the cavernous rooms and winding",
        "staircases serve no immediately visible function. Stepping over the huddled body",
        "of another luckless soldier I back up against the cold stone wall and edge",
        "towards the corner. The hate-filled cries of the Breed echo through the dim",
        "vaulted chambers; this strange place is anything but deserted....",
        "",
        "",
        "",
    },
    {
        "",
        "As I pause for breath I notice a sign on the wall nearby:",
        "",
        "COMBAT TEST ARENA: ALPHA",
        "",
        "pointing back the way I have just come. Now it makes more sense! All those rooms",
        "and walkways were some sort of testing ground for - what? The grotesque",
        "experiments now littering the halls with their bodies? Or something else -",
        "something I haven't seen yet, perhaps? I glance around nervously as the thought",
        "takes shape, but as my eyes adjust to the gloom I see nothing but bank upon bank",
        "of computers stretching as far as the eye can see. Now this is more like it! If",
        "I can  gain access somehow, I might be able to find a way to escape! A databank",
        "this size must hold all sorts of useful information. There are no terminals",
        "though. Maybe if I find my way out I can hack in from somewhere nearby.",
        "A gurgling, half-human grunt behind me makes me spin around, heart pounding....",
        "",
    },
    {
        "",
        "As I had hoped, there is a room just outside the entrance to the computer store",
        "with an operational terminal. After nearly two hours of desperate hacking, the",
        "computers grudgingly furnish me with the information I need: a replay of the",
        "message my second in command sent to our superiors off-planet when the outbreak",
        "became unstoppable. He was planning to escape on our private shuttle, after",
        "disabling the cooling system on the main reactor. I watch in dismay as his",
        "message is cut short; the horde of slavering Breed which break down the door and",
        "devour him alive pay no heed to the camera still recording his screams. A split",
        "second later the net security catches up with my activities and the terminal",
        "shuts down. I know what I must do. A reactor meltdown would blow this whole",
        "wretched place into orbit and the Breed with it. And I might just live to see it",
        "happen. But to go any further I need a high-clearance access card: the security",
        "systems here are not responding to my palm print or retina scan. The Breed howl",
        "mockingly as I set out to find it....",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "I found the access card, along with the remains of its owner. What posessed him",
        "to flee into the mines no-one will ever know. His mildly surprised face gazing",
        "up at me from its watery hiding place is an image I have difficulty banishing",
        "from my mind. Along with many others. The transporter takes me down and down,",
        "into the substructure of the base. According to my route plan, I should be able",
        "to get back into the main building further on, saving time and avoiding some",
        "dangerous areas. This way is far from safe though; a lot of fuel lines go",
        "through this area....",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "As soon as I step onto the transporter I realise something is wrong. The",
        "instrument panel dangles from a jumble of wires; sparks and smoke issue from",
        "within. I curse loudly and lunge for the door; a faulty transporter can be",
        "lethal. But before I can get out, something within the scorched mess of",
        "electronics crackles and I am - somewhere else.",
        "After checking that I am, in fact, still whole, I look uneasily around myself.",
        "An icy chill settles over my heart as I see a sign - scored and dented by some",
        "massive impact - which reads:",
        "",
        "COMBAT TEST ARENA: GAMMA",
        "",
        "The huge exit door is locked. I'm going to have to find the key. Hopefully",
        "whatever they were testing isn't still here....",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "Glad to be alive, I stumble out of the combat arena and collapse, the door",
        "slamming shut behind me. When I come to to my senses again, I find myself on",
        "some sort of lift. The only way seems to be upwards, but I have no idea where it",
        "will take me. My only hope is to find another terminal and get back on track.",
        "Exhausted, I bandage my wounds as best I can and stagger to my feet. I press a",
        "nearby button and the lift judders upwards in response. I wipe my sweaty palms",
        "on my jacket and grip my gun more tightly - things are too quiet up there....",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "I am beginning to think that there is simply no end to this hellish place.",
        "My fevered imagination conjures up an entire planet riddled with these dark",
        "corridors and rooms, empty and deserted except for the screams of the Breed.",
        "With difficulty I get a grip on myself. A barely readable notice on the wall",
        "gives me hope: one of the facilities it mentions, the administration block, was",
        "right near the route the computer gave me. Straightening with new purpose, I set",
        "my jaw and continue. But in the shadows ahead, the breed reach out for me....",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "",
        "I made it! The transporter dumps me in a brightly-lit room in the administration",
        "centre. Supplies are at hand, and I waste no time provisioning myself. All that",
        "remains is for me to find my way out of here and I'll be right on top of the",
        "reactor core! I press the panel which opens the door with renewed hope; I might",
        "just beat them yet....",
        "",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "I slam the door of the admin block behind me, and stare about wildly. I hadn't",
        "expected so much resistance; what has happened here? I can only assume that I am",
        "approaching the centre of the infestation. But there! On the wall opposite: a",
        "sign pointing the way to the reactor control room! I lurch off in the direction",
        "it points, but am brought up short with a shout of despair. The whole corridor",
        "is blocked with rubble! I punch the wall in anger and frustration, but I will",
        "not - cannot - give up now. I look around desperately; a wall plan nearby shows",
        "no other connecting corridors, but there is an alternative route: a winding",
        "tunnel leading to a deep borehole. From there I can ride a lift back up to the",
        "surface and gain access to the reactor from the other side. I stare for a while",
        "at the mountain of debris, mere yards on the other side of which is my goal,",
        "then turn my back and walk away....",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "The lift takes me up to ground level, but what had been marked as a passageway",
        "on the plans turns out to be still under construction. Wetting a finger and",
        "holding it aloft I find that there is indeed a sluggish current of air from the",
        "black passage ahead, but the labyrinth of caves also echoes with the cries of",
        "the enemy. I briefly consider returning to the pit and trying to find a",
        "different way, but shudder and dismiss the idea immediately. Gritting my teeth,",
        "I plunge into the darkness with guns ablaze....",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "",
        "Getting to the reactor control centre proves to be only half the battle. The",
        "place is a maze of corridors and rooms centred around the - maddeningly close",
        "but still unreachable - reactor core itself. Somehow I must raise the walk-ways",
        "leading to the cooling system and extract it from the core. Then I'll have about",
        "two hours to get into orbit before meltdown occurs. If the shuttle is flight-",
        "ready, that's no problem. If not...",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "",
        "",
        "",
        "",
        "Mission accomplished, I pelt out of the reactor core towards the command centre,",
        "which lies some distance from the main base. First though I have to get out of",
        "the power plant, and with fuel coming to the boil in the groaning pipes all",
        "around me, that's easier said than done. The corridors here are thick with the",
        "Breed too, and I'm going to have to wade right through them. My own scream of",
        "rage and hate rising to challenge the horde, I charge the lot of them....",
        "",
        "",
        "",
        "",
        "",
    },
    {
        "",
        "Slamming the door shut on the grasping claws and rending teeth, silence engulfs",
        "me. I turn and lean on the wall, heaving a sigh of relief. The reactor is behind",
        "me now, and all that remains is for me to find the shuttle and get out of here.",
        "Grabbing as much equipment as I can carry, I set off, the nearness of my goal",
        "spurring me on. I pass a sign:",
        "",
        "COMMAND CENTRE: AUTHORIZED PERSONNEL ONLY. CLEARANCE",
        "MU T BE OB AINED FRO",
        "",
        "the rest of it is unreadable; a charred mess. I resolve to be on the look out",
        "for anyone who looks likely to hold a passkey. As I step outside I can see the",
        "command centre, the only access from this side seemingly via a gantry high",
        "overhead. Somewhere there must be a way up to that gantry. And somewhere there's",
        "a passkey to get me inside....",
        "",
    },
};

const char *end_game_text =
    "CONGRATULATIONS!\n\n"
    "You have successfully completed\n"
    "Alien Breed 3D.\n\n"
    "The alien menace has been destroyed\n"
    "and the research station is safe.\n";

/* Game conditions (shared variable, for switches/doors) */
int16_t game_conditions = 0;
