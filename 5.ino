int redPin = 9;    // Pino PWM conectado ao terminal vermelho do LED RGB
int greenPin = 10; // Pino PWM conectado ao terminal verde do LED RGB
int bluePin = 11;  // Pino PWM conectado ao terminal azul do LED RGB

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Ciclo de cores variando entre vermelho, verde e azul
  for (int i = 0; i < 256; i++) {
    setColor(i, 0, 255 - i); // Varia de azul para vermelho
    delay(10);
  }
  for (int i = 0; i < 256; i++) {
    setColor(255 - i, i, 0); // Varia de vermelho para verde
    delay(10);
  }
  for (int i = 0; i < 256; i++) {
    setColor(0, 255 - i, i); // Varia de verde para azul
    delay(10);
  }
}

// Função para definir a cor do LED RGB
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
