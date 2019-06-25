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
int pulse,heartBeat;
//Arduino to PLC
#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>
modbusDevice regBank;
modbusSlave slave;
#define RS485TxEnablePin 3
#define RS485Baud 9600
#define RS485Format SERIAL_8E1
//Arduino to PLC ends
void setup()
{
  pinMode(orien,INPUT);
  Serial.begin(9600);
 //Arduino to PLC
  regBank.setId(1);
  regBank.add(30001);  
  regBank.add(30002);
  regBank.add(30003);  
  regBank.add(30004);
  regBank.add(30005);
  regBank.add(40001);  
  regBank.add(40002);
  regBank.add(40003);  
  regBank.add(40004);
  regBank.add(40005);   
  slave._device = &regBank;
  slave.setBaud(&Serial,RS485Baud,RS485Format,RS485TxEnablePin);
 
  //Arduino to PLC ENDS   
 
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
 for(int i=0;i<60;i++)
 {
  pulse=analogRead(A1);
  regBank.set(30004, pulse); 
  delay(900);
  Serial.println(pulse);
  if(pulse>570)
  {
    heartBeat++;
    
  }
 }
   Serial.print("HeartBeat :");
   Serial.println(heartBeat);
 //Arduino to PLC
  regBank.set(30001, far1); 
  regBank.set(30002, roomtemp); 
  regBank.set(30003, humidity); 
  regBank.set(30004, pulse); 
  regBank.set(30005, heartBeat);
  regBank.set(40001, far1); 
  regBank.set(40002, roomtemp); 
  regBank.set(40003, humidity); 
  regBank.set(40004, pulse); 
  regBank.set(40005, heartBeat); 
 digitalWrite(3,HIGH);
  
  slave.run();  
 delay(1000);
}
