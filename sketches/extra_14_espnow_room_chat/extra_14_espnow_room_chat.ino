#include <WiFi.h>
#include <esp_now.h>

uint8_t everyone[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};   // broadcast: every board hears it
String myName = "Ada";                                       // change this

void onReceive(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  String msg = "";
  for (int i = 0; i < len; i++) {
    msg += (char)data[i];
  }
  Serial.println(msg);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(2000);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW failed to start");
    return;
  }
  esp_now_register_recv_cb(onReceive);
  esp_now_peer_info_t peer = {};
  memcpy(peer.peer_addr, everyone, 6);
  peer.channel = 0;
  peer.encrypt = false;
  esp_now_add_peer(&peer);
  Serial.println("Room chat. Type a message and press Enter.");
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    text.trim();
    String msg = myName + ": " + text;
    esp_now_send(everyone, (const uint8_t *)msg.c_str(), msg.length());
    Serial.println("(sent) " + msg);
  }
}
