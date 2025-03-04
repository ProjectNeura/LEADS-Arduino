#include "Accelerometer.h"

String Acceleration::toString() {
    return String(yaw) + "," + pitch + "," + roll + "," + forwardAcceleration + "," + lateralAcceleration + "," +
           verticalAcceleration;
}
