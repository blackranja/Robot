//Read Temperature ,humidity and measure distance displaying the data to 4-Digit-7-Segment Display
//HardWare used ( 4Digit-7Segment-1pc, 74HC595N[shiftRegester]-2pcs, DHT-22[temp/humidity sensor]-1pc, HC-SR04[Ultra-Sonic sensor]-1pc
//This is the protoType code which helped in establishing the Primary Display For The Rover
//#include <Adafruit_Sensor.h>
#include <DHT.h>
//#include <DHT_U.h>

#define DHTPIN A1
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
// uint32_t delayMS;
int dataPin = D6;
int shiftPin = D5;
int storePin = D4;
int numbers[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 110, 158, 28, 252, 122, 182, 238, 236};
int words[] = {31, 47, 123};
int trigPin = C2;
int echoPin = C1;
long duration;
int distance;
void setup()
{

  dht.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  pinMode(storePin, OUTPUT);
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  // float f = dht.readTemperature(true);
  // int data = 5432;

  // int datas[] = {5421, 2345, 8976, 5496, 2367, 9248, 3214, 6543, 2789, 0736};

  // sensors_event_t event;
  for (int i = 0; i <= 2; i++)
  {

    for (int ii = 0; ii < 1000; ii++)
    {

      int datas[] = {t, h, distance};
      int data = datas[i];
      int firstDigit = data / 1000;
      int secondDigit = (data / 100) % 10;
      int thirdDigit = (data / 10) % 10;
      int fourthDigit = data % 10;
      digitalWrite(shiftPin, LOW);
      shiftOut(dataPin, storePin, MSBFIRST, 14);
      shiftOut(dataPin, storePin, LSBFIRST, words[i]);
      digitalWrite(shiftPin, HIGH);
      delay(1);
      digitalWrite(shiftPin, LOW);
      shiftOut(dataPin, storePin, MSBFIRST, 13);
      shiftOut(dataPin, storePin, LSBFIRST, numbers[secondDigit]);
      digitalWrite(shiftPin, HIGH);
      delay(1);
      digitalWrite(shiftPin, LOW);
      shiftOut(dataPin, storePin, MSBFIRST, 11);
      shiftOut(dataPin, storePin, LSBFIRST, numbers[thirdDigit]);
      digitalWrite(shiftPin, HIGH);
      delay(1);
      digitalWrite(shiftPin, LOW);
      shiftOut(dataPin, storePin, MSBFIRST, 7);
      shiftOut(dataPin, storePin, LSBFIRST, numbers[fourthDigit]);
      digitalWrite(shiftPin, HIGH);
      delay(1);
      digitalWrite(shiftPin, LOW);
    }
  }
}
