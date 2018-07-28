
#include <Adafruit_NeoPixel.h>

#include <LiquidCrystal.h>
#define PIN            6
#define NUMPIXELS      16

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int button=9;
int hr=0;
int minu=0;
int hr_set;
int min_set;
int value;
int skip;


void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  randomSeed(analogRead(0)); // to generate random seeds.
  //lcd.createChar(0, smiley);
  lcd.begin(16, 2);  
  Serial.begin(9600);
  pinMode(button,INPUT);
}

void loop() {

    
    generate_time();
    delay(2500);

  }
void generate_time()
{
  lcd.print("start");
  Serial.print("start");
  delay(1000);
  skip=0;
  hr_set=-1;
  min_set=-1;
  hr=random(1,13);
  minu=random(10)*5;
  PrintToLcd(hr,minu);
  generating_hours();
  if(skip==0)
  {
  generating_hours();
  if(skip==0)
  {
  lcd.clear();
  delay(500);
  lcd.print("Results:...");
  Serial.println("Results...");
  delay(3000);
  //Serial.println(hr_set);
  //Serial.println(min_set);
  
  hr_set=return_convert(hr_set);
  min_set=return_convert(min_set)*5;

  //Serial.println(hr_set);
  //Serial.println(min_set);
  
  if(min_set==60)
  {
    min_set=0;
  }
  if((hr_set==hr) &&(min_set==minu))
  {
    smile();
  }
  else
  {
    depress();
  }
  }
  }
  reset();
  lcd.clear();
  
}
void PrintToLcd (int a , int b)
{
    lcd.clear ();
    lcd.print (a);
    lcd.print(":");
    lcd.print(b);
    
}
void generating_hours()
{
   for(int i=15;i>=-1;i--)
   {
      if(i!=-1)
      {
      if((i!=1)&&(i!=5)&&(i!=9)&&(i!=13))
      {
        pixels.setPixelColor(i, pixels.Color(124,252,0)); 
        pixels.show();
        delay(1000);
        if((digitalRead(button)==LOW)&&(hr_set==-1))
        {
         pixels.setPixelColor(i, pixels.Color(255,0,0));
         hr_set=i; 
          pixels.show();
          break;
          
        }
        if(digitalRead(button)==LOW&& (hr_set!=-1))
        {
         pixels.setPixelColor(i, pixels.Color(255,0,0));
         min_set=i; 
          pixels.show();
          break;
          
        }
        if(i!=hr_set){
        pixels.setPixelColor(i, pixels.Color(0,0,0));
        delay(1000);
        pixels.show();}
        else      //(i==hr_set)
        {
          pixels.setPixelColor(i, pixels.Color(255,0,0));
        delay(1000);
        pixels.show();
        }
      }
   }
   else
   {
    lcd.clear();
    //lcd.flush();
    delay(500);
    lcd.write("sorry dear be faster");
    skip=1;
    Serial.println("sorry dear be faster");
    delay(1000);
    lcd.clear();
   }
   }
}

void smile()
{
  lcd.clear();
 // lcd.flush();
 delay(500);
  lcd.write("good");
  Serial.println("good");
  delay(1000);
}

void depress()
{
  lcd.clear();
  //lcd.flush();
  delay(500);
  lcd.write("sorry try new");
  Serial.println("sorry try new");
  delay(1000);
}
int return_convert(int a)
{
  if(a==15)
  {
    value=12;
  }
  else if(a==14)
  {
    value=1;
  }
   else if(a==12)
  {
    value=2;
  }
   else if(a==11)
  {
    value=3;
  }
   else if(a==10)
  {
    value=4;
  }
   else if(a==8)
  {
    value=5;
  }
   else if(a==7)
  {
    value=6;
  }
   else if(a==6)
  {
    value=7;
  }
   else if(a==4)
  {
    value=8;
  }
   else if(a==3)
  {
    value=9;
  }
   else if(a==2)
  {
    value=10;
  }
   else if(a==0)
  {
    value=11;
  }
  return value;
}
void reset()
{
  for(int k=0;k<16;k++)
  {pixels.setPixelColor(k, pixels.Color(0,0,0));}
}
    
    
