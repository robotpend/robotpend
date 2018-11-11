#include <AFMotor.h>
#include<SoftwareSerial.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#define TxD 3
#define RxD 2
#define LED_PIN 13

SoftwareSerial bluetoothSerial(TxD, RxD);


char bt= 'S';

void setup() {
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Stop();
  }

void loop() {
  if(bluetoothSerial.available()){
    bt = bluetoothSerial.read();
    Serial.println(bt);
    if(bt=='F'){
      forward(); 
      digitalWrite(LED_PIN, HIGH);          
    }
    
    if(bt=='B'){
      backward(); 
      
      digitalWrite(LED_PIN, LOW);
    }
    
if(bt=='L')
{
 left(); 
}

if(bt=='R')
{
 right(); 
}
    if(bt=='G'){
      forward(); 
      left();
      digitalWrite(LED_PIN, HIGH);          
    }
        if(bt=='I'){
      forward(); 
      right();
      digitalWrite(LED_PIN, HIGH);          
    }
    if(bt=='H'){
      backward();
      left(); 
      
      digitalWrite(LED_PIN, LOW);
    }
        if(bt=='J'){
      backward();
      right(); 
      
      digitalWrite(LED_PIN, LOW);
    }
    

if(bt=='S')
{
 Stop(); 
}
  }
}
void forward()
{
     motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward()
{
     motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void right()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
