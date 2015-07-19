#include "SHT21.h"

 SHT21::SHT21(int Choose_pin,int echo_pin,const byte whichISR)   : whichISR_ (whichISR) {
     
        
	_echoBit = digitalPinToBitMask(echo_pin);       // Get the port register bitmask for the echo pin.
	_echoInput = portInputRegister(digitalPinToPort(echo_pin));         // Get the input port register for the echo pin.
       flag =0;
       echo_pin_aux=echo_pin;
       Choose_pin_aux = Choose_pin;
};

void SHT21::Begin(int Intervalodetroca){
         pinMode(Choose_pin_aux, OUTPUT);
         Intervalodetroca_aux = Intervalodetroca;
        switch (whichISR_){
        
          case 0:
              attachInterrupt(echo_pin_aux,isr0,CHANGE); 
               instance0_ = this;
          
            break;
            
          case 1: 
              attachInterrupt(echo_pin_aux,isr1,CHANGE); 
              instance1_ = this;
          break;
               
          case 2: 
                    attachInterrupt(echo_pin_aux,isr2,CHANGE); 
                    instance2_ = this;
           break;
           
          case 3 : 
                    attachInterrupt(echo_pin_aux,isr3,CHANGE); 
                    instance3_ = this;
           break;
           
          case 4: 
                    attachInterrupt(echo_pin_aux,isr4,CHANGE); 
                    instance4_ = this;
           break;
           
          case 5: 
                    attachInterrupt(echo_pin_aux,isr5,CHANGE); 
                     instance5_ = this;
           break;
    }  
}



// class instance to handle an interrupt
void inline SHT21::handleInterrupt ()
  {
       
      Timer = micros();
    if(( *_echoInput & _echoBit)){
  Rising = Timer; 
    }
  else {
     Falling = Timer;  
  }
  if((long)(Falling-Rising)>0){
  High_Time = Falling-Rising;

  }
  if((long)(Rising-Last_Falling)>0){
  Low_Time = Rising-Last_Falling;

  }
   Period = High_Time +Low_Time;
  Last_Falling = Falling;
 flag=1;
  
 
};


int SHT21::Read(void){
   currentMillis = millis();
   if(State) // If state is One Read Temperature
    digitalWrite(Choose_pin_aux, LOW); //Read Temperature
    else 
     digitalWrite(Choose_pin_aux, HIGH); //Read Humidity
     
     
   
  
   //Wait 2seconds to change measurement(humidity or temperature)
  if((long)(currentMillis - previousMillis) > Intervalodetroca_aux ) {
      previousMillis = currentMillis; 
     State = ~State; // Change measurement mode
     Trocou =1;
     
  }  
  if(flag & State & Trocou){//IF Temperature Is Captured
    
      Temperature = (((float)High_Time/Period)*175.72)-46.85;
      flag = 0;
      Trocou = 0;
    return 1;
}
  else if (flag & !State & Trocou){//IF Humidity Is Captured
       
    Humidity = (((float)High_Time/Period)*125)-6;
    flag = 0;
	 Trocou = 0;
    return 1;
  }
  
 else // If Capture Anything Return 0
 return 0;
}



void inline SHT21::isr0 ()
  {
  instance0_->handleInterrupt ();       
  } 

void  inline SHT21::isr1 ()
  {
  instance1_->handleInterrupt ();  
  } 
  
void  inline SHT21::isr2 ()
  {
  instance2_->handleInterrupt ();  
  } 
  
void  inline SHT21::isr3 ()
  {
  instance3_->handleInterrupt ();  
  } 
  
void  inline SHT21::isr4 ()
  {
  instance4_->handleInterrupt ();  
  }   
  
  void  inline SHT21::isr5 ()
  {
  instance5_->handleInterrupt ();  
  } 
  
// for use by ISR glue routines
SHT21 * SHT21::instance0_;
SHT21 * SHT21::instance1_;
SHT21 * SHT21::instance2_;
SHT21 * SHT21::instance3_;
SHT21 * SHT21::instance4_;
SHT21 * SHT21::instance5_;




void SHT21::Test(void){
       
      
	
 Serial.print(" Estado do Pino = ");
 Serial.println(digitalRead(echo_pin_aux));
 digitalWrite(Choose_pin_aux, HIGH);
 Serial.println(" Mudando pra 1 ");
	delayMicroseconds(10);           // Wait long enough for the sensor to realize the trigger pin is high. Sensor specs say to wait 10uS.
   Serial.print(" Estado do Pino = ");
  Serial.println(digitalRead(echo_pin_aux));
  delay(2000);
   Serial.println(" Mudando pra 0 ");
	digitalWrite(Choose_pin_aux, LOW);
delay(2000);
  
}

