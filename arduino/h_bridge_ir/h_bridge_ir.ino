#include <IRremote.hpp>

#define IR_RECEIVE_PIN 3

constexpr uint8_t M2_LEFT_EN = 10;
constexpr uint8_t M2_LEFT_DIR = A0;
constexpr uint8_t M1_RIGHT_EN = 9;
constexpr uint8_t M1_RIGHT_DIR = A1;

void setup() {
  pinMode(M1_RIGHT_EN, OUTPUT);
  pinMode(M1_RIGHT_DIR, OUTPUT);
  pinMode(M2_LEFT_EN, OUTPUT);
  pinMode(M2_LEFT_DIR, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    switch (IrReceiver.decodedIRData.command) {
      case 0x6:  // UP
        analogWrite(M2_LEFT_EN, 255);
        analogWrite(M1_RIGHT_EN, 255);
        digitalWrite(M2_LEFT_DIR, 0);
        digitalWrite(M1_RIGHT_DIR, 0);
        break;
      case 0x1D:  // DOWN
        analogWrite(M2_LEFT_EN, 255);
        analogWrite(M1_RIGHT_EN, 255);
        digitalWrite(M2_LEFT_DIR, 0);
        digitalWrite(M1_RIGHT_DIR, 0);
        break;
      case 0x08:  // LEFT
        analogWrite(M2_LEFT_EN, 255);
        analogWrite(M1_RIGHT_EN, 255);
        digitalWrite(M2_LEFT_DIR, 0);
        digitalWrite(M1_RIGHT_DIR, 1);
        break;
      case 0x19:  // RIGHT
        analogWrite(M2_LEFT_EN, 255);
        analogWrite(M1_RIGHT_EN, 255);
        digitalWrite(M2_LEFT_DIR, 1);
        digitalWrite(M1_RIGHT_DIR, 0);
        break;
      default:
        analogWrite(M2_LEFT_EN, 0);
        analogWrite(M1_RIGHT_EN, 0);
        return;
    }
  }
}
