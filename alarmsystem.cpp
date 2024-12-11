#include "alarmsystem.h"

extern "C" {
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
        std::cout << "=== Powering alarmsystem on... ===" << std::endl;

        while (alarmState == inactive) {
            if (valid()) {
                std::cout << "** Pin corret. Alarm active **" << std::endl;
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

            // sleep(2); 

            if (intrusionCheck(s1, s2, c)) {
                alarmTriggered(); 
            }
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
                std::cout << "=== Alarm was reset... ===\n\n" << std::endl; 
                alarmActive(); 
            } 
        }
        // Time elapsed 
        std::cout << "=== Alarm was reset... ===\n\n" << std::endl; 
        alarmActive(); 
    }
}