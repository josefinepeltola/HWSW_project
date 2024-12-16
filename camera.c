// #include "camera.h"
// #include "random.h"

// extern "C" {
//     void Camera::generateCameraData() {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 cameraData[i][j] = Random::spawnNum() % 10; 
//             }
//         }
//     }
// }

#include "camera.h"
#include "random.h"

void initCamera(struct Camera* camera) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            camera->cameraData[i][j] = 0;
         }
    }
}

int getCameraData (struct Camera* camera, int i, int j) {
    generateCameraData(camera);
    return camera->cameraData[i][j];
}

int* getMatrix(struct Camera* camera) {
    generateCameraData(camera);
    return &camera->cameraData[0][0];
}

void generateCameraData(struct Camera* camera) {
    initCamera(camera);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            camera->cameraData[i][j] = spawnNum() % 10;
        }
    }
}