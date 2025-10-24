#ifndef DISTANCE_HH
#define DISTANCE_HH

#include <HCSR04.h>

class Distance {
private:
    uint8_t TRIGGER_PIN = 2;
    uint8_t ECHO_COUNT = 1;
    uint8_t ECHO_PINS[1] = {3};
public:
    Distance();
    double measure();
};

#endif