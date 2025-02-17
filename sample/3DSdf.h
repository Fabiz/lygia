#include "2DCube.h"
#include "../space/scale.h"
#include "../sdf/boxSDF.h"
#include "../sdf/opIntersection.h"

/*
Author: Patricio Gonzalez Vivo
description: Use a 2D texture as to encode a 3D SDF (Signed Distance Field) function
use: <vecSAMPLE3DSDF_TYPE4> sample3DSdf(in <sampler2D> lut, in <vec3> xyz) 
options:
    - SAMPLER_FNC(TEX, UV): optional depending the target version of GLSL (texture2D(...) or texture(...))
    - SAMPLE_2DCUBE_CELL_SIZE
    - SAMPLE_2DCUBE_CELLS_PER_SIDE: default 8
    - SAMPLE_2DCUBE_FNC
    - SAMPLE3DSDF_TYPE: defaults to float
    - SAMPLE3DSDF_FNC(TEX, POS): defaults to sample2DCube(TEX, POS).r
examples:
    - /shaders/sample_3Dsdf.frag 
*/

#ifndef SAMPLE3DSDF_TYPE
#define SAMPLE3DSDF_TYPE float
#endif

#ifndef SAMPLE3DSDF_FNC
#define SAMPLE3DSDF_FNC(TEX, POS) sample2DCube(TEX, POS).r
#endif

#ifndef FNC_SAMPLE3DSDF
#define FNC_SAMPLE3DSDF
SAMPLE3DSDF_TYPE sample3DSdf(sampler2D tex, vec3 pos) {
    pos += 0.5;
    pos = scale(pos, 0.5);
    SAMPLE3DSDF_TYPE sdf = (SAMPLE3DSDF_FNC(tex, pos) * 2.0 - 1.0) * 1.5;
    return opIntersection( boxSDF(pos - 0.5, vec3(0.5)), sdf);
}
#endif
