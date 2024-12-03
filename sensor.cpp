#include "sensor.h"
#include "random.h"

int Sensor::generateSensorData() {
    sensorInput = Random::spawnNum() % 6;
    return sensorInput; 
} 
