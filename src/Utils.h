#ifndef UTILS_H
#define UTILS_H


#include "Arduino.h"
#include "Peer.h"

void returnString(Peer &peer, const String &tag, const String &msg);

void returnFloat(Peer &peer, const String &tag, float n);

void returnDouble(Peer &peer, const String &tag, double n);


#endif // UTILS_H
