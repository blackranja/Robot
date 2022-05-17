//Counting The Advanced Way
//Two 74HC595N and 4Digit 7Segment Display
//Displaying individual segments, This is idile for presenting data from other Input Devices
//This Display will render the Temprature/Humidity/UltraSonic/Light sensor
int dataPin = D6;
int shiftPin = D5;
int storePin = D4;
int numbers[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  pinMode(storePin, OUTPUT);
}
void loop()
{
  // int data = 5432;
  for (int i = 0; i < 9999; i++)
  {
    int data = i;
    int firstDigit = data / 1000;
    int secondDigit = (data / 100) % 10;
    int thirdDigit = (data / 10) % 10;
    int fourthDigit = data % 10;
    digitalWrite(shiftPin, LOW);
    shiftOut(dataPin, storePin, MSBFIRST, 14);
    shiftOut(dataPin, storePin, LSBFIRST, numbers[firstDigit]);
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
