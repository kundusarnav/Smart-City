#include <singleSevSeg.h>
// Set the pins you want (segment a - segment g)
singleSevSeg sevseg(2, 3, 4, 5, 6, 7, 8);

int delayTime = 1000;
// Milliseconds to delay after each number (default 1 second)

void setup() 
{
  // Nothing needs to go here
}

void loop() 
{
  //Cycle from 0-9, then blank
  sevseg.ZERO();
  delay(delayTime);   // Delay for the delay time sepcified in the integer delayTime
  sevseg.ONE();
  delay(delayTime);
  sevseg.TWO();
  delay(delayTime);
  sevseg.THREE();
  delay(delayTime);
  sevseg.FOUR();
  delay(delayTime);
  sevseg.FIVE();
  delay(delayTime);
  sevseg.SIX();
  delay(delayTime);
  sevseg.SEVEN();
  delay(delayTime);
  sevseg.EIGHT();
  delay(delayTime);
  sevseg.NINE();
  delay(delayTime);
  sevseg.CLEAR();   // Include clearing the screen in the display cycle
  delay(delayTime);
}
