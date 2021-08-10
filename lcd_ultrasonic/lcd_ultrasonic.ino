#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7); //rs en d4 d5 d6 d7
const int trigPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 8; // Echo Pin of Ultrasonic Sensor 
long duration;
long distance;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
lcd.setCursor(0,0);
lcd.print("  distance  ");
lcd.setCursor(0,1);
lcd.print("  measurement  ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("  Made By  ");
lcd.setCursor(0,1);
lcd.print("  Aditi  ");
delay(2000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
//clears the trig pin
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
//sets the trig pin on high state for 10 microsecond
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
//reads the echopin ,return the sound travel time in microseconds
duration = pulseIn(echoPin,HIGH);
//Calculating distance
distance = duration * 0.034/2;
lcd.setCursor(0,0);
lcd.print("Distances: ");
lcd.setCursor(0,1);
lcd.print(distance);
lcd.print(" cm ");
delay(10);
;
}
