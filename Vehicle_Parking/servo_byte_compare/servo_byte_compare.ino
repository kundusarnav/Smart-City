#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

const int RST_PIN = 9;
const int SS_PIN = 10;
MFRC522 mfrc522(SS_PIN, RST_PIN);
byte CardUidByte[4] = {0xDA, 0xA9, 0x56, 0xD3};
boolean state = false;
Servo myservo;
const int servoPin = 5;
const int buzzerPin = 6;

void setup() {
  Serial.begin(9600);  
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Place your TAG near Reader....");
  myservo.attach(servoPin);
  myservo.write(0);
  delay(50);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) return; 
  if ( ! mfrc522.PICC_ReadCardSerial()) return;
  
  if (mfrc522.uid.uidByte[0] == CardUidByte[0] && mfrc522.uid.uidByte[1] == CardUidByte[1] && mfrc522.uid.uidByte[2] == CardUidByte[2] && mfrc522.uid.uidByte[3] == CardUidByte[3])
        {
         state=!state;    
         while (state == true){
           Serial.println("ID Match...Open");
           tone(buzzerPin ,500,250);  //tone(pin, frequency, duration)
           myservo.write(90);
           delay(3000);
           myservo.write(0);
           state=!state;
         }
        }
        
          else{
           Serial.println("Wrong ID ..Entry Denied...!!");
           myservo.write(0);
           tone(buzzerPin ,523,250);    
           delay(250);
           noTone(buzzerPin);
           delay(1000);
         }
         delay(1000);
   }  
