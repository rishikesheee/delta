#include<dht.h>
#define DHT22_PIN 7
dht DHT;
const int temp=A0;
const int orien=2;
long analog1;
//uploading
long cel1;
long far1;
long roomtemp;
long humidity;
int pos;
void setup()
{
  pinMode(orien,INPUT);
  Serial.begin(9600);
 
}
void loop() 
{
 analog1=analogRead(temp);
 cel1=analog1*500/1023;
 Serial.print(cel1);
 Serial.println("*C");
 far1=(cel1*1.8)+32;
 Serial.print(far1);
 Serial.println("*F");
 delay(1000);
 int chk=DHT.read22(DHT22_PIN);
 roomtemp=DHT.temperature;
 humidity=DHT.humidity;
 Serial.print("Room Temperature : ");
 Serial.println(roomtemp);
 Serial.print("Room Humidity: ");
 Serial.println(humidity);
 delay(2000); 
 if(digitalRead(orien)==0)
 {
  Serial.println("The Wheel Chair is in Normal Position");
  pos=0;
 }
 else
 {
  pos=1;
  Serial.println("The Wheel Chair is not in Normal Position");
 }
 delay(1000);
}
