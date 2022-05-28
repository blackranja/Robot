#include <Wire.h>
#include "LiquidCrystal_I2C_Spark/LiquidCrystal_I2C_Spark.h"

LiquidCrystal_I2C *lcd;

int lastSecond = 0;

void setup(void)
{
  Serial.begin(9600);
  lcd = new LiquidCrystal_I2C(0x27, 16, 2);
  lcd->init();
  lcd->backlight();
  lcd->clear();
  // lcd->autoscroll();
  lcd->setCursor(0, 0);
  lcd->print("  Particle");

  // lcd->noAutoscroll();
  lcd->setCursor(0, 1);

  lcd->print("  Mechatronics ");

  // lcd->noAutoscroll();
  delay(12000);
  lcd->clear();
  delay(1000);
  lcd->noBacklight();
  delay(2000);
  lcd->backlight();
}

void loop(void)
{
  // Demo 1 -flach backlight

  lcd->setCursor(0, 0);

  lcd->print("Read Temprature");
  lcd->setCursor(0, 1);
  lcd->print("Read Humidity");
  delay(3000);
  lcd->clear();
  // Flach backlight 4 times
  for (int thisChar = 0; thisChar < 100; thisChar++)
  {
    for (int i = -40; i < 100; i++)
    {
      lcd->setCursor(0, 0);
      lcd->print("Temp::");
      lcd->print(i);
      lcd->print("'C");
      // delay(1000);
      // lcd->clear();
      lcd->setCursor(0, 1);
      lcd->print("Humidity::");
      lcd->print(thisChar);
      lcd->print("%");
      delay(300);
      lcd->clear();
    }
  }
  // Turn backlight back on

  // set the display to automatically scroll;
  // lcd->autoscroll();
  // print from 0 to 9;
  // Turn off automatic scrolling
  lcd->noAutoscroll();
  // clear screen
  lcd->clear();
  // Delay
  delay(1000);
}
