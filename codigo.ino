#include <Ultrasonic.h>    

#define TRIGGER_PIN1 4               
#define ECHO_PIN1 5               

#define TRIGGER_PIN2 2
#define ECHO_PIN2 3

Ultrasonic sensor1(TRIGGER_PIN1, ECHO_PIN1); 
Ultrasonic sensor2(TRIGGER_PIN2, ECHO_PIN2);

#define IN1 6 //motor A (esquerda)
#define IN2 10 //motor A (esquerda)
             
#define IN3 11 //motor B (direita)            
#define IN4 9 //motor B (direita)                    

float distancia(Ultrasonic sensor);
void robo_();
void robo_esquerda();
void robo_direita();
void robo_ajuste_direita();
void robo_ajuste_esquerda();
void robo_ajuste_curva_direita();

void setup() 
{
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);              
  pinMode(IN2,OUTPUT);              

  pinMode(IN3,OUTPUT);             
  pinMode(IN4,OUTPUT);              
        
  delay(1000);                    
} //end setup

//Sentido antihorário (de fora) (esquerda)
//digitalWrite(IN1, HIGH);
//digitalWrite(IN2, LOW);

//Sentido antihorário (de fora) (direita)
//digitalWrite(IN3, LOW);
//digitalWrite(IN4, HIGH);
void loop()                         
{
  robo_direita();
  
  robo_frente();                    
  float dist_cm1 = distancia(sensor1);
  float dist_cm2 = distancia(sensor2);     
  Serial.print("Distancia1 = ");
  Serial.println(dist_cm1);
  Serial.print("Distancia2 = ");
  Serial.println(dist_cm2);

  if(dist_cm1 > 25)
  {
    robo_frente();
    if(dist_cm2 < 5)
    {
      robo_ajuste_direita();
      delay(75);
      robo_frente();
    }else if(dist_cm2 > 8 && dist_cm2 < 10){
      robo_ajuste_esquerda();
      delay(20);
      robo_frente();
    }
  }else
  {
    if(dist_cm2 < 25)
    {
     robo_ajuste_curva_direita();
      delay(200);
      robo_frente();
    }
    else
    {
      robo_ajuste_esquerda();
      delay(200);
      robo_frente();
    }                          
  }
}

float distancia(Ultrasonic sensor)                   
{
  float cmMsec;
  long microsec = sensor.timing();
  cmMsec = sensor.convert(microsec, Ultrasonic::CM);
  return(cmMsec);                   
  delay(10);
} 

void robo_frente()                  
{
  analogWrite(IN1,255);
  analogWrite(IN2,0);
  
  analogWrite(IN3,255);
  analogWrite(IN4,0);
 
} 

void robo_esquerda()         
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);


} 

//Sentido antihorário (de fora) (esquerda)
//digitalWrite(IN1, HIGH);
//digitalWrite(IN2, LOW);

//Sentido antihorário (de fora) (direita)
//digitalWrite(IN3, LOW);
//digitalWrite(IN4, HIGH);

void robo_ajuste_direita()
{
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  
  analogWrite(IN3, 50);
  analogWrite(IN4, 0);
}

void robo_ajuste_curva_direita()
{
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  
  analogWrite(IN3, 10);
  analogWrite(IN4, 0);
}

void robo_ajuste_esquerda()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(IN1, 10);
  analogWrite(IN2, 0);
}

void robo_direita()             
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
} 

void robo_parado()                  
{

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
 
}