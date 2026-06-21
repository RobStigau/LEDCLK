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

        void setHour(int inputHour);
        
        void setMinute(int inputMinute);

        void setAM_PM(int inputAM_PM);


};