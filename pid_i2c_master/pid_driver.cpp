#include "Arduino.h"
#include "pid_driver.h"
#include "ti2c.h"

// IseMotorDriver::IseMotorDriver(uint8_t i2caddr) {}
// void IseMotorDriver::setSpeed(int power){}
// long IseMotorDriver::encorder(){}

PidDriver::PidDriver(uint8_t i2caddr) :
ti2c(i2caddr){
  // @param uint8_t i2caddr: i2c addr of motor driver
  //initializer
  this->addr = i2caddr;
}

void PidDriver::setdegree(int degree){
  char buf[10];
  sprintf(buf, "%d", degree);
//  Serial.println(buf);
  this->ti2c.sendStr(buf); 
}

long PidDriver::encorder(){
  long count = 0;
  char buf[50];
  this -> ti2c.receiveStr(buf);
  
  count = atol(buf);
  //Serial.println(buf);
  return count;
}
