#include <AccelStepper.h>

int pos = 0;
long duration;
int distance;
AccelStepper stepper1(AccelStepper::FULL4WIRE, C5, C3, C4, C2);
AccelStepper stepper2(AccelStepper::FULL4WIRE, C1, A1, C0, A0);
int alarmPin = B1;
int statusPin = B2;
int statusPin2 = B0;
int statusPin3 = A5;
int triggerPin = B5;

int echoPin = B4;
//int dataPin = B2;
int enA = D2;
int enB = D3;
int in1 = D4;
int in2 = D5;
int in3 = D6;
int in4 = D7;

Servo myServo;
Servo myServo2;
// setup() runs once, when the device is first turned on.
void setup()
{
  myServo.attach(D1);
  myServo2.attach(D0);

  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(50.0);
  stepper1.setSpeed(200);

  stepper2.setMaxSpeed(200);
  stepper2.setAcceleration(50.0);
  stepper2.setSpeed(200);
  pinMode(alarmPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, OUTPUT);
  pinMode(statusPin, OUTPUT);
  pinMode(statusPin2, OUTPUT);
  pinMode(statusPin3, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C0, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  //pinMode(D1, OUTPUT);
  //pinMode(D0, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Put initialization like pinMode and begin functions here.
}
void statusOne()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(alarmPin, HIGH);
    digitalWrite(statusPin, HIGH);
    digitalWrite(statusPin2, HIGH);
    digitalWrite(statusPin3, HIGH);
    delay(200);
    digitalWrite(alarmPin, LOW);
    digitalWrite(statusPin, LOW);
    digitalWrite(statusPin2, LOW);
    digitalWrite(statusPin3, LOW);
    delay(200);
  }
}
void statusTwo()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(alarmPin, HIGH);
    digitalWrite(statusPin, LOW);
    digitalWrite(statusPin2, HIGH);
    digitalWrite(statusPin3, LOW);
    delay(200);
    digitalWrite(alarmPin, LOW);
    digitalWrite(statusPin, HIGH);
    digitalWrite(statusPin2, LOW);
    digitalWrite(statusPin3, HIGH);
    delay(200);
  }
}
void closeArm()
{

  for (int i = 70; i > 0; i--)
  {
    myServo2.write(i);
    delay(20);
  }
}
void openArm()
{

  for (int i = 0; i < 70; i++)
  {
    myServo2.write(i);
    delay(20);
  }
}
void turrentLeft()
{
  for (int i = 90; i > 0; i--)
  {
    myServo.write(i);
    delay(20);
  }
}
void turrentCenter()
{
  for (int i = 0; i < 90; i++)
  {
    myServo.write(i);
    delay(20);
  }
}
void turrentRight()
{
  for (int i = 90; i < 180; i++)
  {
    myServo.write(i);
    delay(20);
  }
}
void lowerArm1()
{
  stepper1.moveTo(-200);
  stepper1.runToPosition();
}
void lowerArm2()
{
  stepper2.moveTo(200);
  stepper2.runToPosition();
}
void riseArm1()
{
  stepper1.moveTo(200);
  stepper1.runToPosition();
}
void riseArm2()
{
  stepper2.moveTo(-200);
  stepper2.runToPosition();
}
void front1()
{
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(4000);
}
void back1()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(4000);
}
void right1()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(1500);
}
void left1()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(1500);
}
// loop() runs over and over again, as quickly as it can execute.
void loop()
{

  statusOne();
  turrentCenter();
  riseArm2();
  riseArm2();
  //lowerArm1();
  riseArm2();
  delay(1000);

  openArm();
  delay(2000);
  closeArm();
  delay(1000);

  turrentLeft();
  statusTwo();
  openArm();
  lowerArm1();
  lowerArm2();
  lowerArm2();
  lowerArm1();
  //lowerArm1();
  lowerArm2();
  riseArm1();
  lowerArm2();
  closeArm();
  delay(1000);
  riseArm2();
  riseArm2();
  riseArm1();
  //riseArm1();
  turrentCenter();

  front1();
  right1();

  turrentRight();
  delay(1000);
  lowerArm1();
  lowerArm2();
  lowerArm1();
  lowerArm2();
  delay(1000);
  openArm();
  delay(2000);
  riseArm2();
  riseArm2();
  riseArm1();
  riseArm2();
  delay(1000);

  statusTwo();
  left1();
  back1();
  right1();

  turrentCenter();

  openArm();
  delay(2000);
  closeArm();
  delay(1000);

  delay(1000);
}
