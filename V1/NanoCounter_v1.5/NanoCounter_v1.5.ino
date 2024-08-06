#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

int buttonreset = 0;

int removed;
int lastpressed;
const int buttons[] = {0, 1, 2, 3, 6, 7};

const int tone1 = 500;

const int tone2 = 650;

const int tone3 = 1000;

const int tone4 = 300;

const int tone5 = 450;

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
}

void setup() {
  Serial.begin(9600);
  
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

  lcd.clear();
  lcd.setCursor(2 ,0);
  lcd.print("NANOCOUNTER");
  lcd.setCursor(2 , 1);
  lcd.print("Version 1.5");

  delay(2000);

  lcd.clear();
  lcd.setCursor(4 ,0);
  lcd.print("A NasCO");
  lcd.setCursor(0 , 1);
  lcd.print("software product");

  delay(2000);

  lcd.clear();
  lcd.setCursor(1 ,0);
  lcd.print("Contact me at:");
  lcd.setCursor(2 ,1);
  lcd.print("<censored>");

  delay(2000);

  lcd.clear();

  reload();

  tone(8, tone1);
  delay(100);
  noTone(8);

  lastpressed = 10;
  //I chose a number that wasn't 0, 1, 2, 3, 6 or 7. 10 was a logical choice.
}

void loop() {
  button1 = analogRead(A0);
  button2 = analogRead(A1);
  button3 = analogRead(A2);
  button4 = analogRead(A3);
  button5 = analogRead(A6);
  button6 = analogRead(A7);
  Serial.print(button1);
  Serial.print(" \t ");
  
  Serial.print(button2);
  Serial.print(" \t ");
  
  Serial.print(button3);
  Serial.print(" \t ");
  
  Serial.print(button4);
  Serial.print(" \t ");
  
  Serial.print(button5);
  Serial.print(" \t ");
  
  Serial.println(button6);
  
  if (digitalRead(9) == HIGH) {
    if(buttonreset == 0){
      int empty;
      empty = buttonreset + 1;
      buttonreset = empty;

      lcd.clear();
      lcd.setCursor(1 ,0);
      lcd.print("Reset mode: See");
      lcd.setCursor(0 ,1);
      lcd.print("back for options");

      tone(8, tone2);
      delay(100);
      noTone(8);

      delay(50);

      tone(8, tone3);
      delay(100);
      noTone(8);
    }

    else if(buttonreset == 1){
      buttonreset = 0;
      
      count1 = 0;
      count2 = 0;
      count3 = 0;
      count4 = 0;
      count5 = 0;
      count6 = 0;
      reload();

      tone(8, tone2);
      delay(100);
      noTone(8);

      delay(50);

      tone(8, tone3);
      delay(100);
      noTone(8);

      delay(50);

      tone(8, tone2);
      delay(100);
      noTone(8);

    }
    while (digitalRead(9) == HIGH) {}
  }



  
  if(button1 != 0){
    if(buttonreset == 1){
      buttonreset = 0;
      reload();
      tone(8, tone4);
      delay(100);
      noTone(8);
      while(analogRead(A0) != 0) {}
      }

    else{
      buttonreset = 0;
      removed = 0;
      lastpressed = buttons[1];
      int empty;
      empty = count1 + 1;
      count1 = empty;
      reload();
      tone(8, tone1);
      delay(100);
      noTone(8);
      while(analogRead(A0) != 0) {}
    }
  }




  if(button2 != 0){
    if(buttonreset == 1){
      while (analogRead(A1) != 0) {}
      }

    else{
      buttonreset = 0;
      removed = 0;
      lastpressed = buttons[2];
      int empty;
      empty = count2 + 1;
      count2 = empty;
      reload();
      tone(8, tone2);
      delay(100);
      noTone(8);
      while(analogRead(A1) != 0) {}
    }
  }




  if (button3 != 0) {
    if(buttonreset == 1){
      while (analogRead(A2) != 0) {}
      }

    else{
      buttonreset = 0;
      removed = 0;
      lastpressed = buttons[3];
      int empty;
      empty = count3 + 1;
      count3 = empty;
      reload();
      tone(8, tone1);
      delay(100);
      noTone(8);
      while (analogRead(A2) != 0) {}
    }
  }


  if(button4 != 0) {
    if(buttonreset == 1){
      while(analogRead(A3) != 0) {}
      }
      
    else{
      buttonreset = 0;
      removed = 0;
      lastpressed = buttons[4];
      int empty;
      empty = count4 + 1;
      count4 = empty;
      reload();
      tone(8, tone2);
      delay(100);
      noTone(8);
      while(analogRead(A3) != 0) {}
    }
  }




  if(button5 != 0) {
    if(buttonreset == 1){
      while(analogRead(A6) != 0) {}
      }
    
    else{
      buttonreset = 0;
      removed = 0;
      lastpressed = buttons[5];
      int empty;
      empty = count5 + 1;
      count5 = empty;
      reload();
      tone(8, tone1);
      delay(100);
      noTone(8);
      while (analogRead(A6) != 0) {}
    }
  }
  



  if(button6 != 0) {
    if(buttonreset == 1){
      if(removed == 0){
        int empty;
      
        buttonreset = 0;
      
        if(lastpressed == buttons[1]){
          empty = count1 - 1;
          count1 = empty;
          removed = 1;
        }
      
        if(lastpressed == buttons[2]){
          empty = count2 - 1;
          count2 = empty;
          removed = 1;
        }
      
        if(lastpressed == buttons[3]){
          empty = count3 - 1;
          count3 = empty;
          removed = 1;
        }
      
        if(lastpressed == buttons[4]){
          empty = count4 - 1;
          count4 = empty;
          removed = 1;
        }

        if(lastpressed == buttons[5]){
          empty = count5 - 1;
          count5 = empty;
          removed = 1;
        }

        if(lastpressed == buttons[6]){
          empty = count6 - 1;
          count6 = empty;
          removed = 1;
        }
      
        reload();
        tone(8, tone2);
        delay(100);
        noTone(8);

      
        delay(50);

      
        tone(8, tone1);
        delay(100);
        noTone(8);

      
        delay(50);

      
        tone(8, tone5);
        delay(100);
        noTone(8);
      
        while (analogRead(A7) != 0) {}
      }
    }
    else{
      buttonreset = 0;
      removed = 0;
      lastpressed = buttons[6];
      int empty;
      empty = count6 + 1;
      count6 = empty;
      reload();
      tone(8, tone2);
      delay(100);
      noTone(8);

      while (analogRead(A7) != 0) {}
    }
  }
  delay(50);
}
