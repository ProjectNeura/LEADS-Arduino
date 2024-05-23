#ifndef VOLTAGESENSOR_H
#define VOLTAGESENSOR_H


#include "Device.h"

class VoltageSensor : public Device<float> {
protected:
    float _factor;
public:
    VoltageSensor(float r1, float r2, int *const pins);
    void initialize();
    float read();
};


#endif //VOLTAGESENSOR_H
