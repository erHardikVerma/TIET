                                                                                                                                                                /******************************************************************************
* FileName:        motor_test.ino
* Dependencies:
* Processor:       AVR ATMEGA328P
* Complier:        ARDUINO
*                  ARDUINO IDE
* Company:         Nvis Technologies Pvt. Ltd.
*
*****************************************************************************
* File Description: 
* This program tellls about :
*                           motor interfacing with arduino here we program for forward , backward ,Anti_Rotation
*                          and Clock_Rotation
*                           
*                            
*Change History:
* Name                Date            Changes
* Alok Pindoriya     02/04/16    Initial Version
 ****************************************************************************/

//  initialize digital pin motor as an output
void setup() 
{
  pinMode(5, OUTPUT);   // Right +ve)
  pinMode(6, OUTPUT);   // Right -ve
  pinMode(7, OUTPUT);   // Left -ve
  pinMode(8, OUTPUT);   // Left +ve
}
void forward()
{
  digitalWrite(5,HIGH);   // Right +ve
  digitalWrite(6,LOW);    // Right -ve
  digitalWrite(7,LOW);    // Left -ve
  digitalWrite(8,HIGH);   // Left +ve
}
void Backward()
{
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
void Anti_Rotation()
{
  digitalWrite(5,HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(6,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7,HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8,LOW);   // turn the LED on (HIGH is the voltage level)
}
void Clock_Rotation()
{
  digitalWrite(5,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(6,HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8,HIGH);   // turn the LED on (HIGH is the voltage level)
}
// the loop function runs over and over again forever
void loop()
{
  forward();
  delay(2000);              // wait for a second
  Backward();
  delay(2000); 
  right();
  delay(2000); 
  left();
  delay(2000);            
  Anti_Rotation();
  delay(2000);  
  Clock_Rotation();
  delay(2000); 
}
