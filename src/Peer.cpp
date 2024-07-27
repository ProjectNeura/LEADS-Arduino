#include "Peer.h"


Peer::Peer(unsigned int baudRate, String separator, String remainder) :
    Controller<String, String>(), _baudRate(baudRate), _separator(separator), _remainder(remainder) {}
void Peer::initialize(const ArrayList<String> &parentTags) {
    Controller<String, String>::initialize(parentTags);
    Serial.begin(_baudRate);
}
String Peer::read() {
    char c = Serial.read();
    if (c > 0) {
        _remainder += c;
        if (!_remainder.endsWith(_separator))
            return "";
        String result = _remainder.substring(0, _remainder.length() - _separator.length());
        _remainder = "";
        return result;
    }
    return "";
}
void Peer::write(String payload) { Serial.print(payload + _separator); }
void Peer::refresh() {
    String msg = read();
    if (msg == "")
        return;
    for (Device<String> d: _devices)
        d.update(msg);
}
