#include <Wire.h>
#include <stdlib.h>
#include "ti2c.h"
#include "pid_driver.h"

uint8_t addr = 0x21;
PidDriver m1 = PidDriver(addr);
PidDriver m2 = PidDriver(0x33);
int degree = 0;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
////////   
    m1.setdegree(80);
    //m2.setdegree(-60);
//    delay(4000);
//  m1.setdegree(0);
//    delay(4000);
//Serial.print("ssss");
int enc = m1.encorder();
Serial.println(enc);
//delay(100);

 
 // Serial.println(enc);
 
  }
