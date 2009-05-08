#pragma once
#include <math.h>

/*/////////////////////////////////////////////////////////
MathUtil: This library was created to hold pre-calculated 
values that are used often
/////////////////////////////////////////////////////////*/

//Created my own datatype to avoid confusion as 
//char is missleading when talking abour numbers 
typedef unsigned char uCol;

// Declare a global constant for pi and a few multiples.

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;
const float kPiOver180 = kPi / 180.0f;
const float k180OverPi = 180.0f / kPi;

// Convert between degrees and radians

inline float	degToRad(float deg) { return deg * kPiOver180; }
inline float	radToDeg(float rad) { return rad * k180OverPi; }

// Convert between "field of view" and "zoom"  See section 15.2.4.
// The FOV angle is specified in radians.

inline float	fovToZoom(float fov) { return 1.0f / tan(fov * .5f); }
inline float	zoomToFov(float zoom) { return 2.0f * atan(1.0f / zoom); }

