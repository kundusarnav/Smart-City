#include <AFMotor.h>
#define trigPin 12
#define echoPin 13
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
 
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 20) {   
    motor1.setSpeed(255);
    motor2.setSpeed(0);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    delay(2000);
}
  else {
    motor1.setSpeed(160);
    motor2.setSpeed(160);
    motor1.run(FORWARD);
    motor2.run(FORWARD);  
}   
}
