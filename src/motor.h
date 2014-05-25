#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

void setupMotors(void);

static void setMotorValues(const motors_t motor, const byte direction, const byte value);

void setSpeed(const motors_t motor, const byte value);
void setDirection(const motors_t motor, const byte direction);
void cutoff(motors_t motor);
void brake(const motors_t motor);
void unbrake(const motors_t motor);
static void setBrake(const motors_t motor, const byte value);









#endif

