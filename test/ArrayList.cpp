#include "LEADS.h"

const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
ArrayList<int> b = ArrayList<int>(a, 10);
const int c[] = {12, 13};
ArrayList<int> d = ArrayList<int>(c, 2);

void setup() {
    Serial.begin(9600);
    b.add(11);
    b = b + d;
}

void loop() {
    Serial.println(b.size());
    Serial.println(b[11]);
    delay(1000);
}
