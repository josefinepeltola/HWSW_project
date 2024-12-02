#include "alarmsystem.h"

int Alarmsystem::spawnPin() {
    return Random::spawnNum() % 10; 
}


bool Alarmsystem::valid() {
    if (Alarmsystem::spawnPin() % 2) {
        std::cout << "** Pin correct **" << std::endl; 
        return true; 
    }
    else {
        std::cout << "** Pin incorrect. Please try again... **" << std::endl; 
        return false; 
    }
}


void Alarmsystem::alarmInactive() {
    alarmState = inactive;

    while (alarmState == inactive) {
        if (valid()) {
            alarmActive(); 
        }
    }
}


void Alarmsystem::alarmActive() {
    alarmState = active;
    controlloop(); 
}


void Alarmsystem::controlloop() {
    while (alarmState == active) {
        s1.generateSensorData();
        s2.generateSensorData();
        c.generateCameraData();

        if (intrusionCheck(s1, s2, c)) {
            alarmTriggered(); 
        }
    }
}


bool Alarmsystem::intrusionCheck(Sensor sensor1, Sensor sensor2, Camera cam) {
    int sensorSum = sensor1.generateSensorData() + sensor2.generateSensorData(); 
    int sum = 0; 
    for (int i = 0; i < 9; i++) {    
        for (int j = 0; j < 9; j++) {  
            int value = cam.getCameraData(i, j) * sensorSum;
            sum = sum + value; 
        }
    }
    if (sum >= 6290) {
        std::cout << "** Intrusion Detected **" << std::endl; 
        return true;    // Intrusion detected
    }
    else {
        std::cout << "** Intrusion Not Detected **" << std::endl;
        return false;   // No intrusion
    }
}


void Alarmsystem::alarmTriggered() {
    alarmState = alarmed; 
    std::cout << "** ALARM TRIGGERED **" << std::endl; 


    time_t start = time(0); 
    long int timeRemaining = 10; 
    int pin = 0; 

    while (timeRemaining > 0 && !valid()) {
        time_t end = time(0); 
        long int timeUsed = end - start; 
        timeRemaining = 10 - timeUsed; 

        if (valid()) {
            std::cout << "** Valid pin. Alarm was reset... **" << std::endl; 
            alarmActive(); 
        } 
    }
    // Time elapsed 
    std::cout << "** Alarm was reset... **" << std::endl; 
    alarmActive(); 
}
