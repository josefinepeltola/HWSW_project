#include <stdio.h>
#include <iostream>
#include <fstream>
#include "alarmsystem.h"
#include "random.h"


int main() {
    typedef int test_t;
    test_t test_results[10];
    test_t expected_results[10];
    int retval = 0;
    FILE *fp;

    std::cout << "=== Alarm System Testbench ===" << std::endl;
    
    // Initialize test vectors
    Alarmsystem alarm;
    for(int i = 0; i < 10; i++) {
        // Generate sensor and camera data
        alarm.s1.generateSensorData();
        alarm.s2.generateSensorData();
        alarm.c.generateCameraData();
        
        // Test intrusion detection
        bool intrusion = alarm.intrusionCheck(alarm.s1, alarm.s2, alarm.c);
        test_results[i] = intrusion ? 1 : 0;
        
        // Alternate between expected intrusion/no intrusion
        expected_results[i] = i % 2;
    }

    // Save results
    fp = fopen("alarm_result.dat", "w");
    std::cout << "Test\tExpected\tActual\n";
    for(int i = 0; i < 10; i++) {
        fprintf(fp, "%d\n", test_results[i]);
        std::cout << i << "\t" << expected_results[i] << "\t\t" << test_results[i] << std::endl;
    }
    fclose(fp);

    // Compare with golden results
    retval = system("diff --brief -w alarm_result.dat alarm_result.golden.dat");
    if (retval != 0) {
        std::cout << "Test failed!\n";
        retval = 1;
    } else {
        std::cout << "Test passed!\n";
    }

    return retval;
}