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
int remoteShift = 1;
int remoteControl = 1;
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
void alarm()
{
  for (int i = 0; i > 5; i++)
  {

    digitalWrite(alarmPin, HIGH);
    delay(500);
    digitalWrite(alarmPin, LOW);
    delay(500);
  }
}
void loop()
{
  // alarm();
  for (int i = 0; i > 5; i++)
  {

    digitalWrite(alarmPin, HIGH);
    delay(1000);
    digitalWrite(alarmPin, LOW);
    delay(1000);
  }

  long a = 0x10ED00FF;
  long b = 0X10ED40BF;
  long c = 0x10EDB04F;
  long d = 0X10ED906F;
  long e = 0X10ED8877;

  if (remoteShift > 5)
  {
    remoteShift = 1;
  }
  if (irrecv.decode(&results))
  {
    long remoteAnswer = results.value;
    Serial.print("InfraRed Signal in HEX");
    Serial.println(results.value, HEX);
    Serial.print("InfraRed Signal");
    Serial.println(remoteAnswer);
    alarm();

    if (remoteAnswer == a)
    {
      remoteControl = 10;
      Serial.println("ON Button");
    }
    if (remoteAnswer == b)
    {
      remoteControl = 20;
      Serial.println("OFF Button");
    }
    if (remoteAnswer == c)
    {
      Serial.println("Enter Button");
      remoteShift++;
    }
    if (remoteControl == 10 && remoteShift == 5 && remoteAnswer == d)
    {
      front0();
      front0();
    }
    if (remoteControl == 10 && remoteShift == 5 && remoteAnswer == e)
    {
      back0();
      back0();
    }
    if (remoteControl == 10 && remoteShift == 1 && remoteAnswer == d)
    {
      riseArm0();
    }
    if (remoteControl == 10 && remoteShift == 1 && remoteAnswer == e)
    {
      lowerArm0();
    }
    if (remoteControl == 10 && remoteShift == 2 && remoteAnswer == d)
    {
      riseArm1();
    }
    if (remoteControl == 10 && remoteShift == 2 && remoteAnswer == e)
    {
      lowerArm1();
    }
    if (remoteControl == 10 && remoteShift == 3 && remoteAnswer == d)
    {
      right0();
    }
    if (remoteControl == 10 && remoteShift == 3 && remoteAnswer == e)
    {
      left0();
    }
    if (remoteControl == 10 && remoteShift == 4 && remoteAnswer == d)
    {
      turrentRight();
    }
    if (remoteControl == 10 && remoteShift == 4 && remoteAnswer == e)
    {
      turrentLeft();
    }
    irrecv.resume(); // Receive the next value
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
  Serial.print("Light Intensity: ");
  Serial.println(light);
  int lp = light / 24;
  Serial.print("Light Percentage: ");
  Serial.print(lp);
  Serial.println("%");
  Serial.print("Remote Shift");
  Serial.println(remoteShift);
  Serial.print("Remote Control");
  Serial.println(remoteControl);
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
  /*
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
*/            
  // delay(999);

  // delay(999);
}
