#ifndef PEER_H
#define PEER_H


#include "Controller.h"

// although we try to keep a consistent format, the C++ version does not support multithreading
class Peer : public Controller<String, String> {
protected:
    unsigned int _baudRate;
    String _separator, _remainder;

public:
    explicit Peer(const String& tag, unsigned int baudRate = 9600, const String &separator = ";", const String &remainder = "");
    void initialize(const ArrayList<String> &parentTags) override;
    String read() override;
    void write(const String &payload) override;
    void refresh();
};


#endif // PEER_H
