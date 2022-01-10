#include<Servo.h>
#define maxdistance 100
// defining the pins
const int trigPin1 = 7;
const int echoPin1 = 5;
const int trigPin2 = 8;
const int echoPin2 = 4;
const int trigPin3 = 9;
const int echoPin3 = 6;
const int servopin = 13;
int irpin = 3;
Servo servo;
// defining variables
long duration1;
long duration2;
long duration3;
int distanceleft;
int distancefront;
int distanceright;
int a=0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);// Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(irpin, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);
  servo.attach(servopin);  
  servo.write(0);


}
void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceleft = duration1 * 0.034 / 2;
  Serial.print("Distance1: ");
  Serial.println(distanceleft);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distancefront = duration2 * 0.034 / 2;
  Serial.print("Distance2: ");
  Serial.println(distancefront);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distanceright = duration3 * 0.034 / 2;
  Serial.print("Distance3: ");
  Serial.println(distanceright);
  int s = digitalRead(irpin);
  if(s==LOW)
    
  { 
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(10, HIGH);
    servo.write(90);
      delay(1000);
    a=1;
    }
  else 
    servo.write(0);
  if ((a==0)&&(s==LOW)&&(distanceleft <= 15 && distancefront > 15 && distanceright <= 15) || (a==0)&&(s==LOW)&&(distanceleft > 15 && distancefront > 15 && distanceright > 15))
  {
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(10,LOW);
    servo.write(90);
  }
    else 
    servo.write(0);
  if ((a==1)&&(s==LOW)||(s==LOW)&&(distanceleft <= 15 && distancefront <= 15 && distanceright > 15)||(s==LOW)&&(distanceleft <= 15 && distancefront <= 15 && distanceright > 15)||(s==LOW)&& (distanceleft <= 15 && distancefront > 15 && distanceright > 15)||(distanceleft <= 15 && distancefront > 15 && distanceright > 15))
  {
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(10, HIGH);
    delay(100);
    servo.write(90);
    a=0;
  }
    else 
    servo.write(0);
  if ((s==LOW)&&(distanceleft > 15 && distancefront <= 15 && distanceright <= 15) ||(s==LOW)&& (distanceleft > 15 && distancefront > 15 && distanceright <= 15) ||(s==LOW)&& (distanceleft > 15 && distancefront <= 15 && distanceright > 15) )
  {
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(2, HIGH);   
    digitalWrite(10, LOW);
    servo.write(90);
  } 
    else 
    servo.write(0);
}


