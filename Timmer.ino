#include <LiquidCrystal.h>
//setup lcd pin by sirial RS,E,D4,D5,D6,D7,D8
LiquidCrystal lcd(1,2,8,9,10,11);
// initial SECOND,Minute,hour == 0;
int s=0,m=0,h=0; 

//resate state
int res = 12;

//sound output using pin no any.  I used 13 for pin output. 
int sound=13;
void setup() {
  lcd.begin(16, 2);  //type of your lcd I used 16,2 lcd 
  pinMode(13,OUTPUT); //setup buzzer output pin. 
  pinMode(12,INPUT);
}

void loop() {
  if(digitalRead(res)!=HIGH){ // reset ushing pin 12
    s=0;
    m=0;h=0;
    lcd.clear();
    lcd.print("reseting");
    delay(5000);
    lcd.clear();
  }
  
  lcd.setCursor(0, 0);
  lcd.print("Timer");
  digitalWrite(sound,LOW); // turn off buzzer at starting at every secound. 
  s++;  //increaseing secoend
 
  if(s%60==0){ //increasing minute after every 60 secound
    m++;
    s=0;
  }

  if(m%60==0&&m!=0){ //increasing hour after every 60 minute
    h++;
    m=0;
  }
  lcd.setCursor(0, 1);
  if(h<10){ //add a zero befor hour if the number stand with single digit
    lcd.print("0");
  }lcd.print(h);
   lcd.print(":");
 
  if(m<10){ //add a zero befor minute if the number stand with single digit
    lcd.print("0");
  } lcd.print(m);
    lcd.print(":");
    
   if(s<10){  //add a zero befor second if the number stand with single digit
    lcd.print("0");
  }
    lcd.print(s);
 
  if(s==0){ //buzzer sund after every minute . 
    digitalWrite(sound,HIGH);
  }
  delay(1000);
}
 
