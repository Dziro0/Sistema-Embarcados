// Definição dos pinos dos LEDs
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int numLeds = 10; // Número total de LEDs
int delayTime = 100; // Tempo de delay entre os efeitos (em ms)

void setup() {
  // Configura os pinos dos LEDs como saída
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW); // Inicializa os LEDs desligados
  }
}

void loop() {
  efeitoSuperMaquina();
}

// Função para o efeito Super Máquina
void efeitoSuperMaquina() {
  // Acende os LEDs da esquerda para a direita
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH); // Acende o LED
    delay(delayTime);           // Aguarda
    digitalWrite(leds[i], LOW); // Apaga o LED
  }

  // Acende os LEDs da direita para a esquerda
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH); // Acende o LED
    delay(delayTime);           // Aguarda
    digitalWrite(leds[i], LOW); // Apaga o LED
  }
}
