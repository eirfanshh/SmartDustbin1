#include <Servo.h>

Servo myservo;
byte pos = 0;

// Sensor 1 (for hand detection)
const int trigPin1 = 5;
const int echoPin1 = 4;

// Sensor 2 (for bin fullness detection)
const int trigPin2 = 3;
const int echoPin2 = 2;

// LEDs
const int standbyLED = 13;
const int binFullLED = 12;

long distance1;
long distance2;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Servo and LED pins
  myservo.attach(6);
  pinMode(standbyLED, OUTPUT);
  pinMode(binFullLED, OUTPUT);

  // Sensor 1 pins
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // Sensor 2 pins
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Initialize servo position (closed)
  myservo.write(8);
}

void loop() {
  // Blink standby LED slowly
  digitalWrite(standbyLED, HIGH);
  delay(500);
  digitalWrite(standbyLED, LOW);
  delay(500);

  // Get distance from Sensor 1 (for hand detection)
  distance1 = getDistance(trigPin1, echoPin1);

  // If object detected within 30cm, open lid
  if (distance1 < 300) {
    openLid();
    delay(8000);  // Keep lid open for 8 seconds
    closeLid();
  }

  // Get distance from Sensor 2 (to check if bin is full)
  distance2 = getDistance(trigPin2, echoPin2);

  // If bin full detected (less than 10cm remaining space)
  if (distance2 < 100) {
    digitalWrite(binFullLED, HIGH);
    Serial.println("FULL");  // Display 'FULL' on Serial Monitor
  } else {
    digitalWrite(binFullLED, LOW);
  }
}

// Function to measure distance from an HC-SR04 sensor
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.034) / 2; // in cm
  return distance;
}

// Function to open the lid
void openLid() {
  for (pos = 8; pos < 100; pos++) {
    myservo.write(pos);
    delay(15);
  }
}

// Function to close the lid
void closeLid() {
  for (pos = 100; pos > 8; pos--) {
    myservo.write(pos);
    delay(15);
  }
}


