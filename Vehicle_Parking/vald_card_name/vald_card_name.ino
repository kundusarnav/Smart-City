#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN  10

struct RFIDTag {
   byte uid[4];
   char *name;
};

struct RFIDTag tags[] = {
   {{0xF5,0x45,0x48,0xE7}, "ALSELECTRO"},
   {{0xE5,0x25,0x28,0xB7}, "myTag_2"},
   };

byte totalTags = sizeof(tags) / sizeof(RFIDTag);
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("RFID reader is ready!");
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      byte *id = mfrc522.uid.uidByte;
      byte idSize = mfrc522.uid.size;
      bool foundTag = false;
      
      for (byte i=0; i<totalTags; i++) {
        if (memcmp(tags[i].uid, id, idSize) == 0) {
          Serial.println(tags[i].name);
          foundTag = true;
          break;
        }
      }

      if (!foundTag) {
        Serial.println("Wrong card!");
      }

      mfrc522.PICC_HaltA();
    } 
}
