#include <LiquidCrystal.h>
  int distance_inch;// variable for the distance measurement
  const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
//int potpin=A8;
//int potpin2=A9;
int b=9;
int b2=32;
int val;
int val2;
// Motor A
int enA = 6;
int in1 = 7;
int in2 = 5;

// Motor B

int enB = 3;
int in3 = 2;
int in4 = 4;

int in1V=LOW;
int in2V=HIGH;
int in3V=LOW;
int in4V=HIGH;
bool Direction=0;
bool Direction2=0;
void setup()
{

  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(b,INPUT);
  pinMode(b2,INPUT);
  lcd.begin(20, 4);

}

void Dc_Control()

{
  //Turn ON motors
  digitalWrite(in1, in1V);
  digitalWrite(in2, in2V);
  digitalWrite(in3, in3V);
  digitalWrite(in4, in4V);

  // Set speed to value from potentiometer 
  analogWrite(enA, val);
  analogWrite(enB, val2);
  if(digitalRead(b)==HIGH)
  {
    digitalWrite(in1, !in1V);
    digitalWrite(in2, !in2V);
    Direction=1;
  }
  else
  {
    Direction=0;
  }
  if(digitalRead(b2)==HIGH)
  {
    digitalWrite(in3, !in3V);
    digitalWrite(in4, !in4V);
    Direction2=1;
  }
  else
  {
    Direction2=0;
  }
 
}
void LCD_Print()
{
          
  val = map(val, 0, 1023, 0, 180);                       
  lcd.setCursor(0,0);
  lcd.print("Angle= ");
  lcd.setCursor(7,0);
  lcd.print(val);
  delay(15); 
  lcd.setCursor(0,1);
  lcd.print("Direction= ");  
  lcd.setCursor(10,1);
  if(Direction==0)
  {
    lcd.print("Forward");
  }
  else
  {
    lcd.print("Backward");
  }


  val2 = map(val2, 0, 1023, 0, 180);                       
  lcd.setCursor(0,2);
  lcd.print("Angle= ");
  lcd.setCursor(7,2);
  lcd.print(val2);
  delay(15); 
  lcd.setCursor(0,3);
  lcd.print("Direction= ");  
  lcd.setCursor(10,3);
  if(Direction2==0)
  {
    lcd.print("Forward");
  }
  else
  {
    lcd.print("Backward");
  }
}
void loop()
{

  Dc_Control();
  LCD_Print();
}
