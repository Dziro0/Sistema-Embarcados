const int V1 = 12;    
const int V2 = 4;    
const int AM1 = 10;   
const int AM2 = 3;   
const int VD1 = 8; 
const int VD2 = 2; 

void setup()
{
  pinMode(V1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(AM1, OUTPUT);
  pinMode(AM2, OUTPUT);
  pinMode(VD1, OUTPUT);
  pinMode(VD2, OUTPUT);
}

void loop()
{
  
  // 1° Semáforo
  
  digitalWrite(VD1, HIGH); 
  digitalWrite(V2, HIGH);  
  delay(2000);             
  
  digitalWrite(VD1, LOW);  

  digitalWrite(AM1, HIGH);  
  delay(2000);            
  digitalWrite(AM1, LOW);  
  
  digitalWrite(V2, LOW);   
  
  // 2° Semáforo
  
  digitalWrite(VD2, HIGH);
  digitalWrite(V1, HIGH);  
  delay(2000);             
  
  digitalWrite(VD2, LOW);  

  digitalWrite(AM2, HIGH);  
  delay(1000);             
  digitalWrite(AM2, LOW);   
  
  digitalWrite(V1, LOW);
}

