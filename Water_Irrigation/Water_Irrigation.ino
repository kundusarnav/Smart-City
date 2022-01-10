int sensor_pin = A0;
int output_value ;
void setup() {
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

  void loop() {
   output_value= analogRead(sensor_pin);
   output_value = map(output_value,550,10,0,100);
   Serial.print("Mositure : ");
   Serial.print(output_value);
   Serial.println("%");
   if(output_value<0){
      digitalWrite(4,HIGH);
     }
     else{
            digitalWrite(4,LOW);
     }
   delay(1000);
}
