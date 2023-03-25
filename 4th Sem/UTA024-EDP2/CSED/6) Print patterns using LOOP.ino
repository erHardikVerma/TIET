int a;
void setup() {
Serial.begin (9600);
pinMode (6,OUTPUT);
}
void loop(){
for (int i=0;i<30;i++) {
Serial.print ("*");
}
Serial.println("*");
Serial.print ("HARDIK,KHUSHDEEP,DAKSH,KOMAL");
for (int i=0;i<30;i++) {
Serial.print ("_");
}

Serial.println (); 
for (int i=0;i<20;i++) {
Serial.print ("*");
}

Serial.println("");
Serial.print ("Roll no");
for (int i;i<20;i++) {
Serial.print ("_");
}
Serial.println(); for (int i=0;i<10; i++) {
Serial.print ("*");
}
delay(100000);
}
