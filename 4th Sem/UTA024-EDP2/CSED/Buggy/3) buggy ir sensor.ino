void setup() {
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}
void forward() {
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
}
void backward() {
digitalWrite(5,LOW);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
}
void right() {
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
}
void left() {
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
}
void stop() {
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
}
int l,r;
void loop()
{
  l=digitalRead(A0);
  r=digitalRead(A1);
  if(l==1 && r==1)
  {
    forward();
  }
  else if(l==0 && r==0)
  {
    forward();
  }
  else if(l==0&&r==1)
  {
    right();
  }
  else if(l==0&&r==1)
  {
    left();
  }
}
