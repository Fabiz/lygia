#include "tonemap/aces.h"
#include "tonemap/debug.h"
#include "tonemap/filmic.h"
#include "tonemap/linear.h"
#include "tonemap/reinhard.h"
#include "tonemap/reinhardJodie.h"
#include "tonemap/uncharted.h"
#include "tonemap/uncharted2.h"
#include "tonemap/unreal.h"

/*
original_author: Patricio Gonzalez Vivo  
description: Tone maps the specified RGB color (meaning convert from HDR to LDR) inside the range [0..~8] to [0..1]. The input must be in linear HDR pre-exposed.
use: tonemap(<vec3|vec4> rgb)
options:
    TONEMAP_FNC: tonemapLinear, tonemapReinhard, tonemapUnreal, tonemapACES, tonemapDebug, tonemapUncharter
*/

#ifndef TONEMAP_FNC
#if defined(TARGET_MOBILE) || defined(PLATFORM_RPI) || defined(PLATFORM_WEBGL)
    #define TONEMAP_FNC     tonemapUnreal
#else
    // #define TONEMAP_FNC     tonemapDebug
    // #define TONEMAP_FNC     tonemapFilmic
    // #define TONEMAP_FNC     tonemapACES
    // #define TONEMAP_FNC     tonemapUncharted2
    // #define TONEMAP_FNC     tonemapUncharted
    #define TONEMAP_FNC     tonemapReinhardJodie
    // #define TONEMAP_FNC     tonemapReinhard
    // #define TONEMAP_FNC     tonemapUnreal
    // #define TONEMAP_FNC     tonemapLinear
#endif
#endif

#ifndef FNC_TONEMAP
#define FNC_TONEMAP

vec3 tonemap(const vec3 color) { return TONEMAP_FNC (color); }
vec4 tonemap(const vec4 color) { return TONEMAP_FNC (color); }

#endif
