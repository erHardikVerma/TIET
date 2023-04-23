void setup()
{
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  

}

int count=0;

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}

void left()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void stopb()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void right()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}
void loop()
{
  int l,r;
  l=digitalRead(A0);
  r=digitalRead(A1);

  if(l==0 && r==0)
  {
    count++;
    if(count==1)
    {
      forward();
      delay(200);
    }
    if(count==2)
    {
      forward();
      delay(200);
    }
    if(count==3)
    {
      right();
      delay(500);
    }
    if(count==4)
    {
      stopb();
      delay(2000);
      left();
      delay(200);
      forward();
      delay(100);
    }
    if(count==5)
    {
      stopb();
      delay(4000);
      forward();
      delay(100);
    }
    if(count==6)
    {
      stopb();
      exit(0);
    }
  }
  else if(l==0 && r==1)
  left();

  else if(l==1 && r==0)
  right();

  else if(l==1 and r==1)
  forward();
}
