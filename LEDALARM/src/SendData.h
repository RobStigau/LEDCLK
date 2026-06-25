#pragma once

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
    int color;
    int brightnessLevel;
    int timeToBright;
} struct_message;

class SendData {
private:
    uint8_t _receiverAddress[6];
    esp_now_peer_info_t _peerInfo;

    static SendData* instance;

    static void OnDataSentStatic(const uint8_t *mac_addr, esp_now_send_status_t status);
    void handleDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

public:
    SendData(const uint8_t* targetMac);

    bool begin();

    void send(
        int color,
        int brightnessLevel,
        int timeToBright
    );
};