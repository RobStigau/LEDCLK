#include "EncoderInput.h"
#include <Arduino.h>

EncoderInput::EncoderInput(int pinA, int pinB, int buttonPin) 
    : encoder(pinA, pinB),
      lastPosition(0),
      buttonPin(buttonPin)

{

}


void EncoderInput::begin() {
    pinMode(buttonPin, INPUT_PULLUP);


    lastPosition = encoder.read();
}

int EncoderInput::getDirection() {
    long position = encoder.read();

    if(position >= lastPosition + 4) {
        lastPosition = position;
        return -1;
    }

    if(position <= lastPosition -4) {
        lastPosition = position;
        return 1;
    }

    return 0;
}

bool EncoderInput::buttonPressed() {

    if (digitalRead(buttonPin) == LOW) {

        delay(20);

        if (digitalRead(buttonPin) == LOW) {

            while (digitalRead(buttonPin) == LOW) {

            }
        }
        return true;
    }

    return false;

}
