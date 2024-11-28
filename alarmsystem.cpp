#include "alarmsystem.h"

bool Alarmsystem::valid(int) {
    if (Alarmsystem::spawnPin() % 2) {
        std::cout << "** Pin correct **" << std::endl; 
        return true; 
    }
    else {
        std::cout << "** Pin incorrect. Please try again... **" << std::endl; 
        return false; 
    }
}

bool Alarmsystem::intrusionCheck(int sensor1, int sensor2, int cam[9][9]) {
    int sensorSum = sensor1 + sensor2; 

    for (int i = 0; i < 9; i++) {    
        for (int j = 0; j < 9; j++) { 
            cam[i][j] = cam[i][j] * sensorSum; 
        }
    }
}

void Alarmsystem::alarmOn() {}

void Alarmsystem::controlloop() {
    while(alarmState == active) {
        int s1Data = s1.generateSensorData(); 
        int s2Data = s2.generateSensorData(); 
        // int cData[9][9] = c.generateCameraData(); 

        // if (intrusionCheck(s1Data, s2Data, cData)) {
        //     alarmTriggered(); 
        // }
    }
}

int Alarmsystem::spawnPin() {
    return Random::spawnNum() % 10; 
}

void Alarmsystem::alarmTriggered() {
    alarmState = alarmed; 
    std::cout << "** ALARM TRIGGERED **" << std::endl; 


    time_t start = time(0); 
    long int timeRemaining = 10; 
    int pin = 0; 

    while (timeRemaining > 0 && !valid(pin)) {
        pin = spawnPin(); 
        time_t end = time(0); 
        long int timeUsed = end - start; 
        timeRemaining = 10 - timeUsed; 

        if (valid(pin)) {
            std::cout << "** Valid pin. Alarm was reset... **" << std::endl; 
            alarmState = active; 
            controlloop(); 
            return; 
        } 
    }
    // Time elapsed 
    std::cout << "** Alarm was reset... **" << std::endl; 
    alarmState = active; 
    controlloop();
}

// void Alarmsystem::deactivateAlarm() {}