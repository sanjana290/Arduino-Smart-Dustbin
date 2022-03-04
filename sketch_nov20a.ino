#include <Servo.h> // including servo motor library
Servo servoMain; // Define our Servo or creating object of servo class
int trigpin = 2;// Defining the trigger pin
int echopin = 3;// Defining the echopin
int servopin=9;// servo pin at 9th position
int distance;
float duration;
float cm;
void setup(){
  Serial.begin(9600); // begin the serial communication with 9600 baudrate speed
  servoMain.attach(servopin); // connecting object with servo object
  pinMode(trigpin, OUTPUT);// making trig pin for output
  pinMode(echopin, INPUT);// echo pin for input
}
void loop(){
  // giving a short low pulse to ensure a clean hight pulse
  digitalWrite(trigpin, LOW);
  delay(2);
  // giving high pulse
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  // giving low pulse again
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);// echo pin measures the duration in micro seconds
  cm = (duration/58.82);
  distance = cm;
  if(distance <30){// if distance is less than 30 cm then only it rotates
    servoMain.write(180);// servo motor rotate by 180 degree
    delay(300);// servo motor remains open at 180 degree for 300 sec
  }
  else{
    servoMain.write(0); // servo motor remain at 0 degree
    delay(50);// it remains at this position for 50 sec
  }
}
