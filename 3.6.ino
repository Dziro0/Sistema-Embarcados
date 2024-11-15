// Definir os pinos dos LEDs
int leds[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3 };

void setup() {
  // Configurar os pinos dos LEDs como saída
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}
void loop() {
  
  for (int i = 0; i < 10 - 1; i += 2) {
    // Liga os LEDs no par atual
    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[i + 1], HIGH);

    // Espera um pouco
    delay(1000);
  }

  // Apaga três LEDs de cada vez
  for (int i = 9; i >= 0; i--) {
    // Desliga os LEDs no grupo atual
    digitalWrite(leds[i], LOW);
    delay(1000);
  }
  delay(1000);
}