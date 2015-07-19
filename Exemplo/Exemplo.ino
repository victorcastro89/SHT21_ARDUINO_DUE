
#include "Arduino.h"
#include <SHT21.h>


/*
STH21 LIBRARY
16/04/2014
By Victor Castro
*/

                                    
#define Pino_Seletor0 16
#define Pino_Seletor1 13
#define Pino_PWM_input0 14
#define Pino_PWM_input1 21

/* SHT21 Sensor1(Pino seleção Temperatura ou Umidade,Pino de Leitura PWM,Identificação do Sensor (vai de 0 a 5)) */
SHT21 Sensor0(Pino_Seletor0,Pino_PWM_input0,0); // Cria um objeto chamado Sensor0 Pino de selecao 16, Pino de Pwm 14, Identificao do sensor 0
SHT21 Sensor1(Pino_Seletor1,Pino_PWM_input1,1); // Cria um objeto chamado Sensor1 Pino de selecao 13, Pino de Pwm 21, Identificao do sensor 1


void setup() {
 
  Serial.begin(115200);
 
  /* Inicializa os sensores  
   Sensor1.Begin(int intervalordetroca) A entrada da funcao é o tempo em milesegundos entre a selecao de temperatura e umidade o datasheet pede ao menos 1250ms. 
   Ou seja, o tempo minimo para uma leitura é a entrada da funcao.
  */
  Sensor1.Begin (2000);
  Sensor0.Begin (2000);

}

void loop() {
  
/* Funcao Read(), Retorna 1 caso a leitura de umidade e temperatura foi feita*/  
if(Sensor0.Read()){ // Se a leitura foi concluida imprima os valores
  Serial.println(" Sensor 0  ");
  Serial.print(" TEMPERATURA = ");
  Serial.println(Sensor0.Temperature); //Valor da Temperatura
  Serial.print(" UMIDADE = ");
  Serial.println(Sensor0.Humidity); //Valor da Umidade
  Serial.println(" ");
}

if(Sensor1.Read()){ // Se a leitura foi concluida imprima os valores
  Serial.println(" Sensor 1  ");
  Serial.print(" TEMPERATURA = ");
  Serial.println(Sensor1.Temperature);
  Serial.print(" UMIDADE = ");
  Serial.println(Sensor1.Humidity);
  Serial.println(" ");
}


}
  
           
 
                   
                                 
                  
     
        
                       
   
                               
                             

   
                                    
                                 

   
   
                         
        

 

  


