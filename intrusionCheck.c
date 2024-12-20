#include "alarmsystem.h"
#include <stdio.h>
int intrusionCheck(struct Sensor* s1, struct Sensor* s2, struct Camera* c) {
    int sum = 0;
    int sensorSum = generateSensorData(s1) + generateSensorData(s2);
    generateCameraData(c);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int value = c->cameraData[i][j] * sensorSum;
            sum += value;

            if (sum >= 2000) {
                printf("** Intrusion Detected **\n");
                return 1; // Intrusion detected
            }
        }
    }

    printf("** Intrusion Not Detected **\n");
    return 0; // No intrusion
}
