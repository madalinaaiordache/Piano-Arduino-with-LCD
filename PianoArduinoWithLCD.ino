#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int cNote = 7;
int dNote = 6;
int eNote = 5;
int fNote = 4;
int gNote = 3;
int aNote = 2;
int bNote = A0;
int Piezo = A2;
double c = 261.63;	// frecventa notei c do 
double d = 293.66;	// frecventa notei d re
double e = 329.63;	// frecventa notei e mi
double f = 349.23;	// frecventa notei f fa
double g = 392;		// frecventa notei g sol 
double a = 440;		// frecventa notei a la 
double b = 493.88;	// frecventa notei b si

void setup()
{
  pinMode(cNote, INPUT);
  pinMode(dNote, INPUT);
  pinMode(eNote, INPUT);
  pinMode(fNote, INPUT);
  pinMode(gNote, INPUT);
  pinMode(aNote, INPUT);
  pinMode(bNote, INPUT);
  pinMode(Piezo, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  
  Serial.println(digitalRead(cNote));
  Serial.println(digitalRead(dNote));
  Serial.println(digitalRead(eNote));
  Serial.println(digitalRead(fNote));
  Serial.println(digitalRead(gNote));
  Serial.println(digitalRead(aNote));
  Serial.println(digitalRead(bNote));
  lcd.setCursor(0, 0);
  lcd.print("");
  
  if (digitalRead(cNote) == 1) {
    tone(Piezo, c, 250);	// nota c
    lcd.setCursor(0, 1);
    lcd.print("DO");
    lcd.setCursor(15, 1);
    lcd.print("C");
  }else if (digitalRead(dNote) == 1) {
    tone(Piezo, d, 250);	// nota d
    lcd.setCursor(0, 1);
    lcd.print("RE");
    lcd.setCursor(15, 1);
    lcd.print("D");
  }else if (digitalRead(eNote) == 1) {
    tone(Piezo, e, 250);	// nota e 
    lcd.setCursor(0, 1);
    lcd.print("MI");
    lcd.setCursor(15, 1);
    lcd.print("E");
  }else if (digitalRead(fNote) == 1) {
    tone(Piezo, f, 250);	// nota f 
    lcd.setCursor(0, 1);
    lcd.print("FA");
    lcd.setCursor(15, 1);
    lcd.print("F");
  }else if (digitalRead(gNote) == 1) {
    tone(Piezo, g, 250);	// nota g 
    lcd.setCursor(0, 1);
    lcd.print("SO");
    lcd.setCursor(15, 1);
    lcd.print("G");
  }else if (digitalRead(aNote) == 1) {
    tone(Piezo, a, 250);	// nota a 
    lcd.setCursor(0, 1);
    lcd.print("LA");
    lcd.setCursor(15, 1);
    lcd.print("A");
  }else if (digitalRead(bNote) == 1) {
    tone(Piezo, b, 250);	// nota b
    lcd.setCursor(0, 1);
    lcd.print("SI");
    lcd.setCursor(15, 1);
    lcd.print("B");
  } else {
    noTone(Piezo);
  }
  delay(10);
}