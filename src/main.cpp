// Imports
#include <Arduino.h>
#include <BleKeyboard.h>
#include <PinButton.h>

// Create bleKeyboard with the name Knisper
BleKeyboard bleKeyboard("Knipser");
// Create myButton on pin 12
PinButton myButton(12);
// Declare LED and pin
int led = 25;

void setup() {
  Serial.begin(115200);
  Serial.println("Start BLE!");
  bleKeyboard.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  // Update the button library
  myButton.update(); 

  // If there is no ble connection, led blinks
  if(!(bleKeyboard.isConnected())) {
    delay(200);
    digitalWrite(led,LOW);
    delay(200);
    digitalWrite(led,HIGH);
  }

  // If there is a ble connection, led is set to high
  if(bleKeyboard.isConnected()) {

    digitalWrite(led,HIGH);

    // Double button press
    if (myButton.isDoubleClick()) {
      bleKeyboard.write(KEY_LEFT_ARROW);
    }

    // One button press
    if (myButton.isLongClick()) {
      bleKeyboard.write(KEY_RIGHT_ARROW);
    }
  }
}