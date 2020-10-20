#include <Servo.h>

Servo u;
Servo l;
int topleft , downright ,topright , downleft;
int up ,down , left , right ;
int upmax = 135;                              // write maximum angle of up direction obtained from calibration code.
int downmax = 50;                             // write maximum angle of down direction obtained from calibration code.
int leftmax = 1;                              // write maximum angle of left direction obtained from calibration code.
int rightmax = 170;                           // write maximum angle of right direction obtained from calibration code.
int xx = 90;
int yy = 90;
int w,x , y, z;
void setup() {

Serial.begin(9600);
u.attach(9);
l.attach(10);
u.write(90);
l.write(90);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
delay(4000);
}

void loop() {
topleft  =  analogRead(A0);
topright =  analogRead(A1);
downleft =  analogRead(A2);
downright =  analogRead(A3);

w = topleft + topright;
x = downleft + downright;
y = topleft + downleft;
z = topright + topleft;

up = map(w, 0,1024 , 0 ,100);
down = map(x, 0,1024 , 0 ,100); 
left = map(y, 0,1024 , 0 ,100);
right = map(z, 0,1024 , 0 ,100);
Serial.print("\n up :  "); Serial.print(up);
Serial.print("\n down : "); Serial.print(down);
Serial.print("\n left : "); Serial.print(left);
Serial.print("\n right : "); Serial.print(right); 
if(up > down )
{
  if(xx <= upmax)
  {
     xx= xx+1;
     u.write(xx);  
  }}
if(down > up)
{ 
  if(xx >= downmax)
  {
    xx = xx-1;
    u.write(xx);  
  }}
if(left > right)
     {
      if(yy >= 5)
      {
        yy = yy-1;
       l.write(yy);
      }}
if(right > left)
   {
       if(yy <= rightmax)
       {
          yy = yy  + 1;
          l.write(yy); 
       }}
if(abs(up -down <= 3)    && abs(left-right <= 3) )               // cange the value 3 to make it more or less sensitive.
{
 delay(2500);      // increase the delay time to make it less sensitive.
}
delay(20);
}
