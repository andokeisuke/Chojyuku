#ifndef _ROS_chjk_vw_cmd_h
#define _ROS_chjk_vw_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace chjk
{

  class vw_cmd : public ros::Msg
  {
    public:
      typedef double _vx_type;
      _vx_type vx;
      typedef double _vy_type;
      _vy_type vy;
      typedef double _w_type;
      _w_type w;

    vw_cmd():
      vx(0),
      vy(0),
      w(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_vx;
      u_vx.real = this->vx;
      *(outbuffer + offset + 0) = (u_vx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vx.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vx.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vx.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vx.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vx.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vx);
      union {
        double real;
        uint64_t base;
      } u_vy;
      u_vy.real = this->vy;
      *(outbuffer + offset + 0) = (u_vy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vy.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vy.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vy.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vy.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vy.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vy);
      union {
        double real;
        uint64_t base;
      } u_w;
      u_w.real = this->w;
      *(outbuffer + offset + 0) = (u_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_w.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_w.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_w.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_w.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_w.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_w.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_w.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->w);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_vx;
      u_vx.base = 0;
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vx = u_vx.real;
      offset += sizeof(this->vx);
      union {
        double real;
        uint64_t base;
      } u_vy;
      u_vy.base = 0;
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vy = u_vy.real;
      offset += sizeof(this->vy);
      union {
        double real;
        uint64_t base;
      } u_w;
      u_w.base = 0;
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->w = u_w.real;
      offset += sizeof(this->w);
     return offset;
    }

    const char * getType(){ return "chjk/vw_cmd"; };
    const char * getMD5(){ return "461e74593b26c77a7c97f00fe82c6d79"; };

  };

}
#endif
