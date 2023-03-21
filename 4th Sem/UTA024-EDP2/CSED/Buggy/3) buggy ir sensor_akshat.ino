void forward(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH); 
}
void backward(){
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
void right(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}
void left(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void stopp(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void clockwise(){
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH);
}
void anticlockwise(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}



void setup(){
  // put your setup code here, to run once:
pinMode(A2,INPUT);
pinMode(A1,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}

void loop(){
  // put your main code here, to run repeatedly:
int l,r;
l=digitalRead(A2);
r=digitalRead(A1);
if(l==0 && r==0){
stopp();
delay(500);
forward();
}
else if(l==0 && r==1)
anticlockwise();
else if(l==1 && r==0)
clockwise();
else if(l==1 && r==1)
forward();
}
