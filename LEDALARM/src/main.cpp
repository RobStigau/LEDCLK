

#include <Arduino.h>
#include "UIManager.h"
#include "EncoderInput.h"
#include "DisplayManager.h"
#include "clockBody.h"



UIManager ui;
EncoderInput* encoder;
DisplayManager display;
clockBody ClockBody;

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
  ClockBody.update();

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


