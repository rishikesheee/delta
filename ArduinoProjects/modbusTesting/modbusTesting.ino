#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>
modbusDevice regBank;
modbusSlave slave;
#define RS485TxEnablePin 1
#define RS485Baud 9600
#define RS485Format SERIAL_8E1
int a=10,b=20,c=30,d=35,e=20;
void setup()
{   
  regBank.setId(1);
  regBank.add(40001);  
  regBank.add(40002);
  regBank.add(40003);  
  regBank.add(40004);
  regBank.add(40005);   
  slave._device = &regBank;
  slave.setBaud(&Serial,RS485Baud,RS485Format,RS485TxEnablePin);   

}

void loop()
{
  
  regBank.set(40001, a); 
  regBank.set(40002, b); 
  regBank.set(40003, a); 
  regBank.set(40004, b); 
  regBank.set(40005, a); 
  slave.run();  
}
