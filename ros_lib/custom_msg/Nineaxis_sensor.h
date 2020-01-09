#ifndef _ROS_custom_msg_Nineaxis_sensor_h
#define _ROS_custom_msg_Nineaxis_sensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace custom_msg
{

  class Nineaxis_sensor : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _accl_type;
      _accl_type accl;
      typedef geometry_msgs::Vector3 _gyro_type;
      _gyro_type gyro;
      typedef geometry_msgs::Vector3 _mag_type;
      _mag_type mag;

    Nineaxis_sensor():
      accl(),
      gyro(),
      mag()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->accl.serialize(outbuffer + offset);
      offset += this->gyro.serialize(outbuffer + offset);
      offset += this->mag.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->accl.deserialize(inbuffer + offset);
      offset += this->gyro.deserialize(inbuffer + offset);
      offset += this->mag.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_msg/Nineaxis_sensor"; };
    const char * getMD5(){ return "f88f64117d491e110b918a22793ff2a1"; };

  };

}
#endif
