const int ledPins[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3}; // LED
const int potPin = A0; //potenciômetro

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin);// Lê o valor do potenciômetro
  int delayTime = map(potValue, 0, 1023, 100, 1000);// Mapeia o valor para o tempo de atraso

  
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPins[i], HIGH); 
    delay(delayTime);              
    digitalWrite(ledPins[i], LOW);  
  }
}

