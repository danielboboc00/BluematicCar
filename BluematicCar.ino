#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);
long int data;

// releu pornire/oprire
int relay1 = 9;
long int password1 = 98421615;
long int password2 = 96951628;

// releu start
int relay2 = 8;
long int password3 = 74151525;

// releu inchidere usi
int relay3 = 7;
long int password4 = 84515822;

// releu deshidere usi
int relay4 = 6;
long int password5 = 81426337;

// releu aer conditionat on/off
int relay5 = 5;
long int password6 = 86741749;
long int password7 = 22241729;

// releu portbagaj
int relay6 = 4;
long int password8 = 34156469;

// releu de control
int relay7 = 3;

void setup() 
{
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);
  
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, HIGH);
  
  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, HIGH);
  
  pinMode(relay4, OUTPUT);
  digitalWrite(relay4, HIGH);
  
  pinMode(relay5, OUTPUT);
  digitalWrite(relay5, HIGH);
  
  pinMode(relay6, OUTPUT);
  digitalWrite(relay6, HIGH);
  
  pinMode(relay7, OUTPUT);
  digitalWrite(relay7, HIGH);
  delay(1000);
  digitalWrite(relay7, LOW);
  delay(500);
  digitalWrite(relay7, HIGH);
  delay(1000);
  digitalWrite(relay7, LOW);
  delay(500);
  digitalWrite(relay7, HIGH);
  delay(1000);
  digitalWrite(relay7, LOW);
  delay(500);
  digitalWrite(relay7, HIGH);

  Serial.begin(9600);
  BT.begin(9600);
}

void loop() 
{
  while(BT.available()==0);
  if(BT.available()>0) 
  {
    data = BT.parseInt();
  } 

  if(data == password1)
  {
    digitalWrite(relay1, LOW);
    delay(1000);
  }
  else if(data == password2)
  {
    digitalWrite(relay1, HIGH);
  }
  
  if(data == password3)
  {
    digitalWrite(relay2, LOW);
    delay(700);
    digitalWrite(relay2, HIGH);
  }
  
  if(data == password4)
  {
    digitalWrite(relay3, LOW);
    delay(500);
    digitalWrite(relay3, HIGH);
  }

  if(data == password5)
  {
    digitalWrite(relay4, LOW);
    delay(500);
    digitalWrite(relay4, HIGH);
  }

  if(data == password6)
  {
    digitalWrite(relay5, LOW);
    delay(1000);
  }
  else if(data == password7)
  {
    digitalWrite(relay5, HIGH);
  }

  if(data == password8)
  {
    digitalWrite(relay6, LOW);
    delay(500);
    digitalWrite(relay6, HIGH);
  }
}