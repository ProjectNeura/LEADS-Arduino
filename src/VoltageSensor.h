#ifndef VOLTAGESENSOR_H
#define VOLTAGESENSOR_H


#include "Device.h"

class VoltageSensor : public Device<float> {
protected:
    float _factor;

public:
    VoltageSensor(const ArrayList<int> &pins, float r1, float r2);
    void initialize(const ArrayList<String> &parentTags) override;
    float read() override;
};


#endif // VOLTAGESENSOR_H
