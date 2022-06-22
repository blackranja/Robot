//*****************************************************************************************************************************************//
//Tracked Rover with Arm
//Rover Name: WallEE
//Rover Arm: MeArm
//*************************//
//HardWare Components:
//3pc-74HC595N Shift Registers --Controls The Primary Display, The HeadLights and The Status LEDS
//1pc-Common Cathode 4 Digit 7 Segment Display -- The primary Display 
//2pc-12V DC Motors with Gear Reduction
//1pc-l298N Motor Driver
//2pc-28BYJ-48 Stepper Motors --Motors Used For the MeArm
//2pc-ULN-2003 Motor Driver --Controls The Arm Stepper Motors
//1pc-MG Servo Motor
//1pc-SR Servo Motor
//*************************//
//Firmware version: v0.1
//Framework Modules: 
//DHT-22 -For taking Temp and Humidity Reading
//HC-SR04 -UltraSonic Distance Calculator
//IR Remote -IR Remote Control
//AccelStepper -Arm Control
//L298N -Track Control
//ShiftOut -4Digit-7Segment -Primary Display Unit Control
//************************//
#include <AccelStepper.h>
#include <DHT.h>
#include <IRremote.h>
//#include <DHT_U.h>
#define DHTPIN A4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
// uint32_t delayMS;
int dataPin = B0;
int shiftPin = B1;
int storePin = B2;
int numbers[] = {250, 34, 185, 171, 99, 203, 219, 162, 251, 227};
int words[] = {93, 87, 63, 92};
int pos = -1;
int RECV_PIN = A3;
long duration;
int distance;
int light;
int heads;
AccelStepper stepper0(AccelStepper::FULL4WIRE, C5, C3, C4, C2);
AccelStepper stepper1(AccelStepper::FULL4WIRE, C1, B4, B3, B5);
IRrecv irrecv(RECV_PIN);
decode_results results;
int alarmPin = C0;
int lightPin = A2;

int trigPin = A0;
int echoPin = A1;
int in0 = D6;
int in1 = D5;
int in2 = D4;
int in3 = D3;
int enableOne = D2;
int enableTwo = A5;
int remoteAnswer;
int remoteShift;
bool remoteControl = false;
Servo myServo;
Servo myServo1;
void setup()
{
  dht.begin();
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  myServo.attach(D0);
  myServo1.attach(D1);
  stepper0.setMaxSpeed(200);
  stepper0.setAcceleration(50.0);
  stepper0.setSpeed(200);
  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(50.0);
  stepper1.setSpeed(200);
  pinMode(alarmPin, OUTPUT);

  pinMode(lightPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(C5, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(B5, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(B3, OUTPUT);

  // pinMode(D0, OUTPUT);
  // pinMode(D1, OUTPUT);

  pinMode(in0, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(enableOne, OUTPUT);
  pinMode(enableTwo, OUTPUT);

  pinMode(dataPin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  pinMode(storePin, OUTPUT);
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
  stepper0.moveTo(200);
  stepper0.runToPosition();
}
void lowerArm1()
{
  stepper1.moveTo(-200);
  stepper1.runToPosition();
}
void riseArm0()
{
  stepper0.moveTo(-200);
  stepper0.runToPosition();
}
void riseArm1()
{
  stepper1.moveTo(200);
  stepper1.runToPosition();
}
void riseArm21()
{
  stepper1.moveTo(-600);
  stepper1.runToPosition();
}
void front0()
{
  digitalWrite(enableOne, HIGH);
  digitalWrite(enableTwo, HIGH);
  digitalWrite(in0, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  delay(3999);
  digitalWrite(in0, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(enableOne, LOW);
  digitalWrite(enableTwo, LOW);
}
void back0()
{
  digitalWrite(enableOne, HIGH);
  digitalWrite(enableTwo, HIGH);
  digitalWrite(in0, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  delay(3999);
  digitalWrite(in0, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(enableOne, LOW);
  digitalWrite(enableTwo, LOW);
}
void right0()
{
  digitalWrite(enableOne, HIGH);
  digitalWrite(enableTwo, HIGH);
  digitalWrite(in0, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  delay(1299);
  digitalWrite(in0, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(enableOne, LOW);
  digitalWrite(enableTwo, LOW);
}
void left0()
{
  digitalWrite(enableOne, HIGH);
  digitalWrite(enableTwo, HIGH);

  digitalWrite(in0, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  delay(1299);
  digitalWrite(in0, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(enableOne, LOW);
  digitalWrite(enableTwo, LOW);
}
void loop()
{
  long a = 283967743;
  long b = 283984063;
  long c = 284004463;
  long d = 284012623;
  long e = 284002423;
  if (remoteShift > 4)
  {
    remoteShift = 0;
  }
  if (irrecv.decode(&results))
  {
    Serial.println("        ");
    Serial.println(results.value);
    Serial.println("        ");
    int remoteAnswer = results.value;
    Serial.println(remoteAnswer);
    irrecv.resume(); // Receive the next value
  }

  if (remoteAnswer == a)
  {
    remoteControl = true;
  }
  else if (remoteAnswer == b)
  {
    remoteControl = false;
  }
  else if (remoteAnswer == d)
  {
    remoteShift++;
  }
  if (remoteControl && remoteShift == 0 && remoteAnswer == c)
  {
    front0();
    front0();
  }
  else if (remoteControl && remoteShift == 0 && remoteAnswer == e)
  {
    back0();
    back0();
  }
  else if (remoteControl && remoteShift == 1 && remoteAnswer == c)
  {
    riseArm0();
  }
  else if (remoteControl && remoteShift == 1 && remoteAnswer == e)
  {
    lowerArm0();
  }
  else if (remoteControl && remoteShift == 2 && remoteAnswer == c)
  {
    riseArm1();
  }
  else if (remoteControl && remoteShift == 2 && remoteAnswer == e)
  {
    lowerArm1();
  }
  else if (remoteControl && remoteShift == 3 && remoteAnswer == c)
  {
    right0();
  }
  else if (remoteControl && remoteShift == 3 && remoteAnswer == e)
  {
    left0();
  }
  else if (remoteControl && remoteShift == 4 && remoteAnswer == c)
  {
    turrentRight();
  }
  else if (remoteControl && remoteShift == 4 && remoteAnswer == e)
  {
    turrentLeft();
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  //  Reading temperature or humidity takes about 250 milliseconds!
  //  Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  // float f = dht.readTemperature(true);
  // Take Light Readings from the sensor
  light = analogRead(lightPin);
  Serial.print("Light Intensity");
  Serial.print(light);
  int lp = light / 24;
  Serial.print("Light Percentage");
  Serial.print(lp);
  if (lp < 10)
  {
    // All HeadLights ON
    heads = 160;
  }
  else if (lp > 10 && lp < 30)
  {
    // Threee Lights ON
    heads = 151;
  }
  else if (lp > 30 && lp < 50)
  {
    // Two Light ON
    heads = 153;
  }
  else if (lp > 50 && lp < 70)
  {
    // One Light ON
    heads = 158;
  }
  else if (lp > 80)
  {
    // All Lights OFF
    heads = 143;
  }
  // int heads;
  for (int ii = 0; ii <= 3; ii++)
  {
    // digitalWrite(alarmPin, HIGH);
    for (int i = 0; i < 5000; i++)
    {
      // int status[] = {171, 213, 170};
      int datas[] = {t, h, distance, lp};
      int data = datas[ii];
      // int firstDigit = data / 1000;
      int secondDigit = (data / 100) % 10;
      int thirdDigit = (data / 10) % 10;
      int fourthDigit = data % 10;
      digitalWrite(shiftPin, LOW);
      shiftOut(dataPin, storePin, LSBFIRST, heads);
      shiftOut(dataPin, storePin, LSBFIRST, 127);
      shiftOut(dataPin, storePin, LSBFIRST, words[ii]);
      digitalWrite(shiftPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(shiftPin, LOW);
      // delay(1000);
      //  serial.print(i);

      shiftOut(dataPin, storePin, LSBFIRST, heads);
      shiftOut(dataPin, storePin, LSBFIRST, 191);
      shiftOut(dataPin, storePin, LSBFIRST, numbers[secondDigit]);
      digitalWrite(shiftPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(shiftPin, LOW);
      shiftOut(dataPin, storePin, LSBFIRST, heads);
      shiftOut(dataPin, storePin, LSBFIRST, 223);
      shiftOut(dataPin, storePin, LSBFIRST, numbers[thirdDigit]);
      digitalWrite(shiftPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(shiftPin, LOW);
      shiftOut(dataPin, storePin, LSBFIRST, heads);
      shiftOut(dataPin, storePin, LSBFIRST, 239);
      shiftOut(dataPin, storePin, LSBFIRST, numbers[fourthDigit]);
      digitalWrite(shiftPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(shiftPin, LOW);

      // delay(1000);
    }
    digitalWrite(alarmPin, LOW);
    // delay(1000);
  }

  // delay(999);

  // delay(999);
}
