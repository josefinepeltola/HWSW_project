#include <iostream>
// #include "random.h"
#include "alarmsystem.h"

// int main() {
//     Sensor sensor;
    
//     std::cout << "Generating 10 sensor readings:" << std::endl;
//     for(int i = 0; i < 10; i++) {
//         std::cout << "Reading " << i << ": " << sensor.generateSensorData() << std::endl;
//     }

//     return 0;
// }


int main() {
    Camera cam;  // Uses default constructor
    
    // First matrix
    std::cout << "=== First Matrix ===" << std::endl;
    // cam.generateCameraData();
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << cam.getCameraData(i,j) << "  ";
        }
        std::cout << std::endl;
    }
    
    // Second matrix after brief delay
    // sleep(1);  // Wait 1 second for different random seed
    std::cout << "\n=== Second Matrix ===" << std::endl;
    // cam.generateCameraData();
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << cam.getCameraData(i,j) << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}