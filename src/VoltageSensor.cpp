#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(const ArrayList<int> &pins, float r1, float r2) :
    Device<float>(pins), _factor((r1 + r2) / r2) {}

void VoltageSensor::initialize(const ArrayList<String> &parentTags) {
    Device<float>::initialize(parentTags);
    pinMode(_pins[0], INPUT);
}

float VoltageSensor::read() { return (float) analogRead(_pins[0]) * _factor * 5 / 1023; }
