#ifndef _ROS_pr_RawEncoder_h
#define _ROS_pr_RawEncoder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr
{

  class RawEncoder : public ros::Msg
  {
    public:
      typedef int16_t _e1_type;
      _e1_type e1;
      typedef int16_t _e2_type;
      _e2_type e2;
      typedef int16_t _e3_type;
      _e3_type e3;

    RawEncoder():
      e1(0),
      e2(0),
      e3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_e1;
      u_e1.real = this->e1;
      *(outbuffer + offset + 0) = (u_e1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_e1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->e1);
      union {
        int16_t real;
        uint16_t base;
      } u_e2;
      u_e2.real = this->e2;
      *(outbuffer + offset + 0) = (u_e2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_e2.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->e2);
      union {
        int16_t real;
        uint16_t base;
      } u_e3;
      u_e3.real = this->e3;
      *(outbuffer + offset + 0) = (u_e3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_e3.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->e3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_e1;
      u_e1.base = 0;
      u_e1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_e1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->e1 = u_e1.real;
      offset += sizeof(this->e1);
      union {
        int16_t real;
        uint16_t base;
      } u_e2;
      u_e2.base = 0;
      u_e2.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_e2.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->e2 = u_e2.real;
      offset += sizeof(this->e2);
      union {
        int16_t real;
        uint16_t base;
      } u_e3;
      u_e3.base = 0;
      u_e3.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_e3.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->e3 = u_e3.real;
      offset += sizeof(this->e3);
     return offset;
    }

    const char * getType(){ return "pr/RawEncoder"; };
    const char * getMD5(){ return "59ec3717b3695a619a871d712fbcd7d8"; };

  };

}
#endif
