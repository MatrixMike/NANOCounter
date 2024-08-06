#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

int button1;
int button2;
int button3;
int button4;
int button5;
int button6;

int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;
int count6 = 0;

void reload() {

  lcd.clear();


  lcd.setCursor(0 ,0);
  lcd.print(count1);

  lcd.setCursor(7 ,0);
  lcd.print(count2);

  lcd.setCursor(13 ,0);
  lcd.print(count3);

  lcd.setCursor(0 ,1);
  lcd.print(count4);

  lcd.setCursor(7 ,1);
  lcd.print(count5);

  lcd.setCursor(13 ,1);
  lcd.print(count6);

  tone(8, 500);
  delay(100);
  noTone(8);
}
void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  lcd.setCursor(1 ,0);
  lcd.print("Nasco's Number");
  lcd.setCursor(4 , 1);
  lcd.print("Counter!");

  delay(2000);

  lcd.clear();
  lcd.setCursor(1 ,0);
  lcd.print("Contact me at:");
  lcd.setCursor(2 ,1);
  lcd.print("<censored>");

  delay(2000);



  lcd.clear();

  reload();
}

void loop() {
  button1 = analogRead(A0);
  button2 = analogRead(A1);
  button3 = analogRead(A2);
  button4 = analogRead(A3);
  button5 = analogRead(A6);
  button6 = analogRead(A7);
  Serial.print(" \n ");

  if (button1 != 0) {
    int empty;
    empty = count1 + 1;
    count1 = empty;
    reload();
    while (analogRead(A0) != 0) {}
  }

  if (button2 != 0) {
    int empty;
    empty = count2 + 1;
    count2 = empty;
    reload();
    while (analogRead(A1) != 0) {}
  }

  if (button3 != 0) {
    int empty;
    empty = count3 + 1;
    count3 = empty;
    reload();
    while (analogRead(A2) != 0) {}
  }

  if (button4 != 0) {
    int empty;
    empty = count4 + 1;
    count4 = empty;
    reload();
    while (analogRead(A3) != 0) {}
  }

  if (button5 != 0) {
    int empty;
    empty = count5 + 1;
    count5 = empty;
    reload();
    while (analogRead(A6) != 0) {}
  }

  if (button6 != 0) {
    int empty;
    empty = count6 + 1;
    count6 = empty;
    reload();
    while (analogRead(A7) != 0) {}
  }

  if (digitalRead(9) == HIGH) {
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    count6 = 0;
    reload();
    while (digitalRead(9) == HIGH) {}
  }
  delay(50);
}
