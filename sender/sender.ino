// Here is a simple example of how to send a packet of data via Wi-Fi from one ESP8266 to another using the Arduino IDE:

// 1. First, you will need to set up both ESP8266s with a Wi-Fi network connection and 
// ensure that they are able to communicate with each other over the network. 
// You can use the WiFi library in the Arduino IDE to connect your ESP8266 to a Wi-Fi network.

// 2. Next, create a sketch on the sending ESP8266 that sets up a UDP connection 
// and sends a packet of data to the receiving ESP8266. Here's an example code snippet:


#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "secrets.h"

// We deconstruct the IP address to pass it to the WiFiUDP.beginPacket() function
IPAddress sendAddr(IP_ADDRESS[0],
                   IP_ADDRESS[1],
                   IP_ADDRESS[2],
                   IP_ADDRESS[3]); // IP address of the receiving ESP8266

const unsigned int sendPort = 1234; // UDP port to send packets to

WiFiUDP udp;

#define BUTTON_PIN 2

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set the button pin as input
  
  Serial.begin(9600);                // Initialize serial port to send and receive data
 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);     // Connect to the network
  while (WiFi.status() != WL_CONNECTED) {   // Wait for connection
    delay(1000);
  }

  udp.begin(1234); // UDP port we are targeting to send packets
}

void loop() {
   if (digitalRead(BUTTON_PIN)== LOW){
        Serial.println("Button pressed");    // A check that the circuit is working
        udp.beginPacket(sendAddr, sendPort); // Initialize the packet
        udp.printf("turn_servo");            // Message to send
        udp.endPacket();                     // Send the packet
   }
}
