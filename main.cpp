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
    // Allocate 9x9 matrix
    int** matrix = new int*[9];
    for(int i = 0; i < 9; i++) {
        matrix[i] = new int[9];
    }
    
    // Create camera with allocated matrix
    Camera cam(matrix);
    
    // Generate and print first matrix
    std::cout << "First matrix generation:" << std::endl;
    matrix = cam.generateCameraData();
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    
    // Generate and print second matrix
    std::cout << "\nSecond matrix generation:" << std::endl;
    matrix = cam.generateCameraData();
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // Cleanup
    for(int i = 0; i < 9; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}