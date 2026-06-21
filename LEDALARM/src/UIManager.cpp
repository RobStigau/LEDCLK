#include "UIManager.h"


UIManager::UIManager()
    : currentView(View::CLOCK_MENU),
      mainMenuIndex(0),
      setClockMenuIndex(0),
      alarmMenuIndex(0),
      brightnessMenuIndex(0),
      colorMenuIndex(0),
      editingBrightness(false),
      editingTimeToLight(false),
      brightnessLevel(50),
      timeToLight(10),
      editingHour(false),
      editingMinute(false),
      editingAM_PM(false),
      hour(0),
      minute(0),
      AM_PM(0),
      colorOne(true),
      colorTwo(false),
      colorThree(false),
      colorFour(false),
      colorFive(false),
      colorSix(false),
      settingHour(false),
      settingMinute(false),
      settingAM_PM(false),
      setHour(0),
      setMinute(0),
      setAM_PM(0)

{
}


void UIManager::begin() {
    currentView = View::CLOCK_MENU;
    mainMenuIndex = 0;
    setClockMenuIndex = 0;
    alarmMenuIndex = 0;
    brightnessMenuIndex = 0;
    colorMenuIndex = 0;


}


void UIManager::handleRotation(int direction) {
    switch(currentView) {
        case View::MAIN_MENU:
            moveMainMenu(direction);
            break;

        case View::SET_CLOCK_MENU:
            if (settingHour) {
                setHour += direction;
                

            if (setHour < 0) {
                    setHour = 0;
                }

                if (setHour > 12) {
                    setHour = 12;
                }
            }

            else if (settingMinute) {
                setMinute += direction;

                if (setMinute > 59) {
                    setMinute = 59;
                }

                if (setMinute < 0) {
                    setMinute = 0;
                }
            }



            else if (settingAM_PM) {
                setAM_PM += direction;

                if(setAM_PM < 0) {
                    setAM_PM = 0;
                }

                if(setAM_PM > 1) {
                    setAM_PM = 1;
                }

            } else {
                moveSetClockMenu(direction);
            }

            break;

        case View::ALARM_MENU:
            if (editingHour) {
                hour += direction;

               if (hour < 0) {
                    hour = 0;
                }

                if (hour > 12) {
                    hour = 12;
                }
            }

            else if (editingMinute) {
                minute += direction;

                if (minute > 59) {
                    minute = 59;
                }

                if (minute < 0) {
                    minute = 0;
                }
            }



            else if (editingAM_PM) {
                AM_PM += direction;

                if(AM_PM < 0) {
                    AM_PM = 0;
                }

                if(AM_PM > 1) {
                    AM_PM = 1;
                }

            } else {
                moveAlarmMenu(direction);
            }

            break;


        case View::BRIGHTNESS_MENU:
            if (editingBrightness) {
                brightnessLevel += direction;

                if (brightnessLevel < 0) {
                    brightnessLevel = 0;
                }
                
                if (brightnessLevel > 100) {
                    brightnessLevel = 100;
                }
            }

            else if(editingTimeToLight) {
                timeToLight += direction;

                if (timeToLight < 5) {
                    timeToLight = 5;
                }

                if (timeToLight > 20) {
                    timeToLight = 20;
                }

            } else {
                moveBrightnessMenu(direction);

            }
            break;


        case View::COLOR_MENU:
            moveColorMenu(direction);
            break;
        

        default:
            break;
    }


}

void UIManager::setClockValues(clockBody& clockBody, int setHour, int setMinute, int setAM_PM) {
    clockBody.chooseHour(setHour);
    clockBody.chooseMinute(setMinute);
    clockBody.chooseAM_PM(setAM_PM);
}

void UIManager::handlePress(clockBody& clock) {
    switch(currentView) {

        case View::MAIN_MENU:
            switch(mainMenuIndex) {
                case 0:
                    currentView = View::CLOCK_MENU;
                    break;

                case 1:
                    currentView = View::ALARM_MENU;
                    break;

                case 2:
                    currentView = View::BRIGHTNESS_MENU;
                    break;
                
                case 3:
                    currentView = View::COLOR_MENU;
                    break;
                
                case 4:
                    currentView = View::SET_CLOCK_MENU;
                    break;
                
                default:
                    break;
            }
            break;

        case View::CLOCK_MENU:
            currentView = View::MAIN_MENU;
            break;

       case View::SET_CLOCK_MENU:
            switch(setClockMenuIndex) {
                case 0:
                    settingHour = !settingHour;
                    settingMinute = false;
                    settingAM_PM = false;
                    break;
                
                case 1:
                    settingMinute = !settingMinute;
                    settingHour = false;
                    settingAM_PM = false;
                    break;

                case 2:
                    settingAM_PM = !settingAM_PM;
                    settingHour = false;
                    settingMinute = false;
                    break;

                case 3:
                    settingHour = false;
                    settingMinute = false;
                    settingAM_PM = false;
                    setClockValues(clock, setHour, setMinute, setAM_PM);
                    //applychanges
                    break;

                case 4:
                    setClockMenuIndex = 0;
                    settingHour = false;
                    settingMinute = false;
                    settingAM_PM = false;
                    currentView = View::MAIN_MENU;
                    break;

                default:
                    break;
            }
            break;

            

        case View::ALARM_MENU:
            switch(alarmMenuIndex) {
                case 0:
                    editingHour = !editingHour;
                    editingMinute = false;
                    editingAM_PM = false;
                    break;
                
                case 1:
                    editingMinute = !editingMinute;
                    editingHour = false;
                    editingAM_PM = false;
                    break;

                case 2:
                    editingAM_PM = !editingAM_PM;
                    editingHour = false;
                    editingMinute = false;
                    break;

                case 3:
                    editingHour = false;
                    editingMinute = false;
                    editingAM_PM = false;
                    //apply changes
                    break;

                case 4:
                    alarmMenuIndex = 0;
                    editingHour = false;
                    editingMinute = false;
                    editingAM_PM = false;
                    currentView = View::MAIN_MENU;
                    break;

                default:
                    break;
            }
            break;
            

        
        case View::BRIGHTNESS_MENU:
            switch(brightnessMenuIndex) {
                case 0:
                    editingBrightness = !editingBrightness;
                    editingTimeToLight = false;
                    break;
                
                case 1: 
                    editingTimeToLight = !editingTimeToLight;
                    editingBrightness = false;
                    break;

                case 2:
                    editingBrightness = false;
                    editingTimeToLight = false;
                    //applybrightness
                    break;
                
                case 3:
                    brightnessMenuIndex = 0;
                    editingBrightness = false;
                    editingTimeToLight = false;
                    currentView = View::MAIN_MENU;
                    break;
                
                default:
                    break;
            }
            break;
            

        case View::COLOR_MENU:
            switch(colorMenuIndex) {
                case 0:
                    colorOne = true;
                    colorTwo = false;
                    colorThree = false;
                    colorFour = false;
                    colorFive = false;
                    colorSix = false;
                    break;

                case 1:
                    colorOne = false;
                    colorTwo = true;
                    colorThree = false;
                    colorFour = false;
                    colorFive = false;
                    colorSix = false;
                    break;
            
                case 2:
                    colorOne = false;
                    colorTwo = false;
                    colorThree = true;
                    colorFour = false;
                    colorFive = false;
                    colorSix = false;
                    break;

                case 3:
                    colorOne = false;
                    colorTwo = false;
                    colorThree = false;
                    colorFour = true;
                    colorFive = false;
                    colorSix = false;
                    break;

                case 4:
                    colorOne = false;
                    colorTwo = false;
                    colorThree = false;
                    colorFour = false;
                    colorFive = true;
                    colorSix = false;
                    break;

                case 5:
                    colorOne = false;
                    colorTwo = false;
                    colorThree = false;
                    colorFour = false;
                    colorFive = false;
                    colorSix = true;
                    break;

                case 6:
                    //apply color
                    break;

                case 7:
                    colorMenuIndex = 0;
                    currentView = View::MAIN_MENU;
                    break;

                default:
                    break;
            }
            break;

        
        default:
            break;

        }

}

void UIManager::moveMainMenu(int direction) {
    mainMenuIndex += direction;

    int mainOptionCount = 5;

    if (mainMenuIndex < 0) {
        mainMenuIndex = mainOptionCount - 1;
    }

    if (mainMenuIndex >= mainOptionCount) {
        mainMenuIndex = 0;
    }

}


void UIManager::moveSetClockMenu(int direction) {
    setClockMenuIndex += direction;

    int setClockOptionCount = 5;

    if (setClockMenuIndex < 0) {
        setClockMenuIndex = setClockOptionCount - 1;
    }

    if (setClockMenuIndex >= setClockOptionCount) {
        setClockMenuIndex = 0;
    }
}


void UIManager::moveAlarmMenu(int direction) {
    alarmMenuIndex += direction;

    int alarmOptionCount = 5;

    if (alarmMenuIndex < 0) {
        alarmMenuIndex = alarmOptionCount - 1;
    }
    if (alarmMenuIndex >= alarmOptionCount) {
        alarmMenuIndex = 0;
    }
}


void UIManager::moveBrightnessMenu(int direction) {
    brightnessMenuIndex += direction;

    int brightnessOptionCount = 4;

    if (brightnessMenuIndex < 0) {
        brightnessMenuIndex = brightnessOptionCount - 1;
    }
    if (brightnessMenuIndex >= brightnessOptionCount) {
        brightnessMenuIndex = 0;
    }
}

void UIManager::moveColorMenu(int direction) {
    colorMenuIndex += direction;

    int colorOptionCount = 8;

    if (colorMenuIndex < 0) {
        colorMenuIndex = colorOptionCount - 1;
    }
    if (colorMenuIndex >= colorOptionCount) {
        colorMenuIndex = 0;
    }
}


void UIManager::draw(DisplayManager& display, clockBody& clock) {
    //display.clear();

    switch (currentView) {
        case View::MAIN_MENU:
            display.drawMainMenu(mainMenuIndex, clock.getHour(), clock.getMinute(), clock.getAM_PM());
            break;

        case View::CLOCK_MENU:
            display.drawClock(clock.getHour(), clock.getMinute(), clock.getAM_PM());
            break;

        case View::SET_CLOCK_MENU:
            display.drawSetClock(setClockMenuIndex, setHour, setMinute, setAM_PM);
            break;

        case View::ALARM_MENU:
            display.drawAlarm(alarmMenuIndex, hour, minute, AM_PM);
            break;
 
        case View::BRIGHTNESS_MENU:
            display.drawBrightness(brightnessMenuIndex, brightnessLevel, timeToLight);
            break;

        case View::COLOR_MENU:
            display.drawColor(colorMenuIndex, colorOne, colorTwo, colorThree, colorFour, colorFive, colorSix);
            break;
        
        case View::MAIN_COUNT:
            break;

        default:
            break;
    }
}