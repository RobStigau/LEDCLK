#pragma once
#include "View.h"
#include "DisplayManager.h"


class UIManager {
    private:
        View currentView;
        int selectedIndex;
        int mainMenuIndex;
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


    public:
        UIManager();


        void begin();

        void handleRotation(int direction);

        void handlePress();

        void draw(DisplayManager& display);


        void moveMainMenu(int direction);

        void moveAlarmMenu(int direction);
        void moveBrightnessMenu(int direction);
        void moveColorMenu(int direction);


};