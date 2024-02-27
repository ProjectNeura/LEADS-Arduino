#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(int *const pins) : Device<float>(pins) {}

void VoltageSensor::initialize() { pinMode(_pins[0], INPUT); }

float VoltageSensor::read() { return int(((float) analogRead(_pins[0]) / 4.092)) % 100 / 10; }
