// #include <stdio.h>
// #include <iostream>
// #include <fstream>
// #include "alarmsystem.h"
// #include "random.h"

//     int main() {
//         typedef int test_t;
//         test_t test_results[10];
//         test_t expected_results[10];
//         int retval = 0;
//         FILE *fp;

//         std::cout << "=== Alarm System Testbench ===" << std::endl;
        
//         // Initialize test vectors
//         Alarmsystem alarm;
//         for(int i = 0; i < 10; i++) {
//             // Generate sensor and camera data
//             alarm.s1.generateSensorData();
//             alarm.s2.generateSensorData();
//             alarm.c.generateCameraData();
            
//             // Test intrusion detection
//             bool intrusion = alarm.intrusionCheck(alarm.s1, alarm.s2, alarm.c);
//             test_results[i] = intrusion ? 1 : 0;
            
//             // Alternate between expected intrusion/no intrusion
//             expected_results[i] = i % 2;
//         }

//         // Save results
//         fp = fopen("alarm_result.dat", "w");
//         std::cout << "Test\tExpected\tActual\n";
//         for(int i = 0; i < 10; i++) {
//             fprintf(fp, "%d\n", test_results[i]);
//             std::cout << i << "\t" << expected_results[i] << "\t\t" << test_results[i] << std::endl;
//         }
//         fclose(fp);

//         // Compare with golden results
//         retval = system("diff --brief -w alarm_result.dat alarm_result.golden.dat");
//         if (retval != 0) {
//             std::cout << "Test failed!\n";
//             retval = 1;
//         } else {
//             std::cout << "Test passed!\n";
//         }

//         return retval;
//     }

// // // alarmsystem_test.c
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include "alarmsystem.h"

// // // Forward declarations from C++ code
// // #ifdef __cplusplus
// // extern "C" {
// // #endif
// //     typedef struct Sensor Sensor;
// //     typedef struct Camera Camera;
// //     extern int intrusionCheck(Sensor* s1, Sensor* s2, Camera* c);
// //     extern void generateSensorData(Sensor* s);
// //     extern void generateCameraData(Camera* c);
// // #ifdef __cplusplus
// // }
// // #endif

// // int main() {
// //     int i, retval=0;
// //     FILE *fp;
// //     Sensor sensor1, sensor2;
// //     Camera camera;
// //     int test_results[10];

// //     printf("=== Alarm System Test ===\n");

// //     // Run 10 test cases
// //     for(i = 0; i < 10; i++) {
// //         generateSensorData(&sensor1);
// //         generateSensorData(&sensor2);
// //         generateCameraData(&camera);
        
// //         test_results[i] = intrusionCheck(&sensor1, &sensor2, &camera);
// //     }

// //     // Save results
// //     fp = fopen("alarm_result.dat", "w");
// //     printf("Test\tResult\n");
// //     for(i = 0; i < 10; i++) {
// //         fprintf(fp, "%d\n", test_results[i]);
// //         printf("%d\t%d\n", i, test_results[i]);
// //     }
// //     fclose(fp);

// //     // Compare with golden results
// //     retval = system("diff --brief -w alarm_result.dat alarm_result.golden.dat");
// //     if (retval != 0) {
// //         printf("Test failed!\n");
// //         retval = 1;
// //     } else {
// //         printf("Test passed!\n");
// //     }

// //     return retval;
// // }


#include <stdio.h>
#include <stdlib.h>

// Forward declarations for C++ functions
extern int intrusionCheck(void* s1, void* s2, void* c);
extern void generateSensorData(void* s);
extern void generateCameraData(void* c);

int main() {
    int i, retval = 0;
    FILE *fp;
    char sensor1[sizeof(void*)];
    char sensor2[sizeof(void*)];
    char camera[sizeof(void*) * 81]; // 9x9 matrix
    int test_results[10];

    printf("=== Alarm System Test ===\n");

    // Run test cases
    for(i = 0; i < 10; i++) {
        generateSensorData(&sensor1);
        generateSensorData(&sensor2);
        generateCameraData(&camera);
        
        test_results[i] = intrusionCheck(&sensor1, &sensor2, &camera);
    }

    // Save results
    fp = fopen("alarm_result.dat", "w");
    printf("Test\tResult\n");
    for(i = 0; i < 10; i++) {
        fprintf(fp, "%d\n", test_results[i]);
        printf("%d\t%d\n", i, test_results[i]);
    }
    fclose(fp);

    // Compare with golden results
    retval = system("diff --brief -w alarm_result.dat alarm_result.golden.dat");
    if (retval != 0) {
        printf("Test failed!\n");
        retval = 1;
    } else {
        printf("Test passed!\n");
    }

    return retval;
}