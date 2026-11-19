#include <WiFi.h>

const char* target = "YOUR_NETWORK_NAME";   // the network you want to measure
int spot = 0;

int signalOf(const char* name) {
  int found = WiFi.scanNetworks();
  for (int i = 0; i < found; i++) {
    if (WiFi.SSID(i) == name) return WiFi.RSSI(i);
  }
  return 0;   // not found
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  pinMode(0, INPUT_PULLUP);
  delay(2000);
  Serial.println("Data walk. Stand at a spot and press BOOT to log it.");
  Serial.println("spot,rssi_dBm");
}

void loop() {
  if (digitalRead(0) == LOW) {
    spot++;
    int strength = signalOf(target);
    if (strength == 0) {
      Serial.println(String(spot) + ",not found");
    } else {
      Serial.println(String(spot) + "," + String(strength));
    }
    delay(300);
    while (digitalRead(0) == LOW) {}
  }
}
