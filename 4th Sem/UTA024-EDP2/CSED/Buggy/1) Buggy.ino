void forward(){
  pinMode(5,HIGH);
  pinMode(6,LOW);
  pinMode(7,LOW);
  pinMode(8,HIGH);
}
void backward(){
  pinMode(5,LOW);
  pinMode(6,HIGH);
  pinMode(7,HIGH);
  pinMode(8,LOW);
}
void right(){
  pinMode(5,LOW);
  pinMode(6,LOW);
  pinMode(7,LOW);
  pinMode(8,HIGH);
}
void left(){
  pinMode(5,HIGH);
  pinMode(6,LOW);
  pinMode(7,LOW);
  pinMode(8,LOW);
}
void clockwise(){
  pinMode(5,LOW);
  pinMode(6,HIGH);
  pinMode(7,LOW);
  pinMode(8,HIGH);
}
void anticlockwise(){
  pinMode(5,HIGH);
  pinMode(6,LOW);
  pinMode(7,HIGH);
  pinMode(8,LOW);
}

void setup(){
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}
void loop(){
  forward();
  delay(5000);
  backward();
  delay(5000);
  right();
  delay(5000);
  left();
  delay(5000);
  clockwise();
  delay(5000);
  anticlockwise();
  delay(5000);
}
