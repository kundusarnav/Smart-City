#include <LiquidCrystal.h>
int pos=0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int trigPin = 9;
const int echoPin = 10;
//const int buzz=6;
long duration;
int distance;
int tankheight = 11;

void setup()  
{
lcd.begin(16, 2);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600);
lcd.setCursor(0,0); 
lcd.print("TANKHEIGHT=");
lcd.print(tankheight);
lcd.print("CM");
}

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
int h= tankheight-distance;
Serial.println(h);
delay(500);
lcd.setCursor(10,1);
lcd.print(h);
lcd.print("CM  ");
int x=h;

if(h<=2&&h>=0)
{
  //analogWrite(buzz,200);
  lcd.setCursor(0,0); 
  lcd.print("TANKHEIGHT=");
  lcd.print(tankheight);
  lcd.print("CM   ");
  delay(1000);
  Serial.println("MOTOR ON");
  lcd.setCursor(0,1);
  lcd.print("MOTOR ON ");  
  //analogWrite(buzz,200);                           
}

else if(x==2)
{
  for(x=2;x<=9;x++)
  {
  lcd.setCursor(0,1);
  lcd.print("MOTOR ON "); 
  }
  //analogWrite(buzz,0);
}

else if(h>2&&h<9)
{
  //analogWrite(buzz,0);
}

else if(x==9)
{
  for(x=9;x>=2;x--)
  {
  lcd.setCursor(0,1);
  lcd.print("MOTOR OFF"); 
  }
  //analogWrite(buzz,0);
}

else if(x==9)
{
  lcd.print("MOTOR OFF");   
  //analogWrite(buzz,200);
}

else if(h>=9&&h<=11)
{
  //analogWrite(buzz,200);
  lcd.setCursor(0,0); 
  lcd.print("TANKHEIGHT=");
  lcd.print(tankheight);
  lcd.print("CM  ");
  delay(500);
  Serial.println("MOTOR OFF"); 
  lcd.setCursor(0,1);
  lcd.print("MOTOR OFF");    
}
}
