#ifndef _CAMERA_H   
#define _CAMERA_H

struct Camera {
    int cameraData[9][9];
};

void initCamera(struct Camera* camera);

int getCameraData(struct Camera* camera, int i, int j);

int* getMatrix(struct Camera* camera);

void generateCameraData(struct Camera* camera);

#endif