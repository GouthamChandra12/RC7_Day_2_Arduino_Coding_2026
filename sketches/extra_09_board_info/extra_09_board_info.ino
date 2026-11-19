#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Chip: " + String(ESP.getChipModel()));
  Serial.println("Cores: " + String(ESP.getChipCores()));
  Serial.println("CPU speed: " + String(ESP.getCpuFreqMHz()) + " MHz");
  Serial.println("Flash size: " + String(ESP.getFlashChipSize() / 1048576) + " MB");
  Serial.println("Free memory: " + String(ESP.getFreeHeap() / 1024) + " KB");
  Serial.println("Chip temperature: " + String(temperatureRead()) + " C");
  Serial.println("MAC address: " + WiFi.macAddress());
}

void loop() {}
