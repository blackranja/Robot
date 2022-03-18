for (int i = 0; i < 90; i++)
{
    myServo.write(i);
    delay(20);
}
myServo2.write(0);
delay(2000);

myServo2.write(60);
delay(2000);

for (int i = 0; i < 5; i++)
{
    digitalWrite(alarmPin, HIGH);
    delay(200);
    digitalWrite(alarmPin, LOW);
    delay(200);
}
digitalWrite(alarmPin, LOW);
myServo2.write(70);

stepper1.moveTo(-100);
stepper1.runToPosition();
stepper2.moveTo(200);
stepper2.runToPosition();
myServo2.write(70);
delay(2000);
myServo2.write(0);

stepper1.moveTo(100);
stepper1.runToPosition();
stepper2.moveTo(-200);
stepper2.runToPosition();
delay(2000);
myServo2.write(70);

digitalWrite(enA, HIGH);
digitalWrite(enB, HIGH);

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(4000);

digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

delay(4000);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

delay(3000);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(3000);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

delay(3000);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(3000);

// Change the direction
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
myServo2.write(0);
for (int i = 0; i < 15; i++)
{
    digitalWrite(statusPin, HIGH);
    digitalWrite(statusPin2, LOW);
    digitalWrite(statusPin3, HIGH);
    delay(200);
    digitalWrite(statusPin, LOW);
    digitalWrite(statusPin2, HIGH);
    digitalWrite(statusPin3, LOW);
    delay(200);
}
digitalWrite(statusPin, LOW);
digitalWrite(statusPin2, LOW);
digitalWrite(statusPin3, LOW);

for (int iii = 0; iii < 90; iii++)
{
    myServo.write(iii);
    delay(20);
}
myServo2.write(0);
stepper1.moveTo(-100);
stepper1.runToPosition();
stepper2.moveTo(200);
stepper2.runToPosition();
delay(2000);
myServo2.write(70);
myServo2.write(50);
stepper1.moveTo(100);
stepper1.runToPosition();
stepper2.moveTo(-200);
stepper2.runToPosition();
delay(2000);

for (int iiii = 90; iiii > 180; iiii++)
{
    myServo.write(iiii);
    delay(20);
}
stepper1.moveTo(-100);
stepper1.runToPosition();
stepper2.moveTo(200);
stepper2.runToPosition();

delay(2000);
myServo2.write(0);
stepper1.moveTo(100);
stepper1.runToPosition();
stepper2.moveTo(-200);
stepper2.runToPosition();
delay(2000);
for (int iiii = 180; iiii > 90; iiii--)
{
    myServo.write(iiii);
    delay(20);
}
myServo2.write(70);
stepper1.moveTo(-100);
stepper1.runToPosition();
stepper2.moveTo(200);
stepper2.runToPosition();
delay(2000);
myServo2.write(0);
stepper1.moveTo(100);
stepper1.runToPosition();
stepper2.moveTo(-200);
stepper2.runToPosition();
delay(2000);
digitalWrite(enA, HIGH);
digitalWrite(enB, HIGH);

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(4000);

digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

delay(4000);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

delay(3000);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(3000);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

delay(3000);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(3000);

// Change the direction
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
for (int iiii = 90; iiii > 0; iiii--)
{
    myServo.write(iiii);
    delay(20);
}
stepper1.moveTo(-100);
stepper1.runToPosition();
stepper2.moveTo(200);
stepper2.runToPosition();
delay(2000);
myServo2.write(70);
stepper1.moveTo(100);
stepper1.runToPosition();
stepper2.moveTo(-200);
stepper2.runToPosition();
dela