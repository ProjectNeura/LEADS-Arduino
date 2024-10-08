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
    Device() : Device(ArrayList<int>(0)) {}
    ~Device() = default;
    int level() { return _parentTags.size(); }
    void tag(const String &tag) { _tag = tag; }
    String tag() { return _tag; }
    const ArrayList<String> &parentTags() { return _parentTags; }
    virtual void initialize(const ArrayList<String> &parentTags) { _parentTags = parentTags; }
    void initializeAsRoot() { initialize(ArrayList<String>()); }
    virtual T read() { return T(); }
    virtual void write(const T &payload) {}
    virtual void update(const T &data) {}
    virtual void close() {}
};


#endif // DEVICE_H
