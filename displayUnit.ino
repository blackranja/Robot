//Count using two Shift Registers
//Produced by: Josphat Karanja;
//Connection involves a cathode 4-Digit-7-Segment With 2(74HC595N) shift-Registers;
//The Code countes from 0000-9999 and loops again with a delay of 100ms;
//The hardware used (Particle Electron,4digit7Segment Display,74HC595N-2pcs,220hms-Resistors-8pcs);
//Connect the Serial_Output from the first shift register to the Serial_Input of the next shift register;

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
  digitalWrite(shiftPin, LOW);
  for (int iiii = 0; iiii < 10; iiii++)
  {

    for (int iii = 0; iii < 10; iii++)
    {

      for (int ii = 0; ii < 10; ii++)
      {

        for (int i = 0; i < 10; i++)
        {
          for (int y = 0; y < 100; y++)
          {

            digitalWrite(shiftPin, LOW);
            shiftOut(dataPin, storePin, MSBFIRST, 7);
            shiftOut(dataPin, storePin, LSBFIRST, numbers[i]);
            digitalWrite(shiftPin, HIGH);
            delay(1);
            digitalWrite(shiftPin, LOW);
            shiftOut(dataPin, storePin, MSBFIRST, 11);
            shiftOut(dataPin, storePin, LSBFIRST, numbers[ii]);
            digitalWrite(shiftPin, HIGH);
            delay(1);
            digitalWrite(shiftPin, LOW);
            shiftOut(dataPin, storePin, MSBFIRST, 13);
            shiftOut(dataPin, storePin, LSBFIRST, numbers[iii]);
            digitalWrite(shiftPin, HIGH);
            delay(1);
            digitalWrite(shiftPin, LOW);
            shiftOut(dataPin, storePin, MSBFIRST, 14);
            shiftOut(dataPin, storePin, LSBFIRST, numbers[iiii]);
            digitalWrite(shiftPin, HIGH);
            delay(1);
            digitalWrite(shiftPin, LOW);
          }
        }
      }
    }
  }
}
