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

void setup() 
{   
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
  
  DDRB |= (1 << DDB1) | (1 << DDB0);
  DDRD |= (1 << DDD7) | (1 << DDD6) | (1 << DDD5) | (1 << DDD4) | (1 << DDD3) | (1 << DDD2);
  PORTB |= (1 << PB1) | (1 << PB0);
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
