
#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 int i = 0;
void setup() {
 
  lcd.begin(16, 2);
  
}

void loop() {
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("WELCOME!");
  lcd.clear();
  lcd.setCursor(i, 0);
  i++;
  if (i >= 15) {
    i = 0;
  }
  lcd.print("IOT Weather and");
  lcd.setCursor(1, 1);
  lcd.print("Safety Monitor");
 delay(1000);
}
