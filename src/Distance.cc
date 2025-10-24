#include "Distance.hh"

Distance::Distance() {
    HCSR04.begin(TRIGGER_PIN, ECHO_PINS, ECHO_COUNT);
}

double Distance::measure() {
    double* distances = HCSR04.measureDistanceCm();

    return distances[0];
}