
// This code sets up a UDP connection on port 1234 and sends a packet containing the string "Hello, world!" 
// to the IP address 192.168.1.100 (the IP address of the receiving ESP8266).
// Finally, create a sketch on the receiving ESP8266 that listens for incoming UDP packets 
// and prints out their contents. Here's an example code snippet:

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Servo.h>

#include "secrets.h" 

const unsigned int listenPort = 1234; // UDP port to listen for incoming packets

WiFiUDP udp;

Servo myservo;

void setup() {
  myservo.attach(2); // attach servo to pin 2
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { // Wait for connection
    delay(1000);
  }
  Serial.begin(9600);
  Serial.print("Local IP address: "); // We need this to know the IP address of the receiving ESP8266
  Serial.println(WiFi.localIP());

  udp.begin(listenPort);
}

void loop() {
  char packetBuffer[255];               // buffer to hold incoming packet
  int packetSize = udp.parsePacket();   // read packet size
  if (packetSize > 0) {                 // if packet is received
    udp.read(packetBuffer, 255);        // read the content
      if (strcmp(packetBuffer, "turn_servo") == 0) {  // We check for the signal that we need to turn the servo
        Serial.print("Turned on servo");             // A check to let the user know the data is received
        myservo.write(90);                            // Turn the servo to 90 degrees
        delay(500);                                   // Wait for 500 milliseconds
        myservo.write(0);                             // Turn the servo to 0 degrees             
    }
  }
}
