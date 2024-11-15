#include <Servo.h>

Servo meuServo;  // Cria um objeto servo para controlar o servo motor

void setup() {
  meuServo.attach(9);  // Conecta o servo ao pino 9 do Arduino
}

void loop() {
  meuServo.write(0);
  delay(1000);
  meuServo.write(30);
  delay(1000);
  meuServo.write(60);
  delay(1000);
  meuServo.write(90);
  delay(1000);
  meuServo.write(120);
  delay(1000);
  meuServo.write(150);
  delay(1000);
  meuServo.write(180);
  delay(1000);
}