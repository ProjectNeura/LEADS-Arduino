#ifndef UTILS_H
#define UTILS_H


#include "Arduino.h"

bool pulseTriggered(int pin);

bool equivalent(long a, long b, float epsilon);

bool equivalent(float a, float b, float epsilon);

void returnFloat(String header, float n);


#endif // UTILS_H
