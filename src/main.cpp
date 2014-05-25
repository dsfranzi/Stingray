#include <Wire.h>
#include <Arduino.h>

#include "motor.h"
#include "types.h"
#include "pins.h"
#include "lights.h"
#include "loops.h"
#include "DR_math.h"
#include "Scheduler.h"


#define LEDBLINK_PIN    13    // I/O pin connected to the LED.
#define LEDBLINK_MS     200  // Blink rate (in milliseconds).

//#include "lib/simclist.h"

/* Globale Variablen */
location_t gLocation; //Aktuelle Position & Höhe
float64    gHeading;  //Aktuelle Richtung
float64    gSpeed;    //Aktuelle Geschwindigkeit
/* Ende Globale Variablen */

void setup()
{ 
  pinMode(LEDBLINK_PIN, OUTPUT);

  Serial.begin(9600);

  Serial.println("-- " DEVICENAME " begin startup --");

  Serial.println("Firmware compiled " __DATE__ " - " __TIME__);
  Serial.println("With avr-g++ Version " __VERSION__);

  setupMotors();
  setupBeleuchtung();

  pinMode(13, OUTPUT);
  
  Serial.println("-- " DEVICENAME " startup complete --");
}

void loop()
{  
  int i;
  static status_t shipstate = STANDBY; // Aktueller Status

  loop_general();
  
  /* Statusschleifen */
  if (shipstate == STANDBY)
  loop_standby();
  else if (shipstate == STABILIZE)
  loop_stabilize();
  else if (shipstate == MANUAL)
  loop_manual();  
  else if (shipstate == WAYPOINT)
  loop_waypoint();
  /* Ende Statusschleifen */
}