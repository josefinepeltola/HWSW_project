#include "alarmsystem.h"

// Method intrusionCheck from alarmsystem.h
// Moved to seperate file for running on hardware
bool Alarmsystem::intrusionCheck(Sensor sensor1, Sensor sensor2, Camera cam) {
    int sensorSum = sensor1.generateSensorData() + sensor2.generateSensorData(); 
    int sum = 0; 
    for (int i = 0; i < 9; i++) {    
        for (int j = 0; j < 9; j++) {  
            int value = cam.getCameraData(i, j) * sensorSum;
            sum = sum + value; 
        }
    }
    if (sum >= 600) {
        std::cout << "** Intrusion Detected **" << std::endl; 
        return true;    // Intrusion detected
    }
    else {
        std::cout << "** Intrusion Not Detected **" << std::endl;
        return false;   // No intrusion
    }
}