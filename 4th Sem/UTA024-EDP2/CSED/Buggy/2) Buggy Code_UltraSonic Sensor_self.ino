//HR-SR04 (ultrasonic sensor)
//Transmitter+Reciever
//4 Pins 1) VCC 5V 2)Trigger 3)Echo 4)GND
const int trigPin = 13;

const int echoPin = 12;

long duration;

int distanceCm, distanceInch;


void setup() {

pinMode(trigPin, OUTPUT); 
//minimum 10microsecond(pulse rate) is valid trigger [for starting to transmit it must trigger firstly.]
//trigger pin transmits ping.

pinMode(echoPin, INPUT); // echo pins recieves reflection of transmitted signal.


Serial.begin(9600);


// initialize digital pin motor as an output

pinMode(5, OUTPUT); // Right +ve

pinMode(6, OUTPUT); // Right -ve

pinMode(7, OUTPUT); // Left -ve

pinMode(8, OUTPUT); // Left +ve

}

void loop() {

int s=0; //s=speed

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distanceCm= (duration*0.034)/2; //distance= duration/2 because signal travels 2 times

distanceInch = (duration*0.0133)/2;

Serial.println(distanceCm);

if(distanceCm<30) //here we set the object range 15cm.

{
 stop(); 
}
else
{
  forward();
}

}
