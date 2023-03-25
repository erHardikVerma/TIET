void setup() 
{ 
  pinmode(8,OUTPUT); 
  pinmode(9, OUTPUT); 
  pinmode(10, OUTPUT); 
  pinmode(11, OUTPUT); 
  pinmode(12, OUTPUT) ; 
}
void loop()
{ 
  analogWrite(8,255); 
  delay (100); 
  analogWrite(9,150); 
  delay (100); 
  analogWrite(10,50); 
  delay (100); 
  analogWrite(11,10); 
  delay (100);
  analogWrite(12,0); 
  delay(100);
}
