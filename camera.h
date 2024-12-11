#ifndef _CAMERA_H
#define _CAMERA_H

extern "C" {
    class Camera {
        private:
        int cameraData[9][9];
        
        public: 
        Camera() {  // Add default constructor
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    cameraData[i][j] = 0;
                }
            }
        }

        // Get single element at (i,j)
        int getCameraData(int i, int j) { 
            generateCameraData();
            return cameraData[i][j]; 
        }
        
        // Get pointer to first element (for accessing full matrix)
        int* getMatrix() { 
            generateCameraData();
            return &cameraData[0][0]; 
        }
        
        // Fill matrix with random values
        void generateCameraData();
    }; 
}
#endif