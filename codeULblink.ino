#include <Servo.h>

Servo myservo;  // create servo object to control a servo
byte pos = 0; 

//pin HC-SR04 sensor 
const int trigPin = 5;
const int echoPin = 4;
long distance;


void setup() {

//pinmode untuk HC-SR04
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(13, OUTPUT);//led merah pada pengawal

myservo.attach(6);  // sambung servo ke pin6


  for (pos = 8; pos < 100; pos += 1) { //pintu buka
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 100; pos > 8; pos -= 1) { //pintu tutup
    myservo.write(pos);              
    delay(15);                       
  }

}


void loop(){

 digitalWrite(13,HIGH);//led merah kelip pelahan
 delay(500);
 digitalWrite(13,LOW);
 delay(500);
 
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(20);
 digitalWrite(trigPin,LOW);
 distance = pulseIn(echoPin, HIGH);


if(distance<3000)//jika ada halangan dalam 30cm
{

digitalWrite(4,HIGH);//nyala led putih

  for (pos = 8; pos < 100; pos += 1) { //pintu buka
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }


for(pos=0;pos<25;pos++)//led merah kelip laju
{
 digitalWrite(13,HIGH);
 delay(100);
 digitalWrite(13,LOW);
 delay(100);
  }


  for (pos = 100; pos > 8; pos -= 1) { //pintu tutup
    myservo.write(pos);              
    delay(15);                       
  }
  


  }
  
}
