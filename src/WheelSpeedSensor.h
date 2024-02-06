#ifndef WHEELSPEEDSENSOR_H
#define WHEELSPEEDSENSOR_H


#include "Device.h"

#define ZERO_INTERVAL 3000

typedef void (*OnUpdate)(float ws);

class WheelSpeedSensor : public Device<float> {
protected:
    long _t1, _t2;
    long _lastUpdate;
    bool _consecutive;
    const OnUpdate _onUpdate;

public:
    WheelSpeedSensor(int *const pins, OnUpdate onUpdate);
    void initialize();
    float read();
    String debug();
};


#endif // WHEELSPEEDSENSOR_H
