#include<AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
pinMode(A1, INPUT);
pinMode(A0, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
pinMode(A5, INPUT);
}

void loop() {
  if(analogRead(A0)<=100){
if(analogRead(A1)<=35 && analogRead(A2)<=35 && analogRead(A3)<=35 && analogRead(A4)<=35 && analogRead(A5)<=35)
{
  motor1.write(90);
  motor1.setSpeed(120);
  motor2.write(90);
  motor2.setSpeed(120);
  motor3.write(90);
  motor3.setSpeed(120);
  motor4.write(90);
  motor4.setSpeed(120);
}
else{
  motor1.write(0);
  motor2.write(0);
  motor3.write(0);
  motor4.write(0);
}
// else if(!analogRead(A1)<=35 && analogRead(A0)<=35)
// {
//  motor1.run(FORWARD);
//  motor1.setSpeed(255);
//  motor2.run(FORWARD);
//  motor2.setSpeed(255);
//  motor3.run(BACKWARD);
//  motor3.setSpeed(255);
//  motor4.run(BACKWARD);
//  motor4.setSpeed(255);
//}
//
// else if(analogRead(A1)<=35 && !analogRead(A0)<=35)
// {
//  motor1.run(BACKWARD);
//  motor1.setSpeed(255);
//  motor2.run(BACKWARD);
//  motor2.setSpeed(255);
//  motor3.run(FORWARD);
//  motor3.setSpeed(255);
//  motor4.run(FORWARD);
//  motor4.setSpeed(255);
//}
//
//else if(!analogRead(A1)<=35 && !analogRead(A0)<=35)
//{
//  motor1.run(RELEASE); 
//  motor2.run(RELEASE);
//  motor3.run(RELEASE);
//  motor4.run(RELEASE);
// }
}
}
