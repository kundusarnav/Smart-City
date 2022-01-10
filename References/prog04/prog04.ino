long counter;
int led1, led2;

void setup() 
{
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  counter = 0;
}

void loop() 
{
  if ( counter % 2 == 0 )
  {
    led1 = 13;
    led2 = 12;
  }
  else
  {
    led1 = 12;
    led2 = 13;
  }

  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(1000);
  counter = counter + 1;
}
