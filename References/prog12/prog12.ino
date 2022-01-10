int RED, GREEN, BLUE;

void setup()
{
  RED = 2;
  GREEN = 1;
  BLUE = 0;
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop()
{
digitalWrite(RED, HIGH); digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH); delay(500);
digitalWrite(RED, LOW); digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH); delay(500);
digitalWrite(RED, HIGH); digitalWrite(GREEN, LOW);
digitalWrite(BLUE, HIGH); delay(500);
digitalWrite(RED, HIGH); digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, LOW); delay(500);
digitalWrite(RED, LOW); digitalWrite(GREEN, LOW);
digitalWrite(BLUE, HIGH); delay(500);
digitalWrite(RED, HIGH); digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW); delay(500);
digitalWrite(RED, LOW); digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, LOW); delay(500);
digitalWrite(RED, LOW); digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW); delay(500);
}
