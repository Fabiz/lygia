/*
original_author: Patricio Gonzalez Vivo  
description: |
    Convert LST to RGB. LMS (long, medium, short), is a color space which represents the response of the three types of cones of the human eye, named for their responsivity (sensitivity) peaks at long, medium, and short wavelengths. 
    Refs https://en.wikipedia.org/wiki/LMS_color_space https://arxiv.org/pdf/1711.10662

use: <vec3\vec4> lms2rgb(<vec3|vec4> lms)
*/

#ifndef FNC_LMS2RGB
#define FNC_LMS2RGB
vec3 lms2rgb(vec3 lms) {
    // mat3 lms2rgb_mat = mat3(
    //     2.85847e+0, -1.62879e+0, -2.48910e-2,
    //     -2.10182e-1,  1.15820e+0,  3.24281e-4,
    //     -4.18120e-2, -1.18169e-1,  1.06867e+0
    // );

    mat3 lms2rgb_mat = mat3(
         0.0809444479,  -0.0102485335,  -0.000365296938,
        -0.13050440,     0.0540193266,  -0.00412161469,
         0.116721066,   -0.113614708,    0.693511405
    );

    return lms2rgb_mat * lms;
}

vec4 lms2rgb(vec4 lms) { return vec4( lms2rgb(lms.xyz), lms.a ); }
#endif
