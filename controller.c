int value1;
int x;
#define led 12
#define bjt 9
#define buzzer 7
void setup()
{
  Serial.begin(9600);
  pinMode(bjt,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  digitalWrite(bjt,LOW);
  digitalWrite(led,LOW);
}

void loop()
{
  Serial.println("Reading");
  while(Serial.available()==0);
  value1 = Serial.read();
  Serial.println(value1);
  if ((value1==1) && (x==0))
  {
    Serial.println("Unlocking");
    digitalWrite(bjt,HIGH);
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(3000);
    digitalWrite(bjt,HIGH);
    digitalWrite(led,LOW);
    x=1;    
  }
  if ((value1==0) && (x==0))
  {
    digitalWrite(buzzer,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    delay(400);
    digitalWrite(buzzer,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    delay(400);
    digitalWrite(buzzer,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
  }
  if ((value1==0) && (x==1))
  {
    digitalWrite(bjt,LOW);
    digitalWrite(buzzer,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    delay(400);
    digitalWrite(buzzer,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    delay(400);
    digitalWrite(buzzer,HIGH);
    delay(400);
    digitalWrite(buzzer,LOW);
    x=0;
  }
}
