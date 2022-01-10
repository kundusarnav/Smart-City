#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myservo;
Servo myservo2;
Servo myservo3;
Servo myservo4;
String myID = "DAA956D3";
String myID2 = "D0CBD725";
String myID3 = "C0E99D25";
String myID4 = "EDE654D3";
String myID5 = "E92C269";
int servoPin = 5;
int servoPin2 = 6;
int servoPin3 = 7;
int servoPin4 = 8;
int pos;
int pos2;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Put your card or tag at RFID Reader...");
  Serial.println();
  myservo.attach(servoPin);
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);
  myservo4.attach(servoPin4);
  myservo.write(0);
  myservo2.write(0);
  myservo3.write(180);
  myservo4.write(180);
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
    for(pos=0; pos<=90; pos++)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=180; pos2>=90; pos2--)
    {
      myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
    }
    delay(6000);
    for(pos=90; pos>=0; pos--)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=90; pos2<=180; pos2++)
    {
    myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
  }
  }
  if ((newID == myID2))
  {
    Serial.println("ID matches Servo is 90 degree...door open");
    for(pos=0; pos<=90; pos++)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=180; pos2>=90; pos2--)
    {
      myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
    }
    delay(6000);
    for(pos=90; pos>=0; pos--)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=90; pos2<=180; pos2++)
    {
    myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
  }
  }

  if ((newID == myID3))
  {
    Serial.println("ID matches Servo is 90 degree...door open");
    for(pos=0; pos<=90; pos++)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=180; pos2>=90; pos2--)
    {
      myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
    }
    delay(6000);
    for(pos=90; pos>=0; pos--)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=90; pos2<=180; pos2++)
    {
    myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
  }
  }

  if ((newID == myID4))
  {
    Serial.println("ID matches Servo is 90 degree...door open");
    for(pos=0; pos<=90; pos++)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=180; pos2>=90; pos2--)
    {
      myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
    }
    delay(6000);
    for(pos=90; pos>=0; pos--)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=90; pos2<=180; pos2++)
    {
    myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
  }
  }

  if ((newID == myID5))
  {
    Serial.println("ID matches Servo is 90 degree...door open");
    for(pos=0; pos<=90; pos++)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=180; pos2>=90; pos2--)
    {
      myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
    }
    delay(6000);
    for(pos=90; pos>=0; pos--)
    {
    myservo.write(pos);
    myservo2.write(pos);
    delay(10);
    }
    for(pos2=90; pos2<=180; pos2++)
    {
    myservo3.write(pos2);
      myservo4.write(pos2);
      delay(10);
  }
  }
  
  else
  {
    Serial.println("Wrong ID..Servo is 0 degree..door closed");
    myservo.write(0);
    myservo2.write(0);
    myservo3.write(180);
    myservo4.write(180);
    delay(250);
  }
}
