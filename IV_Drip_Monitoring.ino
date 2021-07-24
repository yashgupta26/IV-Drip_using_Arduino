/*
Defining Libraries, variables and pins to be used in our circuit
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd=LiquidCrystal(2,3,4,5,6,7);

#define LED 13               //pin 13 as led

const int trigPin=11;        //pin 11 as trigpin
const int echoPin=12;        //pin 12 as echopin
float time,distance;


/*
Void setup contains the code that is executed once
and is used to declare the pinMode of a pin, and
baud rate etc
*/

void setup()
{
  
  lcd.begin(16,2);
  pinMode(trigPin,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

/*
Void loop contains our actaul code that will be executed 
repeatedly. Hence our circuit will continue to work.
*/

void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  time=pulseIn(echoPin,HIGH);
  distance=(time*0.0343)/2;       //calculating distance
  
  if(distance > 4){               //if distance is gretaer than
    tone(13,300,1000);            // 4 cm, out bottle is about to
     digitalWrite(LED, HIGH);     //finish. power the buzzer,led
  }

  lcd.setCursor(0,0);
  lcd.print("Distance in cm");     //Display the distance on LCD
  lcd.setCursor(0,1);
  lcd.print(distance);
}


//end of code
