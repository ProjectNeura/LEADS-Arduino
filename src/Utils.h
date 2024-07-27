#ifndef UTILS_H
#define UTILS_H


#include "Arduino.h"
#include "Peer.h"

bool pulseTriggered(int pin);

void returnFloat(Peer peer, const String &tag, float n);

void returnDouble(Peer peer, const String &tag, double n);


#endif // UTILS_H
