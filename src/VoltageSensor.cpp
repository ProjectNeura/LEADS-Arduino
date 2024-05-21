#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(int *const pins) : Device<float>(pins) {}

void VoltageSensor::initialize() { pinMode(_pins[0], INPUT); }

float VoltageSensor::read() { return (float) analogRead(_pins[0]) * 5 / 1023; }
