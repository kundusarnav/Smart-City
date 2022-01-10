#include <Arduino.h>
#include <MuVisionSensor.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include<AFMotor.h>
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
#define SERIAL_MODE
#define MU_ADDRESS    0x61
#ifdef SERIAL_MODE
#define TX_PIN 10
#define RX_PIN 9
SoftwareSerial mySerial(RX_PIN, TX_PIN);
#endif
MuVisionSensor Mu(MU_ADDRESS);

void setup() {
  Serial.begin(9600);
  uint8_t err = MU_ERROR_FAIL;
#ifdef I2C_MODE
  Wire.begin();
  err = Mu.begin(&Wire);
#elif defined SERIAL_MODE
  mySerial.begin(9600);
  err = Mu.begin(&mySerial);
#endif
  if (err == MU_OK)
  {
    Serial.println("MU initialized.");
  }
  else
  {
    do
    {
      Serial.println("fail to initialize MU! Please check protocol "
                     "version or make sure MU is working on the "
                     "correct port with correct mode.");
      delay(5000);
    }
    while (1);
  }
  Mu.VisionBegin(VISION_TRAFFIC_CARD_DETECT);
  Mu.VisionBegin(VISION_SHAPE_CARD_DETECT);
}

void loop() {
  long time_start = millis();
  if (Mu.GetValue(VISION_TRAFFIC_CARD_DETECT, kStatus))
  {
    Serial.println("vision shape card detected:");
    Serial.print("x = ");
    Serial.println(Mu.GetValue(VISION_TRAFFIC_CARD_DETECT, kXValue));
    Serial.print("y = ");
    Serial.println(Mu.GetValue(VISION_TRAFFIC_CARD_DETECT, kYValue));
    Serial.print("width = ");
    Serial.println(Mu.GetValue(VISION_TRAFFIC_CARD_DETECT, kWidthValue));
    Serial.print("height = ");
    Serial.println(Mu.GetValue(VISION_TRAFFIC_CARD_DETECT, kHeightValue));
    Serial.print("label = ");
    switch (Mu.GetValue(VISION_TRAFFIC_CARD_DETECT, kLabel))
    {
      case MU_TRAFFIC_CARD_FORWARD:
        Serial.println("forward");
        moveForward();
        delay(800);
        Stop();
        break;
      case MU_TRAFFIC_CARD_LEFT:
        Serial.println("left");
        turnLeft();
        delay(500);
        Stop();
        break;
      case MU_TRAFFIC_CARD_RIGHT:
        Serial.println("right");
        turnRight();
        delay(500);
        Stop();
        break;
      case MU_TRAFFIC_CARD_TURN_AROUND:
        Serial.println("turn around");
        turnAround();
        delay(1000);
        Stop();
        break;
      case MU_TRAFFIC_CARD_PARK:
        Serial.println("park");
        break;
      default:
        Serial.print("unknow card type: ");
        Serial.println(Mu.GetValue(VISION_TRAFFIC_CARD_DETECT, kLabel));
        break;
    }
  }
  else
  {
    Serial.println("vision shape card undetected.");
  }
  if (Mu.GetValue(VISION_SHAPE_CARD_DETECT, kStatus)) {
    Serial.println("vision shape card detected:");
    Serial.print("x = ");
    Serial.println(Mu.GetValue(VISION_SHAPE_CARD_DETECT, kXValue));
    Serial.print("y = ");
    Serial.println(Mu.GetValue(VISION_SHAPE_CARD_DETECT, kYValue));
    Serial.print("width = ");
    Serial.println(Mu.GetValue(VISION_SHAPE_CARD_DETECT, kWidthValue));
    Serial.print("height = ");
    Serial.println(Mu.GetValue(VISION_SHAPE_CARD_DETECT, kHeightValue));
    Serial.print("label = ");
    switch (Mu.GetValue(VISION_SHAPE_CARD_DETECT, kLabel)) {
      case MU_SHAPE_CARD_SQUARE:
      Serial.println("square");
      moveForward();
      delay(800);
      turnAround();
      delay(600);
      moveForward();
      delay(800);
      turnAround();
      delay(600);
      moveForward();
      delay(800);
      turnAround();
      delay(600);
      moveForward();
      delay(800);
      turnAround();
      delay(600);
      Stop();
      break;
      case MU_SHAPE_CARD_TRIANGLE:
      Serial.println("trigangle");
      moveForward();
      delay(800);
      turnAround();
      delay(700);
      moveForward();
      delay(800);
      turnAround();
      delay(800);
      moveForward();
      delay(1000);
      turnAround();
      delay(800);
      Stop();
      break;
    }
  }
  else
  {
    Serial.println("vision shape card undetected");
  }
  Serial.print("fps = ");
  Serial.println(1000/(millis()-time_start));
  Serial.println();
}

void moveForward()
{
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);  
}

void turnLeft()
{
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void turnRight()
{
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void turnAround()
{
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void Stop()
{
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
