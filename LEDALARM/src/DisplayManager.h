#pragma once

#include <TFT_eSPI.h>

class DisplayManager {
    private:
        TFT_eSPI tft;

    public:
        DisplayManager();

        void drawMainMenu(int menuIndex, int hour, int minute, bool AM_PM);

        void drawClock(int hour, int minute, bool AM_PM);


        void begin();

        void clear();

        void drawColor(int colorMenuIndex, bool colorOne, bool colorTwo, bool colorThree, bool colorFour, bool colorFive, bool colorSix);
        
        void drawAlarm(int AlarmMenuIndex, int hour, int minute, int AM_PM);

        void drawSetClock(int SetClockMenuIndex, int setHour, int setMinute, int setAM_PM);

        void drawBrightness(int brightnessMenuIndex, int brightnessLevel, int timeToLight);

    
};