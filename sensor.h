#ifndef _SENSOR_H
#define _SENSOR_H

class Sensor {
    private:
    int sensorInput; 
    
    public:
    Sensor() : sensorInput(0) {}     // constructor 

    int generateSensorData(); 
    // int getData(); 
}; 

#endif