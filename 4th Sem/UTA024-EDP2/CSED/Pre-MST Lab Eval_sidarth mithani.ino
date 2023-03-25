//traffic light code
//intensity on serial monitor eg.746 7 represents intensity for green, 4 for yellow, 6 for red
//also time of glow red>yellow>green

int green=9;
int yellow=10;
int red=11;
int green_time=0;
int yellow_time=0;
int red_time=0;
int gt=0;
int rt=0;
int yt=0;
void setup()
{
 pinMode(green,OUTPUT);
 pinMode(yellow,OUTPUT);
 pinMode(red,OUTPUT);
 Serial.begin(9600);
}
void loop()
{
 if (Serial.available()>0)
 {
 int input=Serial.parseInt();
 if(input>0)
 {
 red_time=input%10;
 rt=red_time*1000;

 yellow_time=(input/10)%10;
 yt=yellow_time*1000;

 green_time=(input/100)%10;
 gt=green_time*1000;

 analogWrite(green,2);
 Serial.print("Go, Green Light is ON (Timer from ");
 Serial.print(green_time);
 Serial.println(" to 0)");
 delay(gt);
 analogWrite(green,0);

 analogWrite(yellow,50);
 Serial.print("Slow down, Yellow Light is ON (Timer from ");
 Serial.print(yellow_time);
 Serial.println(" to 0)");
 delay(yt);
 analogWrite(yellow,0);

 analogWrite(red,255);
 Serial.print("Stop, Red light is ON (Timer from ");
 Serial.print(red_time);
 Serial.println(" to 0)");
 delay(rt);
 analogWrite(red,0);

 delay(10);
 }

}
else
{
 delay(10);
}

}
