// ATTiny85

#include <avr/power.h>
#include <avr/sleep.h> 
#include <RCSwitch.h>

RCSwitch RTX = RCSwitch();

long A = 2098244;   //kod vysilace
long B = 2098248;   //kod vysilace

long VALUE = 0;


void setup() {
  
  pinMode(2,INPUT_PULLUP);  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(13, HIGH); 
  digitalWrite(12, HIGH); 
  
  Serial.begin(9600);
  RTX.enableReceive(0);  // pin 2
  
  ADCSRA = 0;  
  power_adc_disable ();
  power_spi_disable();
  power_twi_disable();
  power_usart0_disable();
  //power_timer0_disable(); //timer0 je pro delay, nechat povolen
  power_timer1_disable();
  power_timer2_disable();
}

void loop() {
  if (RTX.available()) {

    VALUE = RTX.getReceivedValue();
    //Serial.println(VALUE);

    if (VALUE == A ) { digitalWrite(13, LOW ); delay(200); digitalWrite(13, HIGH );  }
    if (VALUE == B ) { digitalWrite(12, LOW ); delay(200); digitalWrite(12, HIGH );  }
    
    RTX.resetAvailable();

  }

 } 
