// Definir os pinos dos LEDs
int leds[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3 };

void setup() {
  // Configurar os pinos dos LEDs como saída
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    //Liga os LEDs dos pinos (12 a 8)
    digitalWrite(leds[i], HIGH);
    //Liga os LEDs dos pinos (3 a 7)
    digitalWrite(leds[9 - i], HIGH);
    delay(1000);
  }
  for (int i = 5; i >= 0; i--) {
    //Desliga os LEDs dos pinos(8 a 12)
    digitalWrite(leds[i], LOW);
    //Desliga os LEDs dos pinos (7 a 3)
    digitalWrite(leds[9 - i], LOW);
    delay(1000);
  }
}