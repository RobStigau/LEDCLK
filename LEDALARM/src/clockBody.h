#pragma once

class clockBody {
    private:
        int hour;
        int minute;
        int seconds;
        bool AM_PM;
        unsigned long lastTick;



    public:
        clockBody();

        void update();

        void initializeClock();

        void chooseHour(int inputHour);
        
        void chooseMinute(int inputMinute);

        void chooseAM_PM(int inputAM_PM);


};