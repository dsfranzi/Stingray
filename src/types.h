#ifndef TYPES_H
#define TYPES_H

#define DEVICENAME "Silent Stingray"

typedef short int16;
typedef int   int32;
typedef float  float32;
typedef double float64;

typedef unsigned char byte;

typedef unsigned int uint32;

typedef struct
{
  float64 lat;
  float64 lng;
  float64 alt; 
} location_t;

typedef enum 
{
  LEFT,
  RIGHT,
  BOTH
} motors_t;

typedef enum 
{
  FALSE,
  TRUE
} bool_t;
  
typedef enum
{
  STANDBY,
  STABILIZE,
  MANUAL,
  WAYPOINT
} status_t;


// Vektoren
typedef struct
{
  float64 a;
  float64 b;
} vector_t;

typedef struct 
{
  float64 x;
  float64 y;
} point_t;

#endif
