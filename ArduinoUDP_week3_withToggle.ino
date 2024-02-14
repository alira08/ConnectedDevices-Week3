#include <WiFiNINA.h>

//be sure to remove WiFi network details before uploading this code!
const char WIFI_SSID[] = "sandbox370"; //WiFi network name goes here
const char WIFI_PASS[] = "+s0a+s03!2gether?"; //WiFi password goes here

WiFiUDP udpClient;

//configure your WiFi information inside config.h file

const char server[] = "10.23.11.12"; //local IP address of receiver device goes here
const int port = 4242; //desired port # goes here. Make sure the receiver is listening on the same port!

//the port OTHER devices should use when sending to this one
const int localPort = 5000;

const int button1Pin = 2;
int button1State = HIGH;   // Current state of the button
int lastButton1State = HIGH; // Previous state of the button
bool toggle1State = false;   // Initial state is OFF

const int button2Pin = 3;
int button2State = HIGH;   // Current state of the button
int lastButton2State = HIGH; // Previous state of the button
bool toggle2State = false;   // Initial state is OFF

const int button3Pin = 4;
int button3State = HIGH;   // Current state of the button
int lastButton3State = HIGH; // Previous state of the button
bool toggle3State = false;   // Initial state is OFF

int potentiometerPin = A0;


void setup() {
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  Serial.begin(9600);
  //retry connection until WiFi is connected successfully
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Attempting to connect to SSID: ");
    // Attempt connection to WPA/WPA2 network.
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(500);
  }
  Serial.println("connected!");

  udpClient.begin(localPort);
}

char messageBuffer[256];

void loop() {

  int reading1 = digitalRead(button1Pin);
  int reading2 = digitalRead(button2Pin);
  int reading3 = digitalRead(button3Pin);

  int potentiometerValue = analogRead(potentiometerPin);
  int mappedPotValue = map(potentiometerValue, 0, 1027, 0, 255);

  // if (millis()%30 < 10) {    

//udpClient.beginPacket(server, port);

 if (reading1 != lastButton1State) {
    // If the button is pressed, toggle the state
    if (reading1 == LOW) {
      toggle1State = !toggle1State;
    }
  }

  if (toggle1State) {
    // The state is ON
    // Do something when the button is toggled ON
      udpClient.beginPacket(server, port);
      udpClient.print("Button1Pressed");
      udpClient.endPacket();

  } else if (!toggle1State){
    // The state is OFF
    // Do something when the button is toggled OFF
        udpClient.beginPacket(server, port);
        udpClient.print("Button1NotPressed");
        udpClient.endPacket();
  }

  lastButton1State = reading1;


///////////////////
/* BUTTON 2 CODE */
///////////////////

  if (reading2 != lastButton2State) {
    // If the button is pressed, toggle the state
    if (reading2 == LOW) {
      toggle2State = !toggle2State;
    }
  }

  if (toggle2State) {
    // The state is ON
    // Do something when the button is toggled ON
      udpClient.beginPacket(server, port);
      udpClient.print("Button2Pressed");
      udpClient.endPacket();

  } else if (!toggle2State){
    // The state is OFF
    // Do something when the button is toggled OFF
        udpClient.beginPacket(server, port);
        udpClient.print("Button2NotPressed");
        udpClient.endPacket();
  }

  lastButton2State = reading2;

///////////////////
/* BUTTON 3 CODE */
///////////////////

  if (reading3 != lastButton3State) {
    // If the button is pressed, toggle the state
    if (reading3 == LOW) {
      toggle3State = !toggle3State;
    }
  }

  if (toggle3State) {
    // The state is ON
    // Do something when the button is toggled ON
      udpClient.beginPacket(server, port);
      udpClient.print("Button3Pressed");
      udpClient.endPacket();

  } else if (!toggle3State){
    // The state is OFF
    // Do something when the button is toggled OFF
        udpClient.beginPacket(server, port);
        udpClient.print("Button3NotPressed");
        udpClient.endPacket();
  }

  lastButton3State = reading3;

    udpClient.beginPacket(server, port);
    udpClient.print(mappedPotValue);
    udpClient.endPacket();

    // if (button1State != button1StatePrev) {
    //   if (button1State == LOW) {
    //     //Serial.println("Button1Pressed");
    //     udpClient.print("Button1Pressed");
    //     udpClient.endPacket();
    //   } else {
    //     //Serial.println("Button1NotPressed");
    //     udpClient.print("Button1NotPressed");
    //     udpClient.endPacket();
    //   }
    //   button1StatePrev = button1State;
    // }

    // if (button2State != button2StatePrev) {
    //   if (button2State == LOW) {
    //     //Serial.println("Button2Pressed");
    //     udpClient.print("Button2Pressed");
    //     udpClient.endPacket();
    //   } else {
    //     //Serial.println("Button2NotPressed");
    //     udpClient.print("Button2NotPressed");
    //     udpClient.endPacket();
    //   }
    //   button2StatePrev = button2State;
    // }

    // if (button3State != button3StatePrev) {
    //   if (button3State == LOW) {
    //     Serial.println("Button3Pressed");
    //     udpClient.print("Button3Pressed");
    //     udpClient.endPacket();
    //   } else {
    //     Serial.println("Button3NotPressed");
    //     udpClient.print("Button3NotPressed");
    //     udpClient.endPacket();
    //   }
    //   button3StatePrev = button3State;
    // }
    // udpClient.print(millis());
  //udpClient.endPacket();
   // delay(10);
  }
