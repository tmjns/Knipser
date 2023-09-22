#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Knipser");

int led = 25;
int button = 12;

void setup() {
  Serial.begin(115200);
  Serial.println("Start BLE!");
  bleKeyboard.begin();
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {

  if(!(bleKeyboard.isConnected())) {
    delay(200);
    digitalWrite(led,LOW);
    delay(200);
    digitalWrite(led,HIGH);
  }

  if(bleKeyboard.isConnected()) {
    digitalWrite(led,HIGH);
    Serial.println(digitalRead(button));
    if (digitalRead(button) == 1){
      bleKeyboard.print("Bin da");
    }
    delay(400);
  }
}
