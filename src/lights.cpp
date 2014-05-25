#include "lights.h"

#include <Arduino.h>
#include "pins.h"


/* Setup */
void setupBeleuchtung(void)
{
  pinMode(LIGHT_FRONT, OUTPUT);
  pinMode(LIGHT_REAR, OUTPUT);
  pinMode(LIGHT_POS, OUTPUT);
  Serial.println("Light startup complete");
}
/* Ende Setup */

void lightFront(const byte value)
{
  digitalWrite(LIGHT_FRONT, value);
}

void lightgRear(const byte value)
{
  digitalWrite(LIGHT_REAR, value);
}

void lightPos(const byte value)
{
  digitalWrite(LIGHT_POS, value);
}