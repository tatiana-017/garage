#include <Servo.h>
Servo motor;
int piezoE=0;
int piezoEValue;
int led = 13;
int BuzzerPin = 8; 
int duration = 200;
int trig = 10;
int eco = 9;
int duracion;
int distancia;


int Mi_note = 330;

void setup() {
  Serial.begin(9600);
  motor.attach(3);
  pinMode(piezoE,INPUT);
  pinMode(led, OUTPUT);
  pinMode(BuzzerPin,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);

}

void loop() {
  piezoEValue = analogRead(piezoE);
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  duracion = pulseIn(eco, HIGH);
  distancia = duracion/58.2; //Valor especificado por el fabricante del sesnor 

  if(piezoEValue > 1000){
      motor.write(90);
      digitalWrite(led, HIGH);
      
  } 
  if(distancia <= 6 ){
      motor.write(0);
      digitalWrite(led, LOW);
      
  }
  if(distancia > 6 && distancia < 8 ){
      tone(BuzzerPin,Mi_note,duration);
  }
  Serial.println(distancia);

}
