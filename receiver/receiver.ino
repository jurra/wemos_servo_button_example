
// This code sets up a UDP connection on port 1234 and sends a packet containing the string "Hello, world!" 
// to the IP address 192.168.1.100 (the IP address of the receiving ESP8266).
// Finally, create a sketch on the receiving ESP8266 that listens for incoming UDP packets 
// and prints out their contents. Here's an example code snippet:

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "secrets.h"

const unsigned int listenPort = 1234; // UDP port to listen for incoming packets

WiFiUDP udp;

void setup() {
  // WiFi.begin("ssid", "password");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // Print the local IP address
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.begin(9600);
  Serial.print("Local IP address: ");
  Serial.println(WiFi.localIP());

  udp.begin(listenPort);
}

void loop() {
  char packetBuffer[255];
  int packetSize = udp.parsePacket();
  if (packetSize > 0) {
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
      Serial.println(packetBuffer);
    }
  }
}
