#include "Accelerometer.h"

String Acceleration::toString() {
    return String(yaw) + "," + pitch + "," + roll + "," + forwardAcceleration + "," + lateralAcceleration + "," +
           verticalAcceleration;
}

Accelerometer::Accelerometer(OnAccelerometerUpdate onUpdate) : _onUpdate(onUpdate) {}

void Accelerometer::initialize(const ArrayList<String> &parentTags) { Device<Acceleration>::initialize(parentTags); }
