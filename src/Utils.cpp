#include "Utils.h"

bool pulseTriggered(int pin) { return digitalRead(pin) == LOW; }

void returnFloat(const String &tag, float n) {
    Serial.print(tag + ":");
    Serial.print(n);
    Serial.print(";");
}

void returnDouble(const String &tag, double n) {
    Serial.print(tag + ":");
    Serial.print(n);
    Serial.print(";");
}
