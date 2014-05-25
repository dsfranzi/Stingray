#include "motor.h"
#include "types.h"
#include "pins.h"

#include <Arduino.h>

/* Setup */
void setupMotors(void)
{
  pinMode(MOTOR_LEFT_DIR, OUTPUT);
  pinMode(MOTOR_RIGHT_DIR, OUTPUT);
  pinMode(MOTOR_LEFT_PWM, OUTPUT);
  pinMode(MOTOR_RIGHT_PWM, OUTPUT);
  pinMode(MOTOR_LEFT_BRAKE, OUTPUT);
  pinMode(MOTOR_RIGHT_BRAKE, OUTPUT);  
  cutoff(BOTH);
  unbrake(BOTH);
  Serial.println("Motor startup complete");
}
/* Ende Setup */

static void setMotorValues(const motors_t motor, const byte direction, const byte value) 
{
  unbrake(motor);
  setDirection(motor, direction);
  setSpeed(motor, value);
}

void setSpeed(const motors_t motor, const byte value)
{
  if ((motor == LEFT) || (motor == BOTH)) 
  {
    analogWrite(MOTOR_LEFT_PWM, value);
  } 
  if ((motor == RIGHT) || (motor == BOTH))
  {
    analogWrite(MOTOR_RIGHT_PWM, value);
  }  
}

void setDirection(const motors_t motor, const byte direction)
{
  if ((motor == LEFT) || (motor == BOTH)) 
  {
    digitalWrite(MOTOR_LEFT_DIR, direction);
  } 
  if ((motor == RIGHT) || (motor == BOTH))
  {
    digitalWrite(MOTOR_RIGHT_DIR, direction);
  }
}

void cutoff(motors_t motor)
{
  setSpeed(motor, 0);
}

void brake(const motors_t motor)
{
  setBrake(motor, HIGH);
}

void unbrake(const motors_t motor)
{
  setBrake(motor, LOW);
}

static void setBrake(const motors_t motor, const byte value)
{
  if ((motor == LEFT) || (motor == BOTH))
  {
    digitalWrite(MOTOR_LEFT_BRAKE, value);
  }
  if ((motor == RIGHT) || (motor == BOTH))
  {
    digitalWrite(MOTOR_RIGHT_BRAKE, value);
  }
}

/*float measureWaterResistance(void) 
{
  ulong time_before, time_after;
  
  time_before = millis();
  
  setMotorValues(BOTH, HIGH, 255);

  while (1)
  {
    //
  }

  // ...  
  
  time_after = millis();
  
  cutoff(BOTH);
  
}*/
