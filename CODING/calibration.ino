#include <Servo.h>

Servo u;
Servo l;
int aa = 90;
int bb = 90;
void setup() 
{
 Serial.begin(9600);
 u.attach(9);
 l.attach(10);
 u.write(90);
 l.write(90); 
}

void loop() 
{
  
  if(Serial.available())
  { 
   int x =  Serial.parseInt();
   if(x == 1)
   {
    aa = aa+5;
     u.write(aa);
     Serial.print("aa =" );Serial.println(aa);   
   }
 else if(x == 2)
    {
      aa = aa-5;
      u.write(aa);
     Serial.print("aa =" );Serial.println(aa);
    }
    else if(x == 3)
    {
      bb =bb+5;
      l.write(bb);
    Serial.print("bb =" );Serial.println(bb); 
    }
    else if(x == 4)
    { bb = bb-5;
      l.write(bb);
     Serial.print("bb =" );Serial.println(bb);
    }
 delay(100);   
  }
 
}
