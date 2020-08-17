#ifndef _ROS_chjk_unit_cmd_h
#define _ROS_chjk_unit_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace chjk
{

  class unit_cmd : public ros::Msg
  {
    public:
      typedef double _vel_type;
      _vel_type vel;
      typedef double _deg_type;
      _deg_type deg;

    unit_cmd():
      vel(0),
      deg(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_vel;
      u_vel.real = this->vel;
      *(outbuffer + offset + 0) = (u_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vel);
      union {
        double real;
        uint64_t base;
      } u_deg;
      u_deg.real = this->deg;
      *(outbuffer + offset + 0) = (u_deg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deg.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_deg.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_deg.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_deg.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_deg.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->deg);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_vel;
      u_vel.base = 0;
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vel = u_vel.real;
      offset += sizeof(this->vel);
      union {
        double real;
        uint64_t base;
      } u_deg;
      u_deg.base = 0;
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_deg.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->deg = u_deg.real;
      offset += sizeof(this->deg);
     return offset;
    }

    const char * getType(){ return "chjk/unit_cmd"; };
    const char * getMD5(){ return "68a821851e17ec6fee5da92fea03d8fc"; };

  };

}
#endif
