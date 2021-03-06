#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key  key;

int block=2;  
byte blockcontent[16] = {"Mi FARE RFID 13.5MHz"};
byte readbackblock[18];

void setup() 
{
    Serial.begin(9600);
    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("Scan a MIFARE Classic card");
    
    for (byte i = 0; i < 6; i++) {
      key.keyByte[i] = 0xFF;
    }
}

void loop()
{  
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
    Serial.println("card selected");
    writeBlock(block, blockcontent);
    readBlock(block, readbackblock);
    Serial.print("read block: ");
    
    for (int j=0 ; j<16 ; j++)
   {
     Serial.write (readbackblock[j]);
   }
   
   Serial.println("");
}
  
int writeBlock(int blockNumber, byte arrayAddress[]) 
{
  int largestModulo4Number=blockNumber/4*4;
  int trailerBlock=largestModulo4Number+3;
  
  if (blockNumber > 2 && (blockNumber+1)%4 == 0){
    Serial.print(blockNumber);Serial.println(" is a trailer block:");
    return 2;
    }
    
  Serial.print(blockNumber);
  Serial.println(" is a data block:");
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  
  if (status != MFRC522::STATUS_OK) {
         Serial.print("PCD_Authenticate() failed: ");
         Serial.println(mfrc522.GetStatusCodeName(status));
         return 3;
  }
  
  status = mfrc522.MIFARE_Write(blockNumber, arrayAddress, 16);
  
  if (status != MFRC522::STATUS_OK) {
           Serial.print("MIFARE_Write() failed: ");
           Serial.println(mfrc522.GetStatusCodeName(status));
           return 4;
  }
  
  Serial.println("block was written");
}

int readBlock(int blockNumber, byte arrayAddress[]) 
{
  int largestModulo4Number=blockNumber/4*4;
  int trailerBlock=largestModulo4Number+3;
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));

  if (status != MFRC522::STATUS_OK) {
         Serial.print("PCD_Authenticate() failed (read): ");
         Serial.println(mfrc522.GetStatusCodeName(status));
         return 3;
  }

byte buffersize = 18;
status = mfrc522.MIFARE_Read(blockNumber, arrayAddress, &buffersize);

  if (status != MFRC522::STATUS_OK) {
          Serial.print("MIFARE_read() failed: ");
          Serial.println(mfrc522.GetStatusCodeName(status));
          return 4;
  }
  
  Serial.println("block was read");
}
