#ifndef _SENSOR_H   
#define _SENSOR_H

struct Sensor {
    int sensorInput;
};

    void initSensor(struct Sensor* sensor);
    int generateSensorData(struct Sensor* sensor);

#endif