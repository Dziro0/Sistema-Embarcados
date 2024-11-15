const int LDR = A7;           
const int LED = 12;             
int sensor ;               
void setup() {
  pinMode(LED, OUTPUT);         
  pinMode(LDR, INPUT);         
  Serial.begin(9600);         
}

void loop() {
  sensor = analogRead(LDR); //ler LDR e armazena o valor na variavel
  Serial.print("LDR : " );      // Mostra o valor no monitor serial
  Serial.println(sensor);

  if (sensor < 975) {      // Se o valor menor que 1000
    digitalWrite(LED, HIGH);  // Ligar 
  } else {                    // Se não
    digitalWrite(LED, LOW);    // Desligar
  }
  delay(100);                
}