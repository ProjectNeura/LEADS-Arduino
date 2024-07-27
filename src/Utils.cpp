#include "Utils.h"

bool pulseTriggered(int pin) { return digitalRead(pin) == LOW; }

void returnFloat(Peer peer, const String &tag, float n) { peer.write(tag + ":" + n); }

void returnDouble(Peer peer, const String &tag, double n) { peer.write(tag + ":" + n); }
