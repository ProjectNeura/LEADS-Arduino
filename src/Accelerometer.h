#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H


#include "Device.h"

struct Acceleration {
    float yaw = 0, pitch = 0, roll = 0;
    float forwardAcceleration = 0, lateralAcceleration = 0, verticalAcceleration = 0;
    String toString();
};

typedef void (*OnAccelerometerUpdate)(Acceleration acceleration);

class Accelerometer : public Device<Acceleration> {
protected:
    const OnAccelerometerUpdate _onUpdate;

public:
    explicit Accelerometer(OnAccelerometerUpdate onUpdate);
    void initialize(const ArrayList<String> &parentTags) override;
};


#endif // ACCELEROMETER_H
