const int trigPin = 2;
const int echoPin = 3;

void setup() {
  Serial.begin(9600);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 
  long duration = pulseIn(echoPin, HIGH);

 
  long distance = duration * 0.0344 / 2;

  
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(50);
}