int myPins[] = {2, 3, 4, 5, 6, 
                7, 8, 9, 10, 11};

void setup()
{
  for(int i = 0; i <= 9; i++ )
  pinMode(myPins[i], OUTPUT);
}

void flash(int led, int duration)
{
  digitalWrite(led, HIGH);
  delay(duration);
  digitalWrite(led, LOW);
  delay(duration);
}

void loop()
{
  for ( int i=0; i<=9; i++ )
  {
    flash(myPins[i], 20);
    flash(myPins[9-i], 20);
  }
}
