#ifndef BELEUCHTUNG_H
#define BELEUCHTUNG_H

#include <Arduino.h>

void setupBeleuchtung(void);

void lightFront(const byte value);
void lightRear(const byte value);
void lightPos(const byte value);




#endif
