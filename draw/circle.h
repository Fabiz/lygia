
#include "../sdf/circleSDF.h"

#include "fill.h"
#include "stroke.h"

/*
original_author: Patricio Gonzalez Vivo
description: draw a circle filled or not. 
use: circle(<vec2> st, <float> size [, <float> width])
*/

#ifndef FNC_CIRCLE
#define FNC_CIRCLE
float circle(vec2 st, float size) {
    return fill(circleSDF(st), size);
}

float circle(vec2 st, float size, float strokeWidth) {
    return stroke(circleSDF(st), size, strokeWidth);
}
#endif
