#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte ROWS = 2; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'B','R','Y'},
  {'G','C','M'}
};
byte rowPins[ROWS] = {9, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.cursor();
}

void loop(){
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    lcd.clear(); 
    //Serial.println(key);
    lcd.write(key);
  }
}
