#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);     

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

}

void loop() {
  delay(1000);  // change refresh time

  int networks = WiFi.scanNetworks();
  
  if (networks == 0) {
    Serial.println("No WiFi network found!");
  } 

  else {
    Serial.println("-----------------------------------------------------");
    Serial.println("  SSID                               | Signal Strength (dBm)");
    Serial.println("-----------------------------------------------------");

    for (int i = 0; i < networks; ++i) {

      String ssid = WiFi.SSID(i);  
      int rssi = WiFi.RSSI(i);     

      int spaceCount = 30 - ssid.length();
      String spaces = "";

      for (int j = 0; j < spaceCount; ++j) {
        spaces += " ";
      }


      Serial.print(" ");
      Serial.print(i + 1);
      Serial.print(" | ");
      Serial.print(ssid);
      Serial.print(spaces);
      Serial.print(" | ");
      Serial.println(String(rssi) + " dBm");
    }
  }
}
