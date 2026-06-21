#include "clockBody.h"
#include <Arduino.h>

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
    }

    if (hour > 12) {
        hour = 1;
        AM_PM = !AM_PM;
    }
}

void clockBody::initializeClock() {
    hour = 0;
    minute = 0;
    seconds = 0;
    AM_PM = false;
    lastTick = 0;
}

void clockBody::chooseHour(int inputHour) {
    hour = inputHour;
}

void clockBody::chooseMinute(int inputMinute) {
    minute = inputMinute;
}

void clockBody::chooseAM_PM(int inputAM_PM) {
    if (inputAM_PM == 1) {
        AM_PM = true;   //AM
    }

    else {
        AM_PM = false;   //PM
    }

}

