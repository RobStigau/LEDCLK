#include "clockBody.h"
#include <Arduino.h>
#include "SendData.h"

clockBody::clockBody() {}


void clockBody::update() {

    while (millis() - lastTick >= 1000) {
        lastTick += 1000;
        seconds ++;
    }

    if (seconds >= 60) {
        seconds = 0;
        minute ++;
    }

    if (minute >= 60) {
        minute = 0;
        hour ++;

        if (hour == 12) {
            AM_PM = !AM_PM;
        }
    }

    if (hour > 12) {
        hour = 1;
    }
    
}

void clockBody::initializeClock() {
    hour = 12;
    minute = 0;
    seconds = 0;
    AM_PM = true;
    lastTick = 0;
}

void clockBody::chooseHour(int inputHour) {
    hour = inputHour;
    seconds = 0;
    lastTick = millis();
}

void clockBody::chooseMinute(int inputMinute) {
    minute = inputMinute;
    seconds = 0;
    lastTick = millis();
}

void clockBody::chooseAM_PM(int inputAM_PM) {
    if (inputAM_PM == 1) {
        AM_PM = true;   //AM
    }

    else {
        AM_PM = false;   //PM
    }
    seconds = 0;
    lastTick = millis();

}
