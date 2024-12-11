#include "camera.h"
#include "random.h"

extern "C" {
    void Camera::generateCameraData() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cameraData[i][j] = Random::spawnNum() % 10; 
            }
        }
    }
} 