// #include "alarmsystem.h"

// extern "C" {
//     int Alarmsystem::spawnPin() {
//         return Random::spawnNum() % 10; 
//     }


//     bool Alarmsystem::valid() {
//         if (Alarmsystem::spawnPin() % 2) {
//             std::cout << "** Pin correct **" << std::endl; 
//             return true; 
//         }
//         else {
//             std::cout << "** Pin incorrect. Please try again... **" << std::endl; 
//             return false; 
//         }
//     }


//     void Alarmsystem::alarmInactive() {
//         alarmState = inactive;
//         std::cout << "=== Powering alarmsystem on... ===" << std::endl;

//         while (alarmState == inactive) {
//             if (valid()) {
//                 std::cout << "** Pin corret. Alarm active **" << std::endl;
//                 alarmActive(); 
//             }
//         }
//     }


//     void Alarmsystem::alarmActive() {
//         alarmState = active;
//         controlloop(); 
//     }


//     void Alarmsystem::controlloop() {
//         while (alarmState == active) {
//             s1.generateSensorData();
//             s2.generateSensorData();
//             c.generateCameraData();

//             // sleep(2); 

//             if (intrusionCheck(s1, s2, c)) {
//                 alarmTriggered(); 
//             }
//         }
//     }


//     void Alarmsystem::alarmTriggered() {
//         alarmState = alarmed; 
//         std::cout << "** ALARM TRIGGERED **" << std::endl; 


//         time_t start = time(0); 
//         long int timeRemaining = 10; 
//         int pin = 0; 

//         while (timeRemaining > 0 && !valid()) {
//             time_t end = time(0); 
//             long int timeUsed = end - start; 
//             timeRemaining = 10 - timeUsed; 

//             if (valid()) {
//                 std::cout << "=== Alarm was reset... ===\n\n" << std::endl; 
//                 alarmActive(); 
//             } 
//         }
//         // Time elapsed 
//         std::cout << "=== Alarm was reset... ===\n\n" << std::endl; 
//         alarmActive(); 
//     }
// }

#include "alarmsystem.h"
#include <stdio.h>

void initAlarmSystem(struct AlarmSystem* alarm) {
    alarm->alarmState = inactive;
    initSensor(&alarm->s1);
    initSensor(&alarm->s2);
    initCamera(&alarm->c);
}

int spawnPin() {
    return spawnNum() % 10;
}

int valid(struct AlarmSystem* alarm) {
    if (spawnPin() % 2) {
        printf("** Pin correct **\n");
        return 1;
    } else {
        printf("** Pin incorrect. Please try again... **\n");
        return 0;
    }
}

void alarmInactive(struct AlarmSystem* alarm) {
    alarm->alarmState = inactive;
    printf("=== Powering alarmsystem on... ===\n");

    while (alarm->alarmState == inactive) {
        if (valid(alarm)) {
            printf("** Pin correct. Alarm active **\n");
            alarmActive(alarm);
        }
    }
}

void alarmActive(struct AlarmSystem* alarm) {
    alarm->alarmState = active;
    controlLoop(alarm);
}

void controlLoop(struct AlarmSystem* alarm) {
    while (alarm->alarmState == active) {
        // generateSensorData(&alarm->s1);
        // generateSensorData(&alarm->s2);
        // generateCameraData(&alarm->c);
    //    int sensor1 = generateSensorData(&alarm->s1);
    //    int sensor2 = generateSensorData(&alarm->s2);


        // sleep(2);

        if (intrusionCheck(&alarm->s1, &alarm->s2, &alarm->c)) {
            alarmTriggered(alarm);
        }
    }
}

void alarmTriggered(struct AlarmSystem* alarm) {
    alarm->alarmState = alarmed;
    printf("** ALARM TRIGGERED **\n");

    time_t start = time(0);
    long int timeRemaining = 10;

    while (timeRemaining > 0 && !valid(alarm)) {
        time_t end = time(0);
        long int timeUsed = end - start;
        timeRemaining = 10 - timeUsed;

        if (valid(alarm)) {
            printf("=== Alarm was reset... ===\n\n");
            alarmActive(alarm);
        }
    }
    // Time elapsed
    printf("=== Alarm was reset... ===\n\n");
    alarmActive(alarm);
}