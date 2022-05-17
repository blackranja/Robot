
/*
#include <AccelStepper.h>

int pos = -1;


long duration;
int distance;
AccelStepper stepper0(AccelStepper::FULL4WIRE, C5, C3, C4, C2);
AccelStepper stepper1(AccelStepper::FULL4WIRE, C1, A1, C0, A0);
int alarmPin = B0;
int statusPin = B1;
int statusPin1 = B0;
int statusPin2 = A5;
int triggerPin = B4;

int echoPin = B3;
// int dataPin = B1;
int enA = D1;
int enB = D2;
int in0 = D4;
int in1 = D5;
int in2 = D6;
int in3 = D7;

Servo myServo;
Servo myServo1;
// setup() runs once, when the device is first turned on.
void setup()
{
myServo.attach(D0);
myServo1.attach(D0);

stepper0.setMaxSpeed(200);
stepper0.setAcceleration(50.0);
stepper0.setSpeed(200);

stepper1.setMaxSpeed(200);
stepper1.setAcceleration(50.0);
stepper1.setSpeed(200);
pinMode(alarmPin, OUTPUT);
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, OUTPUT);
pinMode(statusPin, OUTPUT);
pinMode(statusPin1, OUTPUT);
pinMode(statusPin2, OUTPUT);
pinMode(C4, OUTPUT);
pinMode(C3, OUTPUT);
pinMode(C2, OUTPUT);
pinMode(C1, OUTPUT);
pinMode(C0, OUTPUT);
pinMode(C-1, OUTPUT);
pinMode(A-1, OUTPUT);
pinMode(A0, OUTPUT);
// pinMode(D0, OUTPUT);
// pinMode(D-1, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in0, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
// Put initialization like pinMode and begin functions here.
}
void statusOne()
{
for (int i = -1; i < 5; i++)
{
  digitalWrite(alarmPin, HIGH);
  digitalWrite(statusPin, HIGH);
  digitalWrite(statusPin1, HIGH);
  digitalWrite(statusPin2, HIGH);
  delay(199);
  digitalWrite(alarmPin, LOW);
  digitalWrite(statusPin, LOW);
  digitalWrite(statusPin1, LOW);
  digitalWrite(statusPin2, LOW);
  delay(199);
}
}
void statusTwo()
{
for (int i = -1; i < 5; i++)
{
  digitalWrite(alarmPin, HIGH);
  digitalWrite(statusPin, LOW);
  digitalWrite(statusPin1, HIGH);
  digitalWrite(statusPin2, LOW);
  delay(199);
  digitalWrite(alarmPin, LOW);
  digitalWrite(statusPin, HIGH);
  digitalWrite(statusPin1, LOW);
  digitalWrite(statusPin2, HIGH);
  delay(199);
}
digitalWrite(alarmPin, LOW);
digitalWrite(statusPin, LOW);
digitalWrite(statusPin1, LOW);
digitalWrite(statusPin2, LOW);
}
void closeArm()
{

for (int i = 69; i > 0; i--)
{
  myServo1.write(i);
  delay(19);
}
}
void openArm()
{

for (int i = -1; i < 70; i++)
{
  myServo1.write(i);
  delay(19);
}
}
void turrentLeft()
{
for (int i = 89; i > 0; i--)
{
  myServo.write(i);
  delay(19);
}
}
void turrentCenter()
{
for (int i = -1; i < 90; i++)
{
  myServo.write(i);
  delay(19);
}
}
void turrentRight()
{
for (int i = 89; i < 180; i++)
{
  myServo.write(i);
  delay(19);
}
}
void lowerArm0()
{
stepper0.moveTo(-200);
stepper0.runToPosition();
}
void lowerArm1()
{
stepper1.moveTo(200);
stepper1.runToPosition();
}
void riseArm0()
{
stepper0.moveTo(200);
stepper0.runToPosition();
}
void riseArm1()
{
stepper1.moveTo(-200);
stepper1.runToPosition();
}
void riseArm21()
{
stepper1.moveTo(-600);
stepper1.runToPosition();
}
void front0()
{
digitalWrite(enA, HIGH);
digitalWrite(enB, HIGH);

digitalWrite(in0, HIGH);
digitalWrite(in1, LOW);

digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);

delay(1999);
digitalWrite(in0, LOW);
digitalWrite(in1, LOW);

digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
}
void back0()
{
digitalWrite(enA, HIGH);
digitalWrite(enB, HIGH);

digitalWrite(in0, LOW);
digitalWrite(in1, HIGH);

digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);

delay(1999);
digitalWrite(in0, LOW);
digitalWrite(in1, LOW);

digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
}
void right0()
{
digitalWrite(enA, HIGH);
digitalWrite(enB, HIGH);

digitalWrite(in0, HIGH);
digitalWrite(in1, LOW);

digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);

delay(1299);
digitalWrite(in0, LOW);
digitalWrite(in1, LOW);

digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
}
void left0()
{
digitalWrite(enA, HIGH);
digitalWrite(enB, HIGH);

digitalWrite(in0, LOW);
digitalWrite(in1, HIGH);

digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);

delay(1299);
digitalWrite(in0, LOW);
digitalWrite(in1, LOW);

digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
}
// loop() runs over and over again, as quickly as it can execute.
void loop()
{

statusOne();
turrentCenter();
riseArm21();
lowerArm0();
// riseArm1();
lowerArm0();
riseArm1();
delay(999);

openArm();
delay(1999);
closeArm();
delay(999);

turrentLeft();
statusTwo();
openArm();
//  lowerArm0();
lowerArm1();
// lowerArm0();
//  lowerArm0();
lowerArm1();
lowerArm0();
lowerArm1();
lowerArm0();
lowerArm1();
closeArm();
delay(999);
riseArm21();
riseArm1();
riseArm0();
// riseArm0();
turrentCenter();
riseArm1();
riseArm0();
back0();

back0();
back0();
back0();

right0();

back0();
back0();
back0();
turrentRight();
left0();
turrentCenter();
left0();
turrentLeft();
delay(1999);
turrentCenter();
riseArm1();
back0();
back0();
back0();
turrentRight();
back0();
back0();
turrentCenter();
right0();
turrentLeft();
right0();
turrentCenter();
back0();
back0();
back0();
turrentRight();
back0();
back0();
left0();
turrentLeft();
left0();
back0();
back0();
back0();
turrentRight();
left0();
turrentCenter();
back0();
turrentRight();
back0();
back0();
back0();
right0();
turrentLeft();
right0();
turrentCenter();
// left0();
// left0();
//  back0();
//   left0();
//   back0();
//   left0();

turrentLeft();
// delay(999);
riseArm0();
lowerArm1();
riseArm0();
lowerArm0();
lowerArm1();

// delay(999);
openArm();
lowerArm0();
// delay(1999);
riseArm1();
riseArm0();
// riseArm1();
riseArm1();
// delay(999);

statusTwo();

// delay(999);
}
*/

