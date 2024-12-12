// #include "sensor.h"
// #include "random.h"

// extern "C" {
//     int Sensor::generateSensorData() {
//         sensorInput = Random::spawnNum() % 6;
//         return sensorInput; 
//     } 
// }

#include "sensor.h"
#include "random.h"

void initSensor(struct Sensor* sensor) {
    sensor->sensorInput = 0;
}

int generateSensorData(struct Sensor* sensor) {
    sensor->sensorInput = spawnNum() % 6;
    return sensor->sensorInput;
}