// #include "alarmsystem.h"

// // Method intrusionCheck from alarmsystem.h
// // Moved to seperate file for running on hardware

// extern "C" {
//     bool Alarmsystem::intrusionCheck(Sensor sensor1, Sensor sensor2, Camera cam) {
//         int sensorSum = sensor1.generateSensorData() + sensor2.generateSensorData(); 
//         int sum = 0; 
//         for (int i = 0; i < 9; i++) {    
//             for (int j = 0; j < 9; j++) {  
//                 int value = cam.getCameraData(i, j) * sensorSum;
//                 sum = sum + value; 
//             }
//         }
//         if (sum >= 6290) {
//             std::cout << "** Intrusion Detected **" << std::endl; 
//             return true;    // Intrusion detected
//         }
//         else {
//             std::cout << "** Intrusion Not Detected **" << std::endl;
//             return false;   // No intrusion
//         }
//     }
// }

#include "alarmsystem.h"
#include <stdio.h>

int intrusionCheck(struct Sensor* s1, struct Sensor* s2, struct Camera* c) {
    int sensorSum = generateSensorData(s1) + generateSensorData(s2);
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int value = getCameraData(c, i, j) * sensorSum;
            sum += value;
            // printf("sum is", sum);
            if (sum >= 6290) {
                printf("** Intrusion Detected **\n");
                return 1; // Intrusion detected
            }
        }
    } 
    // printf("%d", sum);
    printf("** Intrusion Not Detected **\n");
    return 0; // No intrusion
}

