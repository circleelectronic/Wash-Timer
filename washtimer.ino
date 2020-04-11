#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

#define trigpin 8
#define echopin 9

int range;
int time;

byte tap[8] = {
  B11100,
  B01000,
  B11100,
  B00100,
  B00010,
  B01100,
  B00010,
  B00100
};

byte status[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte okey[8] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B01010,
  B01100,
  B01010
};

void setup(){
 pinMode(trigpin, OUTPUT);
 pinMode(echopin, INPUT);
 
 lcd.createChar(0, tap);
 lcd.createChar(1, status);
 lcd.createChar(2, okey);
 
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("Show Your Hands");
 lcd.setCursor(3,1);
 lcd.print("For Start");
}

void loop(){
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin, HIGH);
  range = (time/2) / 28.3; 
  
  if(range>=10&&range<=30){
    Rubbing();
      }  
}

void Rubbing(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(0,1);
  lcd.write("Keep Rub Ur Hand");
  for(int i=1; i<=14 ; i++){
    lcd.setCursor(i,0);
    lcd.write(byte(1));
    delay(1430);
  }  
  lcd.setCursor(15,0);
  lcd.write(byte(2));
  lcd.setCursor(0,1);
  lcd.write("    Good Job!   ");
  delay(10000);
  lcd.setCursor(0,0);
  lcd.print("Show Your Hands");
  lcd.setCursor(0,1);
  lcd.print("    For Start   ");
}
