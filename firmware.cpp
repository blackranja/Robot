/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/josphat/projects/rover/ranjaRover/src/firmware.ino"
/*
 * Project ranjaRover
 * Description: "Framework For the Rover"
 * Author: "Josphat Karanja"
 * Date:
 */
void setup();
void demoOne();
void demoTwo();
void loop();
#line 7 "/home/josphat/projects/rover/ranjaRover/src/firmware.ino"
int enA = D2;
int enB = D3;
int in1 = D4;
int in2 = D5;
int in3 = D6;
int in4 = D7;

// setup() runs once, when the device is first turned on.
void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Put initialization like pinMode and begin functions here.
}
void demoOne()
{
  // This function will run the motors in both directions at a fixed speed
  // Turn on MotorA
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0-255
  analogWrite(enA, 200);
  // Turn on MotorB
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
  delay(4000);
  // Change the direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void demoTwo()
{
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  // Turn off the Motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  demoOne();
  delay(1000);

  // The core of your code will likely live here.
}