#ifndef DR_MATH_H
#define DR_MATH_H

#include "types.h"

float64 vScalarProduct(const vector_t * const v1, const vector_t * const v2);
float64 vLength(const vector_t * const v);
float64 vAngle(const vector_t * const v1, const vector_t * const v2);
vector_t vSum(const vector_t * const v1, const vector_t * const v2);
vector_t vDiff(const vector_t * const v1, const vector_t * const v2);
vector_t vMul_int32(const vector_t * const v, const float64 f);
vector_t pointsToVector(const point_t * const origin, const point_t * const head);

#endif
