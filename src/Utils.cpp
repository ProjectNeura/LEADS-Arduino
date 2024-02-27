#include "Utils.h"

bool pulseTriggered(int pin) { return digitalRead(pin) == LOW; }

bool equivalent(float a, float b, float epsilon) { return fabs(a - b) <= epsilon * max(fabs(a), fabs(b)); }

bool equivalent(long a, long b, float epsilon) { return fabs(a - b) <= epsilon * max(fabs(a), fabs(b)); }

void returnFloat(String header, float n) {
	Serial.print(header + ":");
    Serial.print(n);
    Serial.print(";");
}
