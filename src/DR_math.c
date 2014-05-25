#include "DR_math.h"

#include <math.h>

float64 vScalarProduct(const vector_t * const v1, const vector_t * const v2)
// Skalarprodukt zweier Vektoren
// a ○ b = a1 * b1 + a2 * b2
{
  return (v1->a * v2->a) + (v1->b * v2->b);
}

float64 vLength(const vector_t * const v)
// Länge eines Vektors
// a = Wurzel(a1² + a2²)
{
  return sqrt((v->a * v->a) + (v->b * v->b));
}

float64 vAngle(const vector_t * const v1, const vector_t * const v2)
// Winkel zwischen 2 Vektoren
// phi = (a ○ b) / (Länge(a) * Länge(b))
{
  return acos(vScalarProduct(v1, v2) / (vLength(v1) * vLength(v2)));
}

vector_t vSum(const vector_t * const v1, const vector_t * const v2)
// Vektoraddition
{
  vector_t result;

  result.a = v1->a + v2->a;
  result.b = v1->b + v2->b;

  return result;
}

vector_t vDiff(const vector_t * const v1, const vector_t * const v2)
//Vektorsubtraktion
{
  vector_t result;
  
  result.a = v1->a - v2->a;
  result.b = v1->b - v2->b;
  
  return result;
}

vector_t vMul_int32(const vector_t * const v, const float64 f)
// Verlängerung des Vektors v um Faktor f
{
  vector_t result;
  
  result.a = (int32) v->a * f;
  result.b = (int32) v->b * f;
  
  return result;
}

vector_t pointsToVector(const point_t * const origin, const point_t * const head)
{
  vector_t result;
  
  result.a = head->x - origin->x;
  result.b = head->y - origin->y;
  
  return result;
}
