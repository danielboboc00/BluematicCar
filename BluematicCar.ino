unsigned char UART_Receive()
{
  /* Wait for data to be received */
  while(!(UCSR0A & (1<< RXC0)));
  return UDR0;
}

void UART_TxChar(char ch)
{
  /* Wait for empty transmit buffer*/
  while(!(UCSR0A &(1 << UDRE0))); 
  UDR0 = ch;
}

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
  
  // enable the transmission & reception in USART
  UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
  
  // set data size for communication
  UCSR0C &= ((1 << UMSEL00)) & ((1 << UMSEL01)) & ((1 << UPM00)) & ((1 << UPM01)) & (~(1 << USBS0));
}

void loop() 
{
  data = UART_Receive();
{
  /* Wait for data to be received */
  while(!(UCSR0A & (1<< RXC0)));
  return UDR0;
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
