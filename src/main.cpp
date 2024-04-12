#include <Arduino.h>

// Define the pin for the reed switch
const int reedPin = 2;

int reedState = 0;        // current state of the reed switch
int lastReedState = 0;    // previous state of the reed switch
int tallyCount = 0;       // counter variable

void setup() {
  // Set the reed switch pin as input
  pinMode(reedPin, INPUT);
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the state of the reed switch
  reedState = digitalRead(reedPin);

  // Check if the reed switch state has changed
  if (reedState != lastReedState) {
    if (reedState == HIGH) {
      // Increment tally count when reed switch is triggered
      tallyCount++;
      Serial.print("Tally Count: ");
      Serial.println(tallyCount);
    }
    // Delay to debounce the reed switch
    delay(50);
  }

  // Save the current state of the reed switch for the next loop iteration
  lastReedState = reedState;
}
