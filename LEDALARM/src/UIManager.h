#pragma once
#include "View.h"
#include "DisplayManager.h"
#include "clockBody.h"


class UIManager {
    private:
        View currentView;
        int selectedIndex;
        int mainMenuIndex;
        int setClockMenuIndex;
        int alarmMenuIndex;
        int brightnessMenuIndex;
        int colorMenuIndex;
        
        bool editingBrightness;
        bool editingTimeToLight;

        int brightnessLevel;
        int timeToLight;

        bool editingHour;
        bool editingMinute;
        bool editingAM_PM;

        int hour;
        int minute;
        int AM_PM;

        bool colorOne;
        bool colorTwo;
        bool colorThree;
        bool colorFour;
        bool colorFive;
        bool colorSix;

        bool settingHour;
        bool settingMinute;
        bool settingAM_PM;

        int setHour;
        int setMinute;
        int setAM_PM;


    public:
        UIManager();


        void begin();

        void handleRotation(int direction);

        void handlePress(clockBody& clock);

        void draw(DisplayManager& display, clockBody& clock);

        void setClockValues(clockBody& clockBody, int setHour, int setMinute, int setAM_PM);
        void moveMainMenu(int direction);

        void moveSetClockMenu(int direction);

        void moveAlarmMenu(int direction);
        void moveBrightnessMenu(int direction);
        void moveColorMenu(int direction);



        int getAlarmHour() const;

        int getAlarmMinute() const;

        bool getAlarmAM_PM() const;

        int getBrightnessLevel() const;

        int getColor() const;

        int getTimeToBright() const;


};