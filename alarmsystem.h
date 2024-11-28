#include <iostream>
#include <ctime> 
#include "sensor.h"
#include "camera.h"
#include "random.h"

class Alarmsystem {
    enum state {inactive, active, alarmed};   
    
    private:  
    state alarmState;
    
    public: 
    Sensor s1;
    Sensor s2; 
    Camera c; 
    
    bool valid(int);
    bool intrusionCheck(int, int, int[9][9]); 
    void alarmOn(); 
    void controlloop(); 
    int spawnPin();
    void alarmTriggered(); 
    // void deactivateAlarm();
}; 
