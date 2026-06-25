

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
SendData sender;

void setup() {
  Serial.begin(115200);

  ClockBody.initializeClock();

  
  display.begin();
  encoder = new EncoderInput(32, 33, 25);
  encoder->begin();

  ui.begin();
  ui.draw(display, ClockBody);

}

void loop() {
  static int lastMinute = -1;

  static bool alarmHasBeenSent = false;

  ClockBody.update();

  if (ClockBody.getHour() == ui.getAlarmHour() &&
      ClockBody.getMinute() == ui.getAlarmMinute() &&
      ClockBody.getAM_PM() == ui.getAlarmAM_PM()) {
        if (!alarmHasBeenSent) {
          sender.send(ui.getColor(), 
                      ui.getBrightnessLevel(),
                      ui.getTimeToBright()
          );
          alarmHasBeenSent = true;
        }
      } else {
        alarmHasBeenSent = false;
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


