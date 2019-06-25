#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int val;
String tmpstr;

void setup() 
{
  
  lcd.begin(16, 2);
  lcd.clear();
  val=10;
  tmpstr="The Value of Val is :"+String(val);
  lcd.setCursor(0,0);
  lcd.print(tmpstr);
  
}

void loop()
{
  
}
