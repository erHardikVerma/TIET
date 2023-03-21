const int trigpin=13;
const int echopin=12;

long duration;
int distcm,distinch;

void setup() {
    pinMode(trigpin,OUTPUT);
    pinMode(echopin,INPUT);
    Serial.begin(9600);

    pinMode(5,HIGH);
    pinMode(6,HIGH);
    pinMode(7,HIGH);
    pinMode(8,HIGH);
}

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

void anticlockwise(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void clockwise(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}

void stop(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void loop() {

int s=0;
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

duration =pulseIn(echopin,HIGH);
distcm=(duration*0.034)/2;
distinch=(duration*0.0133)/2;

Serial.println(distcm);

if(distcm<30)
{
 
 stop(); 
}
else
{
  forward();
}
}
