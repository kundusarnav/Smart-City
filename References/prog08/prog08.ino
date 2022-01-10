int counter, led;

void setup() 
{
  counter = 14;
  for(int i = 0; i<counter; i++ )
    pinMode(i, OUTPUT);
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
led = 0;
for ( int i = 0 ; i < 27; i++)
{
  flash(led, 20);
  if ( i < counter-1 )
  led++;
  else
  led--;
}
}
