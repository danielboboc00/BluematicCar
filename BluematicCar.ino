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
  // enable the transmission & reception in USART
  UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
  
  // set data size for communication
  UCSR0C &= ((1 << UMSEL00)) & ((1 << UMSEL01)) & ((1 << UPM00)) & ((1 << UPM01)) & (~(1 << USBS0));
  
  // set data length to be 8 bits
  UCSR0B &= (~(1 << UCSZ02));
  UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); // 8 bits
  
  // set the speed of the transmission
  UCSR0A &= ~(1 << U2X0); // high speed mode
  
  // set the baud rate
  UBRR0 = 103; // baud rate is 9600
  
}

void loop() 
{
  data = UART_Receive();
{
  /* Wait for data to be received */
  while(!(UCSR0A & (1<< RXC0)));
  return UDR0;
}
    //releul 1
  if(data == 'A')
  {
    PORTB &= ~(1 << PB1);
    delay(1000);
  }
  else if(data == 'a')
  {
    PORTB |= (1 << PB1);    
  }

  // releul 2 
  if(data == 'b')
  {
    PORTB &= ~(1 << PB0);
    delay(700);
    PORTB |= (1 << PB0);
  }
  
  // releul 3
  if(data == 'k')
  {
    PORTD &= ~(1 << PD7);
    delay(500);
    PORTD |= (1 << PD7);
  }
  
  // releul 4
  if (data == 'd')
  {
    PORTD &= ~(1 << PD6);
    delay(500);
    PORTD |= (1 << PD6);
  }
  // releul 5
  
  if(data == 'E')
  {
    PORTD &= ~(1 << PD5);
    delay(1000);
  }
  else if(data == 'e')
  {
    PORTD |= (1 << PD5);
  }

  // releul 6
  if(data == 'f')
  {
    PORTD &= ~(1 << PD4);
    delay(500);
    PORTD |= (1 << PD4);
  }

  // releul 7
  if(data == 'g')
  {
    PORTD &= ~(1 << PD3);
    delay(1000);
    PORTD |= (1 << PD3);
    delay(1000);
    PORTD &= ~(1 << PD3);
    delay(1000);
    PORTD |= (1 << PD3);
    delay(1000);
    PORTD &= ~(1 << PD3);
    delay(1000);
    PORTD |= (1 << PD3);
    delay(1000);
  }
}
