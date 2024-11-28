#include "camera.h"
#include "random.h"

int** Camera::generateCameraData() {
    // brug random
    // random int 0-9 i 9x9 matrix
    cameraData = new int*[9];
    for (int i = 0; i < 9; i++) {
        cameraData[i] = new int[9];
        for (int j = 0; j < 9; j++) {
            cameraData[i][j] = Random::spawnNum() % 10; 
        }
    }
    return cameraData; 
} 

// int* Camera::getData() {
//     // return generateCameraData(); 
// } 