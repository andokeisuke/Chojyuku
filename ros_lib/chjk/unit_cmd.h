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
      typedef float _vel_type;
      _vel_type vel;
      typedef float _deg_type;
      _deg_type deg;

    unit_cmd():
      vel(0),
      deg(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->deg);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->deg));
     return offset;
    }

    const char * getType(){ return "chjk/unit_cmd"; };
    const char * getMD5(){ return "68a821851e17ec6fee5da92fea03d8fc"; };

  };

}
#endif
