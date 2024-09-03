#include "Peer.h"


// std::move() is not available in the C library
Peer::Peer(const String &tag, unsigned int baudRate, const String &separator, // NOLINT(*-pass-by-value)
           const String &remainder) : // NOLINT(*-pass-by-value)
    Controller<String, String>(), _baudRate(baudRate), _separator(separator), _remainder(remainder) {
    _tag = tag;
}
void Peer::initialize(const ArrayList<String> &parentTags) {
    Controller<String, String>::initialize(parentTags);
    Serial.begin(_baudRate);
}
String Peer::read() {
    char c = char(Serial.read());
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
void Peer::write(const String &payload) { Serial.print(payload + _separator); }
void Peer::update(const String &data) {
    for (Device<String> d: _devices)
        if (data.startsWith(d.tag() + ":"))
            d.update(data.substring(d.tag().length() + 1));
}
void Peer::refresh() {
    String msg = read();
    if (msg == "")
        return;
    if (msg == "ic")
        return write(_tag);
    update(msg);
}
