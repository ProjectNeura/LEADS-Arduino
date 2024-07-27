#ifndef WHEELSPEEDSENSOR_H
#define WHEELSPEEDSENSOR_H


#include "Device.h"

typedef void (*OnUpdate)(float ws);

class WheelSpeedSensor : public Device<float> {
protected:
    unsigned long _t1, _t2;
    bool _consecutive;
    const OnUpdate _onUpdate;

public:
    WheelSpeedSensor(const ArrayList<int> &pins, OnUpdate onUpdate);
    void initialize(const ArrayList<String> &parentTags) override;
    float read() override;
};


#endif // WHEELSPEEDSENSOR_H
