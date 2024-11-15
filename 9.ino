
//---Vermelho-------
const int V1 = 12;    
const int V2 = 4;  
const int V3 = A0;
const int V4 = A3;  

//------Amarelo-----
const int AM1 = 11;   
const int AM2 = 3;
const int AM3 = A1;
const int AM4 = A4;

//--------Verde------
const int VD1 = 8; 
const int VD2 = 2; 
const int VD3 = A2; 
const int VD4 = A5; 

void setup()
{
//  ---Vermelho-------
  pinMode(V1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(V3, OUTPUT);
  pinMode(V4, OUTPUT);

//  ------Amarelo-----
  pinMode(AM1, OUTPUT);
  pinMode(AM2, OUTPUT);
  pinMode(AM3, OUTPUT);
  pinMode(AM4, OUTPUT);

//  --------Verde--------
  pinMode(VD1, OUTPUT);
  pinMode(VD2, OUTPUT);
   pinMode(VD3, OUTPUT);
    pinMode(VD4, OUTPUT);
}

void loop()
{
  
  // 1° Semáforo
  
  digitalWrite(VD1, HIGH); 
  digitalWrite(V2, HIGH);
  digitalWrite(V3, HIGH);
  digitalWrite(V4, HIGH);  
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

   digitalWrite(V3, LOW);   
  
  // 3° Semáforo

   digitalWrite(VD3, HIGH);
  digitalWrite(V2, HIGH);  
  delay(2000);             
  
  digitalWrite(VD3, LOW);  

  digitalWrite(AM3, HIGH);  
  delay(1000);             
  digitalWrite(AM3, LOW);

  digitalWrite(V4, LOW); 

  // 4° Semáforo

  digitalWrite(VD4, HIGH);
  digitalWrite(V3, HIGH);  
  delay(2000);             
  
  digitalWrite(VD4, LOW);  

  digitalWrite(AM4, HIGH);  
  delay(1000);             
  digitalWrite(AM4, LOW);

  digitalWrite(V1, LOW); 
}

