#include "sensor.h"
#include "random.h"

extern "C" {
    int Sensor::generateSensorData() {
        sensorInput = Random::spawnNum() % 6;
        return sensorInput; 
    } 
}