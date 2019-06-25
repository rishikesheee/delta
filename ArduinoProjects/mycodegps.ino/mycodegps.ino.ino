#include<SoftwareSerial.h>
#include<TinyGPS.h>
TinyGPS gps;
SoftwareSerial gpsSerial(3,4);//tx,rx
float lat,lon;
int loc=0;
void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(9600);
  

}

void loop() 
{
  while(gpsSerial.available())
  {
    if(gps.encode(gpsSerial.read()))
    {
      gps.f_get_position(&lat,&lon);
      loc=1;
      Serial.print("Position: ");
      Serial.print("Latitude:");
      Serial.println(lat,6);
      Serial.println(lon,6);
     
    }
  }
  

}
