#include <iostream>
#include <unistd.h> // for sleep function
#include "alarmsystem.h"

int main() {
    std::cout << "=== Testing Alarm System ===" << std::endl;
    
    Alarmsystem alarm;

    alarm.alarmInactive(); 
    
    // // Test pin validation
    // std::cout << "\nTesting PIN validation:" << std::endl;
    // for(int i = 0; i < 3; i++) {
    //     std::cout << "Attempt " << i+1 << ": ";
    //     if (alarm.valid())
    //     alarm.valid();
    //     sleep(1);
    // }
    
    // // Test intrusion detection
    // std::cout << "\nTesting intrusion detection:" << std::endl;
    // for(int i = 0; i < 3; i++) {
    //     std::cout << "Test " << i+1 << ": ";
    //     bool result = alarm.intrusionCheck(alarm.s1, alarm.s2, alarm.c);
    //     std::cout << "Intrusion detected: " << (result ? "Yes" : "No") << std::endl;
    //     sleep(1);
    // }
    
    // // Test full alarm system flow
    // std::cout << "\nTesting full alarm system flow:" << std::endl;
    // std::cout << "Starting in inactive state..." << std::endl;
    // sleep(1);
    
    // // This will start the alarm system state machine
    // alarm.alarmInactive();
    
    return 0;
}