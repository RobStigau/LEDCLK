#include "DisplayManager.h"

DisplayManager::DisplayManager() {}


void DisplayManager::begin() {
    tft.init();
    tft.setRotation(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.fillScreen(TFT_RED);
    delay(500);
    tft.fillScreen(TFT_GREEN);
    delay(500);
    tft.fillScreen(TFT_BLUE);
    delay(500);
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(1);
    tft.setTextFont(4);

}

void DisplayManager::clear() {
    tft.fillScreen(TFT_BLACK);
}

void DisplayManager::drawClock() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextFont(4);
    tft.setTextSize(4);
    tft.drawString("1 1 : 3 7", 220, (64*2) + 32);
    tft.setTextSize(1);
    tft.drawString("AM", 420, (64*2));
}


void DisplayManager::drawAlarm(int alarmMenuIndex, int hour, int minute, int AM_PM) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextFont(4);
    tft.setTextSize(4);
    if (hour < 10) {
        if (minute < 10) {
            tft.drawString("0 " + String(hour) + " : " + "0 " + String(minute), 220, 140);
        }
        else {
        tft.drawString("0 " + String(hour) + " : " + String(minute), 220, 140);
        }
    }
    else if (minute < 10) {
        tft.drawString(String(hour) + " : " + "0 " + String(minute), 220, 140);

    }
    else {
        tft.drawString(String(hour) + " : " + String(minute), 220, 140);
    }
    tft.setTextSize(1);
    if (AM_PM == 1) {
        tft.drawString("AM", 420, 108);

    } else {
        tft.drawString("PM", 420, 108);
    }

    
    tft.drawString("APPLY", 120, 64*4);
    tft.drawString("RETURN", 360, 64*4);

    switch(alarmMenuIndex) {
        case 0:
            tft.drawString("---------------", 120, 180);
            break;
        
        case 1:
            tft.drawString("---------------", 320, 180);
            break;

        case 2:
            tft.drawString("----", 420, 128);
            break;

        case 3:
            tft.drawString("---------", 120, (64*4) + 20);
            break;

        case 4:
            tft.drawString("------------", 360, (64*4) + 20);
            break;
        
        default:
            break;
    }
}


void DisplayManager::drawColor(int colorMenuIndex, bool colorOne, bool colorTwo, bool colorThree, bool colorFour, bool colorFive, bool colorSix) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextFont(4);


    tft.fillCircle(120, 64, 35, TFT_DARKGREY);
    tft.fillCircle(120, 64, 25, TFT_RED);


    tft.fillCircle(240, 64, 35, TFT_DARKGREY);
    tft.fillCircle(240, 64, 25, TFT_GREEN);
   
    tft.fillCircle(360, 64, 35, TFT_DARKGREY);
    tft.fillCircle(360, 64, 25, TFT_SKYBLUE);
   
    tft.fillCircle(120, 64*2 + 35, 35, TFT_DARKGREY);
    tft.fillCircle(120, 64*2 + 35, 25, TFT_YELLOW);

    tft.fillCircle(240, 64*2 + 35, 35, TFT_DARKGREY);
    tft.fillCircle(240, 64*2 + 35, 25, TFT_PURPLE);

    tft.fillCircle(360, 64*2 + 35, 35, TFT_DARKGREY);
    tft.fillCircle(360, 64*2 + 35, 25, TFT_PINK);
   
    tft.setTextSize(1);
    tft.drawString("APPLY", 120, 64*4);
    tft.drawString("RETURN", 360, 64*4);

    if (colorOne) {
        tft.fillCircle(120, 64, 35, TFT_DARKGREEN);
        tft.fillCircle(120, 64, 25, TFT_RED);
    }

    else if (colorTwo) {
        tft.fillCircle(240, 64, 35, TFT_DARKGREEN);
        tft.fillCircle(240, 64, 25, TFT_GREEN);
    }

    else if (colorThree) {
        tft.fillCircle(360, 64, 35, TFT_DARKGREEN);
        tft.fillCircle(360, 64, 25, TFT_SKYBLUE);
    }

    else if (colorFour) {
        tft.fillCircle(120, 64*2 + 35, 35, TFT_DARKGREEN);
        tft.fillCircle(120, 64*2 + 35, 25, TFT_YELLOW);
    }

    else if (colorFive) {
        tft.fillCircle(240, 64*2 + 35, 35, TFT_DARKGREEN);
        tft.fillCircle(240, 64*2 + 35, 25, TFT_PURPLE);
    }

    else if (colorSix) {
        tft.fillCircle(360, 64*2 + 35, 35, TFT_DARKGREEN);
        tft.fillCircle(360, 64*2 + 35, 25, TFT_PINK);
    }

    switch(colorMenuIndex) {
        case 0:
            tft.fillCircle(120, 64, 35, TFT_WHITE);
            tft.fillCircle(120, 64, 25, TFT_RED);
            break;

        case 1:
            tft.fillCircle(240, 64, 35, TFT_WHITE);
            tft.fillCircle(240, 64, 25, TFT_GREEN);
            break;

        case 2:
            tft.fillCircle(360, 64, 35, TFT_WHITE);
            tft.fillCircle(360, 64, 25, TFT_SKYBLUE);
            break;

        case 3:
            tft.fillCircle(120, 64*2 + 35, 35, TFT_WHITE);
            tft.fillCircle(120, 64*2 + 35, 25, TFT_YELLOW);
            break;

        case 4:
            tft.fillCircle(240, 64*2 + 35, 35, TFT_WHITE);
            tft.fillCircle(240, 64*2 + 35, 25, TFT_PURPLE);
            break;

        case 5:
            tft.fillCircle(360, 64*2 + 35, 35, TFT_WHITE);
            tft.fillCircle(360, 64*2 + 35, 25, TFT_PINK);
            break;

        case 6:
            tft.drawString("---------", 120, (64*4) + 20);
            break;

        case 7:
            tft.drawString("------------", 360, (64*4) + 20);
            break;







    }

}


void DisplayManager::drawBrightness(int brightnessMenuIndex, int brightnessLevel, int timeToLight) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextFont(4);
    tft.setTextSize(1);
    tft.drawString("Brightness Level:  " + String(brightnessLevel) + "%", 240, 64);
    tft.drawString("Time to Light:  " + String(timeToLight) + " sec", 240, (64*2) + 20);
    tft.setTextSize(1);
    tft.drawString("APPLY", 120, 64*4);
    tft.drawString("RETURN", 360, 64*4);
    
    switch(brightnessMenuIndex) {
        case 0:
            tft.drawString("<", 90, 64);
            tft.drawString(">", 390, 64);
            break;

        case 1:
            tft.drawString("<", 90, (64*2)+ 20);
            tft.drawString(">", 390, (64*2) + 20);
            break;

        case 2:
            tft.drawString("---------", 120, (64*4) + 20);
            break;

        case 3:
            tft.drawString("------------", 360, (64*4) + 20);
            break;

        default:
            break;


    }
}


void DisplayManager::drawSetClock(int setClockMenuIndex, int setHour, int setMinute, int setAM_PM) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextFont(4);
    tft.setTextSize(4);
    if (setHour < 10) {
        if (setMinute < 10) {
            tft.drawString("0 " + String(setHour) + " : " + "0 " + String(setMinute), 220, 140);
        }
        else {
        tft.drawString("0 " + String(setHour) + " : " + String(setMinute), 220, 140);
        }
    }
    else if (setMinute < 10) {
        tft.drawString(String(setHour) + " : " + "0 " + String(setMinute), 220, 140);

    }
    else {
        tft.drawString(String(setHour) + " : " + String(setMinute), 220, 140);
    }
    tft.setTextSize(1);
    if (setAM_PM == 1) {
        tft.drawString("AM", 420, 108);

    } else {
        tft.drawString("PM", 420, 108);
    }

    
    tft.drawString("APPLY", 120, 64*4);
    tft.drawString("RETURN", 360, 64*4);

    switch(setClockMenuIndex) {
        case 0:
            tft.drawString("---------------", 120, 180);
            break;
        
        case 1:
            tft.drawString("---------------", 320, 180);
            break;

        case 2:
            tft.drawString("----", 420, 128);
            break;

        case 3:
            tft.drawString("---------", 120, (64*4) + 20);
            break;

        case 4:
            tft.drawString("------------", 360, (64*4) + 20);
            break;
        
        default:
            break;
    }
}



void DisplayManager::drawMainMenu(int menuIndex) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextFont(4);
    tft.setTextSize(4);
    tft.drawString("2:21", 160, 160);
    tft.setTextSize(1);
    tft.drawString("AM", 280, 128);
    tft.drawString("CLOCK", 400, 64);
    tft.drawString("ALARM", 400, 64*2);
    tft.drawString("BRIGHTNESS", 400, 64*3);
    tft.drawString("COLOR", 400, 64*4);


    switch(menuIndex) {
        case 0:
            tft.drawString("-----------", 400, 64 + 20);
            break;

        case 1:
            tft.drawString("-----------", 400, 64*2 + 20);
            break;

        case 2:
            tft.drawString("--------------------", 400, 64*3 + 20);
            break;

        case 3:
            tft.drawString("----------", 400, 64*4 + 20);
            break;


        default:
            break;

    }
}