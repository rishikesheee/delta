#include<SoftwareSerial.h>
#include<TinyGPS.h>
TinyGPS gps;
SoftwareSerial gpsSerial(3,4);//tx,rx
SoftwareSerial gsmSerial(10,11);//tx,rx
int state=0;
float lat,lon;
void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);  

}

void loop() 
{
   Serial.print("Entering the loop");
  state=0;
  while(gpsSerial.available())
  {
    Serial.println("Entering the gps Mode");
    if(gps.encode(gpsSerial.read()))
    {
      gps.f_get_position(&lat,&lon);
      Serial.print("Position: ");
      Serial.print("Latitude:");
      Serial.println(lat,6);
      Serial.println(lon,6);
      delay(100);
      if(state==0)
      {
        gsmSerial.println("AT+CSMP=17,167,0,0");
        Serial.println("AT+CSMP=17,167,0,0");
        gsmSerial.println("AT+CMGF=1\r");
        Serial.println("AT+CMGF=1\r");
        gsmSerial.println("AT+CMGs=\"+917010766091\"\r");
        Serial.println("AT+CMGs=\"+917010766091\"\r");
        delay(1000);
        gsmSerial.println(" My Wheel Chair is Fallen Down");
        gsmSerial.println("MY Location is :");
        gsmSerial.println("https://www.google.com/maps/?q=");
        gsmSerial.print(lat,6);
        gsmSerial.print(",");
        gsmSerial.print(lon, 6);
        delay(1000);
        gsmSerial.write(0x1A);
        delay(1000);
        state = 1;  
        Serial.println("Message Sent with Location");
        break;   
        
       }
     
    }
   /* else
    {
       if(state==0)
      {
        gsmSerial.println("AT+CSMP=17,167,0,0");
        Serial.println("AT+CSMP=17,167,0,0");
        gsmSerial.println("AT+CMGF=1\r");
        Serial.println("AT+CMGF=1\r");
        gsmSerial.println("AT+CMGs=\"+917010766091\"\r");
        Serial.println("AT+CMGs=\"+917010766091\"\r");
        delay(1000);
        gsmSerial.println(" My Wheel Chair is Fallen Down");
        gsmSerial.println("Please come Quickly and help me");
        Serial.println("Hello");
        delay(1000);
        gsmSerial.write(0x1A);
        delay(1000);
        state = 1;  
        Serial.println("Message Sent");
        break;     
    
      }
    }*/
  }
 
 
}
