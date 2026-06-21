

#include <Arduino.h>
#include "UIManager.h"
#include "EncoderInput.h"
#include "DisplayManager.h"



UIManager ui;
EncoderInput* encoder;
DisplayManager display;

void setup() {
  Serial.begin(115200);

  display.begin();
  encoder = new EncoderInput(32, 33, 25);
  encoder->begin();

  ui.begin();
  ui.draw(display);
}

void loop() {
  int direction = encoder->getDirection();

  if (direction != 0) {
    ui.handleRotation(direction);
    ui.draw(display);
  }
  bool buttonPress = encoder->buttonPressed();
  if (buttonPress) {
    delay(100);
    ui.handlePress();
    ui.draw(display);
  }


}


