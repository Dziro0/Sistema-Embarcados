int buzzerPin = 4;

// Frequências das notas
#define NOTE_A 440
#define NOTE_AS 466
#define NOTE_B 494
#define NOTE_C 523
#define NOTE_CS 554
#define NOTE_D 587
#define NOTE_DS 622
#define NOTE_E 659
#define NOTE_F 698
#define NOTE_FS 740
#define NOTE_G 784
#define NOTE_GS 830

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Tocar a Marcha Imperial
  playNote(NOTE_A, 500);
  playNote(NOTE_A, 500);
  playNote(NOTE_F, 350);
  playNote(NOTE_C, 150);
  playNote(NOTE_A, 500);
  playNote(NOTE_F, 350);
  playNote(NOTE_C, 150);
  playNote(NOTE_A, 1000);

  playNote(NOTE_E, 500);
  playNote(NOTE_E, 500);
  playNote(NOTE_E, 500);
  playNote(NOTE_F, 350);
  playNote(NOTE_C, 150);
  playNote(NOTE_GS, 500);
  playNote(NOTE_F, 350);
  playNote(NOTE_C, 150);
  playNote(NOTE_A, 1000);

  delay(2000);  // Pausa antes de repetir a música
}

void playNote(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);  // Emite o som da frequência desejada por uma duração específica
  delay(duration * 1.30);                // Pausa pela duração da nota mais um pouco para dar um intervalo
  noTone(buzzerPin);                     // Para o som
}
