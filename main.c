// #include <iostream>
// #include "alarmsystem.h"

// int main() {
//     std::cout << "=== Testing Alarm System ===" << std::endl;
    
//     Alarmsystem alarm;

//     alarm.alarmInactive(); 
    

//     return 0;
// }

#include <stdio.h>
#include "alarmsystem.h"

int main() {
    printf("=== Testing Alarm System ===\n");
    
    struct AlarmSystem alarm;
    initAlarmSystem(&alarm);

    alarmInactive(&alarm); 

    return 0;
}