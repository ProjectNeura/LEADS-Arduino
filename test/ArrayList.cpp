#include "LEADS.h"

ArrayList<int> test = ArrayList<int>();

void setup() { Serial.begin(9600); }

void loop() {
    test.add(1);
    if (test.size() > 20)
        test.clear();
    Serial.println(test.size());
    delay(100);
}
