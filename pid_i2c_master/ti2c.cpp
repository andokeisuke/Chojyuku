#include "Arduino.h"
#include "ti2c.h"
#include <Wire.h>
#define SIZE 100

const byte postfix = '$';
Ti2c::Ti2c(uint8_t i2caddr){
//initializer
  this->addr = i2caddr;
}

void Ti2c::sendStr(char buf[]){  
  Wire.beginTransmission(this->addr);	 // 
  Wire.write(buf);				// 1バイトをキューへ送信
  Wire.write(postfix);
  Wire.endTransmission();		// 送信完了  
}

void Ti2c::receiveStr(char buf[]){
  char b_buf[SIZE] = "";
  int i = 0;
  long j = 0;
 
   while(1){
     j++;
       //Serial.println(j);
     if (j > 1000){
    
       sprintf(buf, "TimeOut");
       return;
     }
    
       //Serial.println(j);
     Wire.requestFrom(this->addr, uint8_t(10));
     
       //Serial.println(Wire.available());
        byte val;
          
    while (Wire.available()) {
      //Serial.println(j);
      val = Wire.read();
     // Serial.println(atoi(val));
      
      if (val == postfix){
        b_buf[i++] = '\0';
        //Serial.print("oooooooooooooo");
        break;
      } else {
        b_buf[i++] = val;
      }
    }
    if (val == postfix){
      sprintf(buf, "%s", b_buf);
      break;
    }  
  } 
}
