#include <Arduino.h>
#include <BleKeyboard.h>
#include <PinButton.h>

BleKeyboard bleKeyboard("Knipser");
PinButton myButton(12);

int led = 25;

void setup() {
  Serial.begin(115200);
  Serial.println("Start BLE!");
  bleKeyboard.begin();
  pinMode(led, OUTPUT);
}

void loop() {

  myButton.update(); 

  if(!(bleKeyboard.isConnected())) {
    delay(200);
    digitalWrite(led,LOW);
    delay(200);
    digitalWrite(led,HIGH);
  }

  if(bleKeyboard.isConnected()) {

    digitalWrite(led,HIGH);

    if (myButton.isDoubleClick()) {
      // Serial.println("double");
      bleKeyboard.write(KEY_LEFT_ARROW);
    }

    if (myButton.isLongClick()) {
      // Serial.println("long");
      bleKeyboard.write(KEY_RIGHT_ARROW);
    }
  
  }
}