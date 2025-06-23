#include <Servo.h>

Servo myservo;  // create servo object to control a servo
byte pos = 0;

// pin connections for HC-SR04 sensor 
const int trigPin = 5;
const int echoPin = 4;
long distance;

void setup() {
  // set pin modes for HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT); // red LED on controller board

  myservo.attach(6);  // connect servo to pin 6

  // open the lid
  for (pos = 8; pos < 100; pos += 1) {
    myservo.write(pos);
    delay(15);
  }

  // close the lid
  for (pos = 100; pos > 8; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}

void loop() {
  // red LED blinks slowly
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);

  // trigger ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  distance = pulseIn(echoPin, HIGH);

  // if an object is detected within 30cm
  if (distance < 3000) {
    digitalWrite(4, HIGH); // turn on white LED

    // open the lid
    for (pos = 8; pos < 100; pos += 1) {
      myservo.write(pos);
      delay(15);
    }

    // red LED blinks fast
    for (pos = 0; pos < 25; pos++) {
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
    }

    // close the lid
    for (pos = 100; pos > 8; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}

