

void setup() {
  for (int x = 2; x<9; x++){
    pinMode(x, OUTPUT);
  }
 }

void display (int a, int b, int c,int d,int e,int f,int g)
{
  digitalWrite (2,a);
  digitalWrite (3,b);
  digitalWrite (4,c);
  digitalWrite (5,d);
  digitalWrite (6,e);
  digitalWrite (7,f);
  digitalWrite (8,g);
}

void loop() {
  display (1,1,1,1,1,1,0);   //numero 0
  delay(1000);
  display(0,1,1,0,0,0,0);    //numero 1
  delay(1000);
  display(1,1,0,1,1,0,1);    //numero 2
  delay(1000);
  display(1,1,1,1,0,0,1);    //numero 3
  delay(1000);
  display(0,1,1,0,0,1,1);    //numero 4
  delay(1000);
  display(1,0,1,1,0,1,1);    //numero 5
  delay(1000);
  display(1,0,1,1,1,1,1);    //numero 6
  delay(1000);
  display(1,1,1,0,0,0,0);    //numero 7
  delay(1000);
  display(1,1,1,1,1,1,1);    //numero 8
  delay(1000);
  display(1,1,1,0,0,1,1);    //numero 9
  delay(1000);
  display(1,1,1,0,1,1,1) ;   //A
  delay(1000);
  display(0,0,1,1,1,1,1);    //B
  delay(1000);
  display(1,0,0,1,1,1,0);    //C
  delay(1000);
  display(0,1,1,1,1,0,1);    //D
  delay(1000);
  display(1,0,0,1,1,1,1) ;   //E
  delay(1000);
  display(1,0,0,0,1,1,1);    //F
  delay(1000);

}