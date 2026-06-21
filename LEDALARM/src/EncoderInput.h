#pragma once

#include <Encoder.h>

class EncoderInput {
    private:
        Encoder encoder;

        long lastPosition;

        int buttonPin;

    public:
        EncoderInput(int pinA, int pinB, int buttonPin);

        void begin();

        int getDirection();

        bool buttonPressed();

};
