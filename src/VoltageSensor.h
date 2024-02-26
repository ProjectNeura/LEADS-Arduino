#ifndef VOLTAGESENSOR_H
#define VOLTAGESENSOR_H


#include "Device.h"

class VoltageSensor : public Device<float> {
public:
    WheelSpeedSensor(int *const pins);
    void initialize();
    float read();
};


#endif //VOLTAGESENSOR_H
