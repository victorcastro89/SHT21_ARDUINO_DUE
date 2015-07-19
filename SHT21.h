#include <Arduino.h>

class SHT21 {
  
  public:
  SHT21(int Choose_pin,int echo_pin,const byte whichISR) ;
  void Begin(int Intervalodetroca);
  int Read(void);
  void Test(void);
  boolean flag;
  long High_Time,Low_Time;
  float Humidity,Temperature;
  long Period ;
  
  
  private:
  

  static void isr0 ();
  static void isr1 ();
  static void isr2 ();
  static void isr3 ();
  static void isr4 ();
  static void isr5 ();
  volatile unsigned long Timer,Falling,Rising,Last_Falling,Last_Rising;
  unsigned int _ChooseBit;
  unsigned int _echoBit;
  volatile RwReg *_ChooseOutput;
   volatile RwReg *_ChooseMode;
  volatile RwReg *_echoInput;
  int echo_pin_aux;
  int Choose_pin_aux;
  int Intervalodetroca_aux;
  boolean Trocou;
  unsigned long currentMillis;
  long previousMillis; 
  boolean  State;
    const byte whichISR_;
  static SHT21 * instance0_;
  static SHT21 * instance1_;
  static SHT21 * instance2_;
  static SHT21 * instance3_;
  static SHT21 * instance4_;
  static SHT21 * instance5_;
  void handleInterrupt ();
};


