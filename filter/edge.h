#include "../sample/clamp2edge.h"

/*
original_author: Patricio Gonzalez Vivo
description: Wrapper around three different edge detection algorithms Sobel, Prewitt, and directional Sobel
use: edge(<sampler2D> texture, <vec2> st, <vec2> pixels_scale)
options:
    - EDGE_FNC: Edge detection algorithm, defaults to edgeSobel, edgePrewitt & edgeSobel_directional also available
    - EDGE_TYPE: Return type, defaults to float
    - EDGE_SAMPLER_FNC: Function used to sample the input texture, defaults to texture2D(tex,TEX, UV).r
    - SAMPLER_FNC(TEX, UV): optional depending the target version of GLSL (texture2D(...) or texture(...))
examples:
    - /shaders/filter_edge2D.frag
*/

#ifndef EDGE_FNC
#define EDGE_FNC edgeSobel
#endif

#ifndef EDGE_TYPE
#define EDGE_TYPE float
#endif

#ifndef EDGE_SAMPLER_FNC
#define EDGE_SAMPLER_FNC(TEX, UV) sampleClamp2edge(TEX, UV).r
#endif

#include "edge/prewitt.h"
#include "edge/sobel.h"
#include "edge/sobelDirectional.h"

#ifndef FNC_EDGE
#define FNC_EDGE
EDGE_TYPE edge(in sampler2D tex, in vec2 st, in vec2 offset) {
    return EDGE_FNC(tex, st, offset);
}
#endif
