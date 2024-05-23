#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(float r1, float r2, int *const pins) : _factor((r1 + r2) / r2), Device<float>(pins) {}

void VoltageSensor::initialize() { pinMode(_pins[0], INPUT); }

float VoltageSensor::read() { return (float) analogRead(_pins[0]) * _factor * 5 / 1023; }
