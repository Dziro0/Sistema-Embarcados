const int sensorPin = A0;  // Pino onde o termistor está conectado
const float BETA = 3950; // Coeficiente beta do termistor
const float seriesResistor = 10000; // Resistor em série (10kΩ)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  
  // Converte o valor lido (0 a 1023) para tensão
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Calcula a resistência do termistor
  float thermistorResistance = (seriesResistor * (5.0 / voltage)) - seriesResistor;
  
  // Aplica a equação de Steinhart-Hart
  float temperatureC = 1.0 / (log(thermistorResistance / seriesResistor) / BETA + 1.0 / 298.15) - 273.15;
  
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  delay(1000);  // Aguarda 1 segundo
}

