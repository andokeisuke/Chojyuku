#ifndef pid_driver_h
#define pid_driver_h
#include "ti2c.h"
#include "Arduino.h"

class PidDriver {
  public:
    PidDriver(uint8_t i2caddr);
    void setdegree(int wheel_degree);
    long encorder();
  private:
    uint8_t addr;
    Ti2c ti2c;
};
#endif
