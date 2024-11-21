#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x3F);

void setup() {
  lcd.begin(16, 2);                // مقداردهی اولیه LCD
  lcd.setBacklight(255);           // روشن کردن نور پس‌زمینه
  lcd.setCursor(2, 0);
  lcd.print("Hello World!");
  lcd.setCursor(2, 1);
  lcd.print("Kasra Hassani");
}

void loop() {
}
