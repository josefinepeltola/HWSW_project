#include <iostream>
#include <ctime> 
#include "sensor.h"
#include "camera.h"
#include "random.h"

extern "C" {
    class Alarmsystem {
        enum state {inactive, active, alarmed};   
        
        private:  
        state alarmState;
        
        public: 
        Sensor s1;
        Sensor s2; 
        Camera c; 

        Alarmsystem() : alarmState(inactive) {} 
        
        int spawnPin();
        bool valid();
        void alarmInactive();
        void alarmActive(); 
        void controlloop(); 
        bool intrusionCheck(Sensor, Sensor, Camera);  
        void alarmTriggered(); 
        // void deactivateAlarm()
    }; 
}