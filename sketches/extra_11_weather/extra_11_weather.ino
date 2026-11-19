#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

const char* ssid = "YOUR_HOTSPOT";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);
  int waited = 0;
  while (WiFi.status() != WL_CONNECTED && waited < 30) {
    delay(500);
    Serial.print(".");
    waited++;
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Could not connect. Check the name, the password and that the hotspot is 2.4 GHz.");
    return;
  }
  Serial.println("Connected. IP: " + WiFi.localIP().toString());

  WiFiClientSecure client;
  client.setInsecure();   // skip certificate checking. Fine for a classroom demo.
  HTTPClient http;
  http.begin(client, "https://api.open-meteo.com/v1/forecast?latitude=51.52&longitude=-0.13&current=temperature_2m,wind_speed_10m");
  int code = http.GET();
  if (code == 200) {
    JsonDocument doc;
    deserializeJson(doc, http.getString());
    float temp = doc["current"]["temperature_2m"];
    float wind = doc["current"]["wind_speed_10m"];
    Serial.println("London now: " + String(temp) + " C, wind " + String(wind) + " km/h");
  } else {
    Serial.println("Request failed with code " + String(code));
  }
  http.end();
}

void loop() {}
