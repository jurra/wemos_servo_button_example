// Here is a simple example of how to send a packet of data via Wi-Fi from one ESP8266 to another using the Arduino IDE:

// 1. First, you will need to set up both ESP8266s with a Wi-Fi network connection and 
// ensure that they are able to communicate with each other over the network. 
// You can use the WiFi library in the Arduino IDE to connect your ESP8266 to a Wi-Fi network.

// 2. Next, create a sketch on the sending ESP8266 that sets up a UDP connection 
// and sends a packet of data to the receiving ESP8266. Here's an example code snippet:


#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "secrets.h"

IPAddress sendAddr(IP_ADDRESS[0],
                   IP_ADDRESS[1],
                   IP_ADDRESS[2],
                   IP_ADDRESS[3]); // IP address of the receiving ESP8266

const unsigned int sendPort = 1234; // UDP port to send packets to

WiFiUDP udp;

void setup() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  udp.begin(1234); // UDP port to listen for incoming packets
}

void loop() {
  String message = "Hello, world!"; // message to send
  udp.beginPacket(sendAddr, sendPort);
  udp.write((uint8_t*)message.c_str(), message.length());
  udp.endPacket();
  delay(5000);
}
