const int t1=2;
const int e1=3;
long dur1;
int dis1;

void setup() 
{
  pinMode(t1,OUTPUT);
  pinMode(e1,INPUT);
  Serial.begin(9600);   

}

void loop()
{
 digitalWrite(t1,LOW);
 delayMicroseconds(2);
 digitalWrite(t1,HIGH);
 delayMicroseconds(10);
 digitalWrite(t1, LOW);
 dur1=pulseIn(e1,HIGH);
 dis1=dur1*0.034/2;
 Serial.print("Distance From UR1:");
 Serial.println(dis1);
 delay(1000);
}
