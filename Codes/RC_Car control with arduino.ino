#include <Servo.h>
#include <SoftwareSerial.h>

#define m11 11 // M1a
#define m12 12 // M1b

#define m21 10 // M2a
#define m22 9 // M2b


SoftwareSerial BT (3,2)   // pin 3 for TX and pin 2 for RX
Servo sv;
int servoPin = 13;
int sv_pos = 0;

void forward()
{
digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
}
void backward()
{
digitalWrite(m11, LOW);
digitalWrite(m12, HIGH);
digitalWrite(m21, LOW);
digitalWrite(m22, HIGH);
}

void left()
{

 sv_pos = 65;
 sv.write (sv_pos);
  
digitalWrite(m11, LOW);
digitalWrite(m12, HIGH);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
}

void right()
{

  sv_pos = -65;
  sv.write (sv_pos);
digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);

digitalWrite(m21, LOW);
digitalWrite(m22, HIGH);
}
void Stop()
{
digitalWrite(m11, LOW);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, LOW);
}
void setup()
{
  
Serial.begin(9600);
pinMode(m11, OUTPUT);
pinMode(m12, OUTPUT);
pinMode(m21, OUTPUT);
pinMode(m22, OUTPUT);
sv.attach (servoPin);
}



void loop()
{
while(BT.available())
{
char data = BT.read();
if(data =='1') // forward
{
Serial.println("Forward");
forward();

}
else if(data =='2') //left
{
Serial.println("Left");
left();

}
else if(data =='3') //right
{
Serial.println("right");
right();

}

else if(data =='4') //backward
{
Serial.println("backward");
backward();

}
else if(data =='5') //stop
{
Serial.println("stop");
Stop();
}
else if(data =='6') //right without moving forward
{
 sv_pos = -65;
  sv.write (sv_pos);
forward();

}
else if(data =='7') //left without moving forward
{
 sv_pos = 65;
 sv.write (sv_pos);
forward();
}
sv.write (0);
}
}
