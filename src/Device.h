#ifndef DEVICE_H
#define DEVICE_H


#include "ArrayList.h"

template<typename T>
class Device {
protected:
    String _tag = "";
    ArrayList<String> _parentTags = ArrayList<String>();
    ArrayList<int> _pins;

public:
    explicit Device(const ArrayList<int> &pins) : _pins(pins) {}
    ~Device() = default;
    void tag(const String &tag) { _tag = tag; }
    String tag() { return _tag; }
    void parentTags(const ArrayList<String> &parentTags) { _parentTags = parentTags; }
    const ArrayList<String> &parentTags() { return _parentTags; }
    virtual void initialize(const ArrayList<String> &parentTags) { _parentTags = parentTags; }
    virtual T read() = 0;
    virtual void write(T payload) {}
    virtual void close() {}
};


#endif // DEVICE_H
