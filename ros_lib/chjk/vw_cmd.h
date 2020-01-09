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
      typedef float _vx_type;
      _vx_type vx;
      typedef float _vy_type;
      _vy_type vy;
      typedef float _w_type;
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
      offset += serializeAvrFloat64(outbuffer + offset, this->vx);
      offset += serializeAvrFloat64(outbuffer + offset, this->vy);
      offset += serializeAvrFloat64(outbuffer + offset, this->w);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->w));
     return offset;
    }

    const char * getType(){ return "chjk/vw_cmd"; };
    const char * getMD5(){ return "461e74593b26c77a7c97f00fe82c6d79"; };

  };

}
#endif
