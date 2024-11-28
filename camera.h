#ifndef _CAMERA_H
#define _CAMERA_H

class Camera {
    private:
    int** cameraData;
    
    public: 
    // int getCameraData(int i, int j) const { return cameraData[i][j]; }     // constructor 
    Camera(int** cameraData) : cameraData(cameraData) {}

    int** generateCameraData(); 
    // int* getData(); 
}; 

#endif