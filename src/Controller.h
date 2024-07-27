#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Device.h"

template<typename T, typename E>
class Controller : public Device<T> {
protected:
    ArrayList<String> _device_tags;
    ArrayList<Device<E>> _devices;
    void _attachDevice(String &tag, Device<E> device) {
        _device_tags.add(tag);
        _devices.add(device);
        device.tag(tag);
    }

public:
    Controller() : Device<T>() {}
    int level() { return this->_parentTags.size(); }
    const ArrayList<Device<E>> &devices() { return _devices; }
    void device(const String &tag, Device<E> device) { _attachDevice(tag, device); }
    Device<E> device(const String &tag) { return _devices.get(_device_tags.indexOf(tag)); }
    virtual void initialize(const ArrayList<String> &parentTags) {
        Device<E>::initialize(parentTags);
        for (Device<E> d: _devices) {
            ArrayList<String> deviceParentTags = this->_parentTags.copy();
            deviceParentTags.add(this->_tag);
            d.initialize(deviceParentTags);
        }
    }
};


#endif // CONTROLLER_H
