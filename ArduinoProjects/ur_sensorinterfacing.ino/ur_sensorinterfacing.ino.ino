const int t1=22;
const int t2=23;
const int t3=24;
const int t4=25;
const int t5=26;
const int t6=27;

const int e1=2;
const int e2=3;
const int e3=4;
const int e4=5;
const int e5=6;
const int e6=7;

const int o1=28;
const int o2=29;
const int o3=30;
const int o4=31;
const int o5=32;
const int o6=33;

long dur1;
long dur2;
long dur3;
long dur4;
long dur5;
long dur6;

int dis1;
int dis2;
int dis3;
int dis4;
int dis5;
int dis6;

void setup() 
{
  pinMode(t1,OUTPUT);
  pinMode(t2,OUTPUT);
  pinMode(t3,OUTPUT);
  pinMode(t4,OUTPUT);
  pinMode(t5,OUTPUT);
  pinMode(t6,OUTPUT);
  
  pinMode(e1,INPUT);
  pinMode(e2,INPUT);
  pinMode(e3,INPUT);
  pinMode(e4,INPUT);
  pinMode(e5,INPUT);
  pinMode(e6,INPUT);
  
  pinMode(o1,OUTPUT);
  pinMode(o2,OUTPUT);
  pinMode(o3,OUTPUT);
  pinMode(o4,OUTPUT);
  pinMode(o5,OUTPUT);
  pinMode(o6,OUTPUT);
  
  Serial.begin(9600);   

}

void loop()
{
 digitalWrite(t1,LOW);
 digitalWrite(t2,LOW);
 digitalWrite(t3,LOW);
 digitalWrite(t4,LOW);
 digitalWrite(t5,LOW);
 digitalWrite(t6,LOW);
 delayMicroseconds(2);
  
 digitalWrite(t1,HIGH);
 delayMicroseconds(10);
 digitalWrite(t1, LOW);
 dur1=pulseIn(e1,HIGH);
 digitalWrite(t2,HIGH);
 delayMicroseconds(10);
 digitalWrite(t2, LOW);
 dur2=pulseIn(e2,HIGH);
 digitalWrite(t3,HIGH);
 delayMicroseconds(10);
 digitalWrite(t3, LOW);
 dur3=pulseIn(e3,HIGH);
 digitalWrite(t4,HIGH);
 delayMicroseconds(10);
 digitalWrite(t4, LOW);
 dur4=pulseIn(e4,HIGH);
 digitalWrite(t5,HIGH);
 delayMicroseconds(10);
 digitalWrite(t5, LOW);
 dur5=pulseIn(e5,HIGH);
 digitalWrite(t6,HIGH);
 delayMicroseconds(10);
 digitalWrite(t6, LOW);
 dur4=pulseIn(e6,HIGH);


 
 dis1=dur1*0.034/2;
 dis2=dur2*0.034/2;
 dis3=dur3*0.034/2;
 dis4=dur4*0.034/2;
 dis5=dur5*0.034/2;
 dis6=dur6*0.034/2;

 dis1=70;
 dis2=70;
 dis3=30;
 dis4=30;
 dis5=30;
 dis6=30;
 
 Serial.print("Distance From UR1:");
 Serial.println(dis1);
 delay(1000);
 Serial.print("Distance From UR2:");
 Serial.println(dis2);
  delay(1000);
 Serial.print("Distance From UR3:");
 Serial.println(dis3);
  delay(1000);
 Serial.print("Distance From UR4:");
 Serial.println(dis4);
 delay(1000);
 Serial.print("Distance From UR5:");
 Serial.println(dis5);
  delay(1000);
 Serial.print("Distance From UR6:");
 Serial.println(dis6);
  delay(1000);
 if(dis1<=60)
 {
  digitalWrite(o1,LOW);
  Serial.println("o1 is Setted");
   delay(500);
   
 }
 else
 {
   digitalWrite(o1,HIGH);
   delay(500);
 }
 
  if(dis2<=60)
 {
  digitalWrite(o2,LOW);
  Serial.println("o2 is Setted");
  delay(500);
  
 }
 else
 {
   digitalWrite(o2,HIGH);
   delay(500);
   
 }

if(dis3<15)
 {
  digitalWrite(o3,LOW);
  Serial.println("o3 is Setted");
  delay(500);
 }
   
 else
 {
   digitalWrite(o3,HIGH);
   delay(500);
 }
  if(dis4<15)
 {
  digitalWrite(o4,LOW);
  Serial.println("o4 is Setted");
  delay(500);
   /*delay(5000);
  digitalWrite(o4,LOW);
  delay(1000);*/
 }
 else
 {
   digitalWrite(o4,HIGH);
   delay(500);
 }
 if(dis5<15)
 {
  digitalWrite(o5,LOW);
  Serial.println("o5 is Setted");
  delay(500);
   /*delay(5000);
  digitalWrite(o4,LOW);
  delay(1000);*/
 }
 else
 {
   digitalWrite(o5,HIGH);
   delay(500);
 }
 if(dis6<15)
 {
  digitalWrite(o6,LOW);
  Serial.println("o6 is Setted");
  delay(500);
   /*delay(5000);
  digitalWrite(o4,LOW);
  delay(1000);*/
 }
 else
 {
   digitalWrite(o6,HIGH);
   delay(500);
 }      
 delay(1000);  
}
