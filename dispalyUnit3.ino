#include <DHT.h>
#include <Wire.h>
#include "LiquidCrystal_I2C_Spark/LiquidCrystal_I2C_Spark.h"
#define DHTPIN A1
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C *lcd;

int lastSecond = 0;
int dataPin = D6;
int shiftPin = D5;
int storePin = D4;
int numbers[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 110, 158, 28, 252, 122, 182, 238, 236};
int words[] = {31, 47, 123};
int trigPin = D3;
int echoPin = D2;
int lightPin = A0;
long duration;
int distance;

void setup(void)
{
  dht.begin();
  pinMode(lightPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  pinMode(storePin, OUTPUT);
  Serial.begin(9600);
  lcd = new LiquidCrystal_I2C(0x27, 16, 2);
  lcd->init();
  lcd->backlight();
  lcd->clear();
  // lcd->autoscroll();
  lcd->setCursor(0, 0);
  lcd->print("  Particle");
  lcd->setCursor(0, 1);
  lcd->print("  Mechatronics ");
  delay(12000);
  lcd->clear();
  delay(1000);
  lcd->noBacklight();
  delay(2000);
  lcd->backlight();
}

void loop(void)
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
  lcd->clear();
  lcd->setCursor(0, 0);
  lcd->print("Distance :");
  lcd->print(distance);
  lcd->print("cm");

  lcd->setCursor(0, 1);
  lcd->print("Humidity :");
  lcd->print(h);
  lcd->print("%");
  delay(1500);

  lcd->setCursor(0, 1);
  lcd->print("Temprature :");
  lcd->print(t);
  lcd->print("C");
  // clear screen
  // Delay
  // delay(1000);
  for (int i = 0; i <= 2; i++)
  {

    for (int ii = 0; ii < 1000; ii++)
    {

      int datas[] = {t, h, distance};
      int data = datas[i];
      // int firstDigit = data / 1000;
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
