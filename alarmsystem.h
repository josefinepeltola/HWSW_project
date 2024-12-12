// #include <iostream>
// #include <ctime> 
// #include "sensor.h"
// #include "camera.h"
// #include "random.h"

// extern "C" {
//     class Alarmsystem {
//         enum state {inactive, active, alarmed};   
        
//         private:  
//         state alarmState;
        
//         public: 
//         Sensor s1;
//         Sensor s2; 
//         Camera c; 

//         Alarmsystem() : alarmState(inactive) {} 
        
//         int spawnPin();
//         bool valid();
//         void alarmInactive();
//         void alarmActive(); 
//         void controlloop(); 
//         bool intrusionCheck(Sensor, Sensor, Camera);  
//         void alarmTriggered(); 
//         // void deactivateAlarm()
//     }; 
// }

#ifndef _ALARMSYSTEM_H
#define _ALARMSYSTEM_H

#include <time.h>
#include "sensor.h"
#include "camera.h"
#include "random.h"

struct AlarmSystem {
    enum state {inactive, active, alarmed} alarmState;
    struct Sensor s1;
    struct Sensor s2;
    struct Camera c;
};

// Initialize the AlarmSystem
void initAlarmSystem(struct AlarmSystem* alarm);

// Generate a random pin
int spawnPin();

// Check if the pin is valid
int valid(struct AlarmSystem* alarm);

// Set the alarm to inactive state
void alarmInactive(struct AlarmSystem* alarm);

// Set the alarm to active state
void alarmActive(struct AlarmSystem* alarm);

// Control loop for the alarm system
void controlLoop(struct AlarmSystem* alarm);

// Check for intrusion
int intrusionCheck(struct Sensor* s1, struct Sensor* s2, struct Camera* c);

// Trigger the alarm
void alarmTriggered(struct AlarmSystem* alarm);

#endif