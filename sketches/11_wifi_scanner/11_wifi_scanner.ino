#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000);
  Serial.println("Wi-Fi scanner");
}

void loop() {
  int found = WiFi.scanNetworks();
  Serial.println("Found " + String(found) + " networks");
  for (int i = 0; i < found; i++) {
    int strength = WiFi.RSSI(i);
    int bars = map(constrain(strength, -100, -30), -100, -30, 0, 20);
    String line = "";
    for (int b = 0; b < bars; b++) {
      line += "#";
    }
    Serial.println(WiFi.SSID(i) + "  " + String(strength) + " dBm  " + line);
  }
  Serial.println("-----");
  delay(5000);
}
