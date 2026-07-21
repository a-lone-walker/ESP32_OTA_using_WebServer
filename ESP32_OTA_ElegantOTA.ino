#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ElegantOTA.h>

const char* ssid = "ssid";
const char* password = "password";

WebServer server(80);

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println("\n");
  Serial.println("Connecting to WiFi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n");
  Serial.println("=================================");
  Serial.println("WiFi Connected!");
  Serial.print("SSID       : ");
  Serial.println(WiFi.SSID());

  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  Serial.print("Gateway    : ");
  Serial.println(WiFi.gatewayIP());

  Serial.print("Subnet     : ");
  Serial.println(WiFi.subnetMask());

  Serial.print("RSSI       : ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
  Serial.println("=================================");

  // Home page
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html",
      "<h1>ESP32 OTA Server</h1>"
      "<p>OTA is working!</p>"
      "<a href='/update'>Open OTA Update Page</a>");
  });

  // Initialize ElegantOTA
  ElegantOTA.begin(&server);

  // Start server
  server.begin();

  Serial.println("HTTP Server Started");
  Serial.println("---------------------------------");
  Serial.print("Open Browser: http://");
  Serial.println(WiFi.localIP());
  Serial.print("OTA Page    : http://");
  Serial.print(WiFi.localIP());
  Serial.println("/update");
  Serial.println("---------------------------------");
}

void loop() {
  server.handleClient();
  ElegantOTA.loop();
}
