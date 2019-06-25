#include<SoftwareSerial.h>
SoftwareSerial gsmSerial(10,11);//tx,rx
#include<TinyGPS.h>
TinyGPS gps;
SoftwareSerial gpsSerial(3,4);//tx,rx
int state=0;
const int orien=2;
float gpslat,gpslon;
//float gpslat=12.941125;
//float gpslon=80.146530;
void setup()
{
  Serial.begin(9600);
  gsmSerial.begin(9600); 
  gpsSerial.begin(9600);
  pinMode(orien,INPUT);

}

void loop()
{
   //Serial.println("hi");
   while(gpsSerial.available())
    {
     // Serial.println("Entering the GPSmode");
    if(gps.encode(gpsSerial.read()))
      {
        Serial.println("Entering the GPS_Encoding mode");
        gps.f_get_position(&gpslat,&gpslon);
        Serial.print("Position: ");
        Serial.print("Latitude:");
        Serial.println(gpslat,6);
        Serial.println(gpslon,6);
        }
    }
    
  if(state==0&&digitalRead(orien)==1)
  {    
   Serial.println("Entering the mode");
   //if(gsmSerial.available()>0)
    {
      gsmSerial.println("AT+CSMP=17,167,0,0");
      Serial.println("AT+CSMP=17,167,0,0");
      gsmSerial.println("AT+CMGF=1\r"); 
      Serial.println("AT+CMGF=1\r");
      gsmSerial.println("AT+CMGs=\"+919840571695\"\r");
      Serial.println("AT+CMGs=\"+91917530000285\"\r");
      delay(1000);
      gsmSerial.println("Your Ward is fallen down his location is : ");
      gsmSerial.print("https://www.google.com/maps/?q=");
      gsmSerial.print(gpslat, 6);
      gsmSerial.print(",");
      gsmSerial.print(gpslon, 6);
      Serial.println("Hello");
      delay(1000);
      gsmSerial.write(0x1A);
      delay(1000);
      state = 1;  
      Serial.println("Message Sent");     
    }
  }
   if(state==1&&digitalRead(orien)==1)
  {    
   Serial.println("Entering the mode");
   //if(gsmSerial.available()>0)
    
      gsmSerial.println("AT+CSMP=17,167,0,0");
      Serial.println("AT+CSMP=17,167,0,0");
      gsmSerial.println("AT+CMGF=1\r"); 
      Serial.println("AT+CMGF=1\r");
      gsmSerial.println("AT+CMGs=\"+919444868585\"\r");
      Serial.println("AT+CMGs=\"+91917530000285\"\r");
      delay(1000);
      gsmSerial.println("Your Ward is fallen down his location is : ");
      gsmSerial.print("https://www.google.com/maps/?q=");
      gsmSerial.print(gpslat, 6);
      gsmSerial.print(",");
      gsmSerial.print(gpslon, 6);
      Serial.println("Hello");
      delay(1000);
      gsmSerial.write(0x1A);
      delay(1000);
      state = 2;  
      Serial.println("Message Sent");    
   
}
}
  
