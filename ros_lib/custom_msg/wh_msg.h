#ifndef _ROS_custom_msg_wh_msg_h
#define _ROS_custom_msg_wh_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class wh_msg : public ros::Msg
  {
    public:
      typedef float _st_target_deg_type;
      _st_target_deg_type st_target_deg;
      typedef float _st_now_deg_type;
      _st_now_deg_type st_now_deg;
      typedef float _wh_target_vel_type;
      _wh_target_vel_type wh_target_vel;
      typedef float _wh_now_vel_type;
      _wh_now_vel_type wh_now_vel;

    wh_msg():
      st_target_deg(0),
      st_now_deg(0),
      wh_target_vel(0),
      wh_now_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->st_target_deg);
      offset += serializeAvrFloat64(outbuffer + offset, this->st_now_deg);
      offset += serializeAvrFloat64(outbuffer + offset, this->wh_target_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->wh_now_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_target_deg));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_now_deg));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->wh_target_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->wh_now_vel));
     return offset;
    }

    const char * getType(){ return "custom_msg/wh_msg"; };
    const char * getMD5(){ return "f89faf035737b3c1eab14ea32778c58c"; };

  };

}
#endif
