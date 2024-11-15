// Definir os pinos dos LEDs
int leds[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};

void setup()
{
  // Configurar os pinos dos LEDs como saída
  for (int i = 0; i < 10; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  // Ligar os LEDs um por um
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(100);
  }

  // Desligar os LEDs um por um
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(leds[i], LOW);
    delay(100);
  }
}