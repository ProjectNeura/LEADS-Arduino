#include "Utils.h"

bool pulseTriggered(int pin) { return digitalRead(pin) == LOW; }

bool equivalent(float a, float b, float epsilon) { return abs(a - b) <= epsilon * max(abs(a), abs(b)); }

bool equivalent(long a, long b, float epsilon) { return labs(a - b) <= epsilon * max(labs(a), labs(b)); }

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
