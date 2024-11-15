// Define os pinos dos LEDs
int leds[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};

void setup() {
  // Configurar os pinos dos LEDs como saída
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Sequência de acender LEDs de 12 a 3
  for (int i = 0; i <= 9; i++) { // Usamos o índice em vez do número do pino
    digitalWrite(leds[i], HIGH);
    delay(5);
    digitalWrite(leds[i], LOW);
    delay(25);
  }

  // Sequência de apagar LEDs de 3 a 12
  for (int i = 9; i >= 0; i--) { // Usamos o índice em vez do número do pino
    digitalWrite(leds[i], HIGH);
    delay(5);
    digitalWrite(leds[i], LOW);
    delay(25);
  }
}
