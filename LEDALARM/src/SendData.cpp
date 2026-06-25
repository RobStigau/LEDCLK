#include "SendData.h"

SendData* SendData::instance = nullptr;

SendData::SendData(const uint8_t* targetMac) {
    memcpy(_receiverAddress, targetMac, 6);
    instance = this;
}

void SendData::OnDataSentStatic(const uint8_t *mac_addr, esp_now_send_status_t status) {
    if (instance != nullptr) {
        instance->handleDataSent(mac_addr, status);
    }
}

void SendData::handleDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("packet send status: ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

bool SendData::begin() {
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return false;
    }

    esp_now_register_send_cb(SendData::OnDataSentStatic);

    memset(&_peerInfo, 0, sizeof(_peerInfo));
    memcpy(_peerInfo.peer_addr, _receiverAddress, 6);
    _peerInfo.channel = 0;
    _peerInfo.encrypt = false;

    if (esp_now_add_peer(&_peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer configuration");
        return false;
    }

    return true;
}

void SendData::send(
    int color,
    int brightnessLevel,
    int timeToBright
) {
    struct_message dataPacket;

    dataPacket.color = color;
    dataPacket.brightnessLevel = brightnessLevel;
    dataPacket.timeToBright = timeToBright;

    esp_err_t result = esp_now_send(
        _receiverAddress,
        (uint8_t*)&dataPacket,
        sizeof(dataPacket)
    );

    if (result == ESP_OK) {
        Serial.println("Send started");
    } else {
        Serial.println("Send failed");
    }
}