#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);     

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

}

void loop() {
  delay(5000);  // change refresh time

  int networks = WiFi.scanNetworks();
  
  if (networks == 0) {
    Serial.println("No WiFi network found!");
  } 

  else {
    Serial.println("-----------------------------------------------------------------------------------");
    Serial.println("  SSID                              | Strength | MAC Adress       | EncrytionType");
    Serial.println("-----------------------------------------------------------------------------------");

    for (int i = 0; i < networks; ++i) {

      String ssid = WiFi.SSID(i);  
      int rssi = WiFi.RSSI(i);     
      String bssid = WiFi.BSSIDstr(i);
      int encryptionType = WiFi.encryptionType(i);


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
      Serial.print(String(rssi) + " dBm");
      Serial.print(" | ");
      Serial.print(bssid);
      Serial.print(" | ");
      Serial.println(encryptionTypeToStr(encryptionType));
    }
  }
}

String encryptionTypeToStr(int encryptionType) {
  switch (encryptionType) {
    case ENC_TYPE_NONE:
      return "Open";
    case ENC_TYPE_WEP:
      return "WEP";
    case ENC_TYPE_TKIP:
      return "WPA/TKIP";
    case ENC_TYPE_CCMP:
      return "WPA2/CCMP";
    case ENC_TYPE_AUTO:
      return "Auto";
    default:
      return "Unknown";
  }
}
