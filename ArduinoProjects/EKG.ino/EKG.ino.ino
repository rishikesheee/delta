#include<Filters.h>
int heart;
void setup() {
 pinMode(10,INPUT);
 pinMode(11,INPUT);
 Serial.begin(9600);

}

void loop()
{
  FilterOnePole lowpassFilter( LOWPASS, 50);
  FilterOnePole highpassFilter( HIGHPASS, 1 );  
  
  if(digitalRead(10)==1|digitalRead(11)==1)
  {
    //Serial.println("!");
    heart=analogRead(A1);
   //heart=lowpassFilter.input(heart);
    //heart=highpassFilter.input(heart);
    Serial.println(heart);
  }
  
  delay(10);

}
