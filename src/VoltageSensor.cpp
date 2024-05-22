#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(int r1, int r2, int *const pins) : _factor((float) (r1 + r2) / r2), Device<float>(pins) {}

void VoltageSensor::initialize() { pinMode(_pins[0], INPUT); }

float VoltageSensor::read() { return (float) analogRead(_pins[0]) * _factor * 5 / 1023; }
