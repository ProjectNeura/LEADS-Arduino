#ifndef UTILS_H
#define UTILS_H


#include "Arduino.h"

bool pulseTriggered(int pin);

bool equivalent(long a, long b, float epsilon);

bool equivalent(float a, float b, float epsilon);

void returnFloat(const String &tag, float n);

void returnDouble(const String &tag, double n);


#endif // UTILS_H
