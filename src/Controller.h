#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Device.h"

template<typename T, typename E>
class Controller : public Device<T> {
protected:
    ArrayList<String> _device_tags;
    ArrayList<Device<E>> _devices;
    void _attachDevice(const String &tag, Device<E> device) {
        _device_tags.add(tag);
        _devices.add(device);
        device.tag(tag);
    }

public:
    Controller() : Device<T>() {}
    const ArrayList<Device<E>> &devices() { return _devices; }
    void device(const String &tag, const Device<E> &device) { _attachDevice(tag, device); }
    Device<E> device(const String &tag) { return _devices[_device_tags.indexOf(tag)]; }
    void initialize(const ArrayList<String> &parentTags) override {
        Device<E>::initialize(parentTags);
        for (Device<E> d: _devices)
            d.initialize(this->_parentTags + this->_tag);
    }
};


#endif // CONTROLLER_H
