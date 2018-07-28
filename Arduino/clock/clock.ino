#include <Adafruit_NeoPixel.h>

#include <LiquidCrystal.h>
#define PIN            6
#define NUMPIXELS      16

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int hours;
int minutes;
int value;
int rnd;

void setup() {
  pixels.begin(); 
  lcd.begin(16, 2);  
  Serial.begin(9600);
}

void loop() 
{   
    rnd=0;
    timer();
    rnd=1;
    timer();
}


void timer()
{
  for(int h=15;h>=-1;h--)
  {
    if((h!=1)&&(h!=5)&&(h!=9)&&(h!=13))
    { hours=h;
      pixels.setPixelColor(h, pixels.Color(0,255,0)); 
      pixels.show();
      minute_delay();        
      pixels.setPixelColor(h, pixels.Color(0,0,0));        
    }
  }
  
}
void minute_delay()
{
  for(int m=15;m>=-1;m--)
  { 
    
    if((m!=1)&&(m!=5)&&(m!=9)&&(m!=13)&&(m!=hours))
    {
      minutes=m;
      pixels.setPixelColor(m, pixels.Color(255,0,0)); 
      pixels.show();
      seconds_delay();        
      pixels.setPixelColor(m, pixels.Color(0,0,0));        
    }
    if(m==hours)
    {
      seconds_delay();
    }
  }
}
void seconds_delay()
{
  for(int i=15;i>=-1;i--)
  {             
    if((i!=1)&&(i!=5)&&(i!=9)&&(i!=13)&&(i!=hours)&&(i!=minutes))
    {
      pixels.setPixelColor(i, pixels.Color(0,0,255)); 
      pixels.show();
      delay(1000);        
      pixels.setPixelColor(i, pixels.Color(0,0,0));        
    }  
    else if((i==hours)||i==minutes)
    {
       delay(1000);
    }
  }
}
void print_time(int a)
{
  lcd.clear();
  lcd.print(convert(hours));
  lcd.print(":");
  int m=convert(minutes)*5;
  if(m==60)
  {
    m=0;
  }
  lcd.print(m);
  lcd.print(":");
  m=convert(a)*5;
  if(m==60)
  {
    m=0;
  }
  lcd.print(m);
  lcd.print(" ");
  if(rnd==0)
  {
    lcd.print("A M");
  }
  else if(rnd==1)
  {
    lcd.print("P M");
  }
  
}
int convert(int a)
{
  if(a==15)
  {
    return 12;
  }
  else if(a==14)
  {
    return 1;
  }
   else if(a==12)
  {
    return 2;
  }
   else if(a==11)
  {
   return 3;
  }
   else if(a==10)
  {
    value=4;
  }
   else if(a==8)
  {
    return 5;
  }
   else if(a==7)
  {
    return 6;
  }
   else if(a==6)
  {
    return 7;
  }
   else if(a==4)
  {
    return 8;
  }
   else if(a==3)
  {
    return 9;
  }
   else if(a==2)
  {
    return 10;
  }
   else if(a==0)
  {
    return 11;
  }
}



