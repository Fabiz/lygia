#include "../sample/sprite.h"

/*
original_author: Patricio Gonzalez Vivo
description: sample a frame on a sprite sheet
use: <SPRITELOOP_TYPE> SpriteLOOP(<sampler2D >tex, <vec2> st, <vec2> grid, <float> frame)
options:
    - SAMPLER_FNC(TEX, UV)
    - SAMPLESPRITE_TYPE: vec4
    - SAMPLESPRITE_SAMPLER_FNC(UV)
examples:
    - /shaders/animation_sprite.frag
*/

#ifndef FNC_SPRITELOOP
#define FNC_SPRITELOOP

SAMPLESPRITE_TYPE spriteLoop(sampler2D tex, vec2 st, vec2 grid, float start_index, float end_index, float time) {
    float frame = mod(time, end_index-start_index);
    return sampleSprite(tex, st, grid, start_index + frame);
}

#endif
