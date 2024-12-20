#include <stdio.h>
#include "alarmsystem.h"

// Main driver for the alarm system 
int main() {
    printf("=== Testing Alarm System ===\n");
    
    struct AlarmSystem alarm;
    initAlarmSystem(&alarm);

    alarmInactive(&alarm); 

    return 0;
}