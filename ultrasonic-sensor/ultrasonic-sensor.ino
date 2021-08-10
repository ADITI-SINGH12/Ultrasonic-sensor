const int trigPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 8; // Echo Pin of Ultrasonic Sensor 
long duration;
long distance;
void setup() {
  // put your setup code here, to run once:
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600); // Starting Serial Terminal

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
Serial.print("Distance: ");
Serial.print(distance);

}
