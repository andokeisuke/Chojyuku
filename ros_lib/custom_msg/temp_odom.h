#ifndef _ROS_custom_msg_temp_odom_h
#define _ROS_custom_msg_temp_odom_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace custom_msg
{

  class temp_odom : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;

    temp_odom():
      position(),
      velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_msg/temp_odom"; };
    const char * getMD5(){ return "589dbd8c358d253de2ab5441acd36a2b"; };

  };

}
#endif
