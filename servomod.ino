#include<avr/io.h>

void initADC()
{
  ADMUX=(1<<REFS0);
  ADCSRA|=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS2)|(1<<ADPS0);
  }

  void usart_int(void)
{
  UCSR0B=(1<< RXEN0)|(1<< TXEN0);//TRANSMIT AND RECEIVE ENABLE
  UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);//ASYNCHRONOUS, 8 BIT TRANSFER
  UBRR0L= 0x67 ; //BAUD RATE 9600
  
}

  uint16_t ReadADC(uint8_t ch)
  {
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return (ADC);
    }

int main()
{float angle=30;
  initADC();
  float ch=0;
  Serial.begin(9600);
  // while(UCSR0A!= (UCSR0A|(1<<RXC0)));
  // angle=UDR0; 
  
  DDRB=0xFF;//PIN 9 in the board
  
  
  TCCR1A |= (1<<COM1A1)|(1<<WGM10)|(1<<COM1B1);
  TCCR1B |= (1<<CS10) | (1<<WGM12);
 
  float x=ReadADC(2);
 
 // Serial.println(x);
  //Serial.println(flag);
  
  float adcreq=angle*1024/180;
  
 
    if(adcreq>x)
    {
      while(1)
      {OCR1A=0;
      OCR1B=130;
      x=ReadADC(2);
      //Serial.println(x);
   Serial.println(adcreq);

      if(x>adcreq)
      {
        OCR1B=0;
     break;
      }
      }
      
      }
      else if(adcreq<x)//reverse
      {
        while(1)
       { OCR1A=130;
      OCR1B=0;
      x=ReadADC(2);
      Serial.println(adcreq);
  
     if(x<adcreq)
     {OCR1A=0;
     break;
     }
       }
        }
    
}
  
  
  
  


