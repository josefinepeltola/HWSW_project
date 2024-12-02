#include "sensor.h"
#include "random.h"

// void Sensor::generateSensorData() {
//     int data = Random::spawnNum(); 
// } 

int Sensor::generateSensorData() {
    sensorInput = Random::spawnNum() % 6;
    return sensorInput; 
} 
