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
    Serial.print(networks);
    Serial.println(" WiFi networks found:");

    for (int i = 0; i < networks; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (Sinyal Gücü: ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dBm)");
    }
    
    Serial.println("-----------------------------------------------------");
  }
}
