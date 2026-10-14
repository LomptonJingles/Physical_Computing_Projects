#include "SevSeg.h"
SevSeg sevseg;

const int BUTTON_PIN = 1;

// Variables will change:
int lastState = HIGH; // the previous state from the input pin
int currentState;    // the current reading from the input pin

int counter = 0;

void setup(){
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop(){
    sevseg.setNumber(counter, 3);
    sevseg.refreshDisplay();
     // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if(lastState == LOW && currentState == HIGH)
    counter += 1;

  // save the last state
  lastState = currentState;
}