#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>

#ifndef STASSID
#define STASSID ""
#define STAPSK  ""
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const char* www_username = "admin";
const char* www_password = "esp8266";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Connect Failed! Rebooting...");
    delay(1000);
    ESP.restart();
  }
  //LED_BUILTIN
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(14, HIGH);
  pinMode(14, OUTPUT);
  String hostname = "esp8266-master";
  WiFi.setHostname(hostname.c_str());
  ArduinoOTA.begin();
  ArduinoOTA.setHostname(hostname.c_str());
  // ArduinoOTA.setPassword("admin");
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  server.on("/", []() {
    if (!server.authenticate(www_username, www_password)) {
      return server.requestAuthentication();
    }

    digitalWrite(14, LOW);   // Turn the LED on (Note that LOW is the voltage level
    delay(500);                      // Wait for a second
    digitalWrite(14, HIGH);  // Turn the LED off by making the voltage HIGH
    server.send(200, "text/plain", "Login OK");

  });
  server.begin();
  Serial.print("Open http://");
  Serial.print(WiFi.localIP());
  Serial.println("/ in your browser to see it working");
}

void loop() {
  ArduinoOTA.handle();
  server.handleClient();
}
