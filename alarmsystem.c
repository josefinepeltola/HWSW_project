#include "alarmsystem.h"
#include <stdio.h>

void initAlarmSystem(struct AlarmSystem* alarm) {
    alarm->alarmState = inactive;
    initSensor(&alarm->s1);
    initSensor(&alarm->s2);
    initCamera(&alarm->c);
}

int spawnPin() {
    return spawnNum() % 10;
}

int valid(struct AlarmSystem* alarm) {
    if (spawnPin() % 2) {
        printf("** Pin correct **\n");
        return 1;
    } else {
        printf("** Pin incorrect. Please try again... **\n");
        return 0;
    }
}

void alarmInactive(struct AlarmSystem* alarm) {
    alarm->alarmState = inactive;
    printf("=== Powering alarmsystem on... ===\n");

    while (alarm->alarmState == inactive) {
        if (valid(alarm)) {
            printf("** Pin correct. Alarm active **\n");
            alarmActive(alarm);
        }
    }
}

void alarmActive(struct AlarmSystem* alarm) {
    alarm->alarmState = active;
    controlLoop(alarm);
}

void controlLoop(struct AlarmSystem* alarm) {
    while (alarm->alarmState == active) {
        if (intrusionCheck(&alarm->s1, &alarm->s2, &alarm->c)) {
            alarmTriggered(alarm);
        }
    }
}

void alarmTriggered(struct AlarmSystem* alarm) {
    alarm->alarmState = alarmed;
    printf("** ALARM TRIGGERED **\n");

    time_t start = time(0);
    long int timeRemaining = 10;

    while (timeRemaining > 0 && !valid(alarm)) {
        time_t end = time(0);
        long int timeUsed = end - start;
        timeRemaining = 10 - timeUsed;

        if (valid(alarm)) {
            printf("=== Alarm was reset... ===\n\n");
            alarmActive(alarm);
        }
    }
    // Time elapsed
    printf("=== Alarm was reset... ===\n\n");
    alarmActive(alarm);
}