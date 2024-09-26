#include "Utils.h"

void returnString(Peer &peer, const String &tag, const String &msg) { peer.write(tag + ":" + msg); }

void returnFloat(Peer &peer, const String &tag, float n) { peer.write(tag + ":" + n); }

void returnDouble(Peer &peer, const String &tag, double n) { peer.write(tag + ":" + n); }
