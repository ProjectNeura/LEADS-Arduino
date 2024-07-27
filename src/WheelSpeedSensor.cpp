#include "WheelSpeedSensor.h"
#include "Utils.h"

WheelSpeedSensor::WheelSpeedSensor(const ArrayList<int> &pins, OnUpdate onUpdate) :
    Device<float>(pins), _t1(0), _t2(0), _consecutive(false), _onUpdate(onUpdate) {}

void WheelSpeedSensor::initialize(const ArrayList<String> &parentTags) {
    Device<float>::initialize(parentTags);
    pinMode(_pins.get(0), INPUT);
    _t1 = 0;
    _t2 = millis();
    _consecutive = false;
}

float getRPM(unsigned long t1, unsigned long t2) { return float(60000.0 / double(t2 - t1)); }

float WheelSpeedSensor::read() {
    if (pulseTriggered(_pins.get(0))) {
        if (!_consecutive) {
            _consecutive = true;
            _t1 = _t2;
            _t2 = millis();
            float r = getRPM(_t1, _t2);
            _onUpdate(r);
            return r;
        }
    } else
        _consecutive = false;
    return getRPM(_t1, _t2);
}
