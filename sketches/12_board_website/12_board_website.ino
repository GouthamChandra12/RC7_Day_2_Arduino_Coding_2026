#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "RC7-yourname";   // change this so every board has its own name
WebServer server(80);
int lastRoll = 0;

String makePage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta http-equiv="refresh" content="2">
  <style>
    body { font-family: sans-serif; text-align: center; margin-top: 40px; }
    .big { font-size: 72px; margin: 8px; }
    a { display: inline-block; padding: 16px 32px; background: #e63b2e;
        color: white; text-decoration: none; border-radius: 8px; font-size: 22px; }
  </style>
</head>
<body>
  <h1>My ESP32 board</h1>
  <p>Touch reading on pin 4</p>
  <p class="big">%TOUCH%</p>
  <p>Last dice roll</p>
  <p class="big">%DICE%</p>
  <a href="/roll">Roll the dice</a>
</body>
</html>
)rawliteral";
  page.replace("%TOUCH%", String(touchRead(4)));
  page.replace("%DICE%", lastRoll == 0 ? String("-") : String(lastRoll));
  return page;
}

void handleRoot() {
  server.send(200, "text/html", makePage());
}

void handleRoll() {
  lastRoll = random(1, 7);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid);
  server.on("/", handleRoot);
  server.on("/roll", handleRoll);
  server.begin();
  delay(2000);
  Serial.println("Network name: " + String(ssid));
  Serial.println("Join it on your phone, then open http://" + WiFi.softAPIP().toString());
}

void loop() {
  server.handleClient();
}
