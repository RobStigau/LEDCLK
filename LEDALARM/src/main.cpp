

#include <Arduino.h>
#include "UIManager.h"
#include "EncoderInput.h"
#include "DisplayManager.h"
#include "clockBody.h"
#include "SendData.h"


UIManager ui;
EncoderInput* encoder;
DisplayManager display;
clockBody ClockBody;


uint8_t receiverMac[] = {0x30, 0x76, 0xf5, 0x92, 0x80, 0x14};
SendData sender(receiverMac);

void setup() {
  Serial.begin(115200);
  sender.begin();
  ClockBody.initializeClock();

  
  display.begin();
  encoder = new EncoderInput(32, 33, 25);
  encoder->begin();

  ui.begin();
  ui.draw(display, ClockBody);

}

void loop() {
  static int lastMinute = -1;

  static int lastAlarmHour = -1;
  static int lastAlarmMinute = -1;
  static bool lastAlarmAM_PM = false;

  ClockBody.update();

  bool alarmTimeMatches = ClockBody.getHour() == ui.getAlarmHour() &&
                          ClockBody.getMinute() == ui.getAlarmMinute() &&
                          ClockBody.getAM_PM() == ui.getAlarmAM_PM();

  bool alreadyTriggeredInMinute = lastAlarmHour == ClockBody.getHour() &&
                                  lastAlarmMinute == ClockBody.getMinute() &&
                                  lastAlarmAM_PM == ClockBody.getAM_PM();

  if (alarmTimeMatches && !alreadyTriggeredInMinute && !ui.isInAlarmMenu()) {
    sender.send(
      ui.getColor(),
      ui.getBrightnessLevel(),
      ui.getTimeToBright()
    );

    lastAlarmHour = ClockBody.getHour();
    lastAlarmMinute = ClockBody.getMinute();
    lastAlarmAM_PM = ClockBody.getAM_PM();

    ui.setView(View::ALARM_OFF_MENU);
    ui.draw(display, ClockBody);
  }
  

  int direction = encoder->getDirection();

  if (ClockBody.getMinute() != lastMinute) {
    lastMinute = ClockBody.getMinute();
    ui.draw(display, ClockBody);
  }

  if (direction != 0) {
    ui.handleRotation(direction);
    ui.draw(display, ClockBody);
  }
  bool buttonPress = encoder->buttonPressed();
  if (buttonPress) {
    delay(100);
    ui.handlePress(ClockBody);
    ui.draw(display, ClockBody);
  }


}


