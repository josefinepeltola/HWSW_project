#include <stdio.h>
#include <stdlib.h>
#include "alarmsystem.h"
#include "random.h"

int main() {
    int test_results[10];
    int expected_results[10];
    int retval = 0;
    FILE *fp;

    printf("=== Alarm System Testbench ===\n");

    // Initialize test vectors
    struct AlarmSystem alarm;
    initAlarmSystem(&alarm);
    for (int i = 0; i < 10; i++) {
        // Generate sensor and camera data
        generateSensorData(&alarm.s1);
        generateSensorData(&alarm.s2);
        generateCameraData(&alarm.c);

        // Test intrusion detection
        int intrusion = intrusionCheck(&alarm.s1, &alarm.s2, &alarm.c);
        test_results[i] = intrusion ? 1 : 0;
    }

    // Read expected results from golden file
    fp = fopen("alarm_result.golden.dat", "r");
    if (fp == NULL) {
        printf("Error: Could not open golden results file.\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        fscanf(fp, "%d", &expected_results[i]);
    }
    fclose(fp);

    // Save results
    fp = fopen("alarm_result.dat", "w");
    printf("\n====== Results: ======\n"); 
    printf("Expected\tActual\n");
    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%d\n", test_results[i]);
        printf("   %d\t\t  %d\n", expected_results[i], test_results[i]);
    }
    fclose(fp);

    // Compare results
    for (int i = 0; i < 10; i++) {
        if (test_results[i] != expected_results[i]) {
            printf("Test failed at index %d: expected %d, got %d\n", i, expected_results[i], test_results[i]);
            retval = 1;
        }
    }

    if (retval == 0) {
        printf("All tests passed!\n");
    }

    return retval;
}