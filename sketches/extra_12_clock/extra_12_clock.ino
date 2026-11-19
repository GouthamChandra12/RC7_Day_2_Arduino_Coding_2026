#include <WiFi.h>
#include <time.h>

const char* ssid = "YOUR_HOTSPOT";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  delay(2000);
  WiFi.begin(ssid, password);
  int waited = 0;
  while (WiFi.status() != WL_CONNECTED && waited < 30) {
    delay(500);
    Serial.print(".");
    waited++;
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Could not connect.");
    return;
  }
  Serial.println("Connected");
  // London time, including summer time changes
  configTzTime("GMT0BST,M3.5.0/1,M10.5.0", "pool.ntp.org");
}

void loop() {
  struct tm now;
  if (getLocalTime(&now)) {
    Serial.println(&now, "%A %d %B %Y, %H:%M:%S");
  } else {
    Serial.println("Waiting for the time...");
  }
  delay(1000);
}
