#ifndef _ROS_pr_RawPower_h
#define _ROS_pr_RawPower_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr
{

  class RawPower : public ros::Msg
  {
    public:
      typedef int8_t _p1_type;
      _p1_type p1;
      typedef int8_t _p2_type;
      _p2_type p2;
      typedef int8_t _p3_type;
      _p3_type p3;

    RawPower():
      p1(0),
      p2(0),
      p3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_p1;
      u_p1.real = this->p1;
      *(outbuffer + offset + 0) = (u_p1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->p1);
      union {
        int8_t real;
        uint8_t base;
      } u_p2;
      u_p2.real = this->p2;
      *(outbuffer + offset + 0) = (u_p2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->p2);
      union {
        int8_t real;
        uint8_t base;
      } u_p3;
      u_p3.real = this->p3;
      *(outbuffer + offset + 0) = (u_p3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->p3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_p1;
      u_p1.base = 0;
      u_p1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->p1 = u_p1.real;
      offset += sizeof(this->p1);
      union {
        int8_t real;
        uint8_t base;
      } u_p2;
      u_p2.base = 0;
      u_p2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->p2 = u_p2.real;
      offset += sizeof(this->p2);
      union {
        int8_t real;
        uint8_t base;
      } u_p3;
      u_p3.base = 0;
      u_p3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->p3 = u_p3.real;
      offset += sizeof(this->p3);
     return offset;
    }

    const char * getType(){ return "pr/RawPower"; };
    const char * getMD5(){ return "6f7f165af95e0d4a28d278c9de5c4ef3"; };

  };

}
#endif
