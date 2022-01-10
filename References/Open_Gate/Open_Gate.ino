#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myservo;
String myID = "DAA956D3";
String myID2 = "D0CBD725";
int buzzer_pin = 6;
int servoPin = 5;
int pos;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Put your card or tag at RFID Reader...");
  Serial.println();
  pinMode(buzzer_pin, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(0);
}

void loop()
{
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  
  Serial.print("ID tag :");
  String newID;
  byte letter;

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    newID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  Serial.println();
  newID.toUpperCase();
  
  if ((newID == myID))
  {
    Serial.println("ID matches Servo is 90 degree...door open");
    tone(buzzer_pin,250,250);
    for(pos=0; pos<=90; pos++)
    {
    myservo.write(pos);
    delay(30);
    }
    delay(6000);
    for(pos=90; pos>=0; pos--)
    {
    myservo.write(pos);
    delay(30);
    }
    noTone(buzzer_pin);
  }

  if ((newID == myID2))
  {
    Serial.println("ID matches Servo is 90 degree...door open");
    tone(buzzer_pin,250,250);
    for(pos=0; pos<=90; pos++)
    {
    myservo.write(pos);
    delay(30);
    }
    delay(6000);
    for(pos=90; pos>=0; pos--)
    {
    myservo.write(pos);
    delay(30);
    }
    noTone(buzzer_pin);
  }
  
  else
  {
    Serial.println("Wrong ID..Servo is 0 degree..door closed");
    myservo.write(0);
    tone(buzzer_pin,250,250);
    delay(250);
  }
}
