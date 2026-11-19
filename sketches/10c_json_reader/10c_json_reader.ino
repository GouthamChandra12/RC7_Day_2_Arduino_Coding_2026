#include <ArduinoJson.h>

void setup() {
  Serial.begin(115200);
  delay(2000);

  // some data written as JSON text
  String text = R"({"site":"Roof","floors":4,"height":13.5})";

  JsonDocument doc;
  deserializeJson(doc, text);

  String site = doc["site"];
  int floors = doc["floors"];
  float height = doc["height"];

  Serial.println("Site: " + site);
  Serial.println("Floors: " + String(floors));
  Serial.println("Height: " + String(height) + " m");
}

void loop() {}
