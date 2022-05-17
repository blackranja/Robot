void loop()
{
  digitalWrite(latchpin, LOW);

  for (int i = 0; i < 16; i++)
  {
    digitalWrite(status, HIGH);
    shiftOut(datapin, clockpin, LSBFIRST, 1 << i);
    delay(10);
    // digitalWrite(latchpin, HIGH);
    // delay(10);
    // digitalWrite(latchpin, LOW);
    //  delay(1000);
    //  };
    digitalWrite(status, HIGH);
  };
  digitalWrite(latchpin, HIGH);
  delay(10);
  digitalWrite(latchpin, LOW);

  for (int i = 0; i < 8; i++)
  {
    digitalWrite(status, HIGH);
    shiftOut(datapin, clockpin, MSBFIRST, 1 << i);
    delay(10);
    // digitalWrite(latchpin, HIGH);
    delay(10);
    // digitalWrite(latchpin, LOW);
    // delay(1000);
    // };
    digitalWrite(status, HIGH);
  };
  digitalWrite(latchpin, HIGH);
  delay(10);
  digitalWrite(latchpin, LOW);

  for (int i = 0; i < 16; i++)
  {
    digitalWrite(status, HIGH);
    shiftOut(datapin, clockpin, MSBFIRST, 1024 >> i);
    delay(10);
    // digitalWrite(latchpin, HIGH);
    // delay(10);
    // digitalWrite(latchpin, LOW);
    //  delay(1000);
    //  };
    digitalWrite(status, HIGH);
  };
  digitalWrite(latchpin, HIGH);
  delay(10);
  digitalWrite(latchpin, LOW);

  for (int i = 0; i < 16; i++)
  {
    digitalWrite(status, HIGH);
    shiftOut(datapin, clockpin, MSBFIRST, 2 << i);
    delay(10);
    // digitalWrite(latchpin, HIGH);
    // delay(10);
    // digitalWrite(latchpin, LOW);
    // delay(1000);
    // };
    digitalWrite(status, HIGH);
  };
  digitalWrite(latchpin, HIGH);
  delay(10);
  digitalWrite(latchpin, LOW);

  digitalWrite(status, LOW);
};

