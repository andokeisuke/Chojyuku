#ifndef _ROS_custom_msg_valve_msg_h
#define _ROS_custom_msg_valve_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class valve_msg : public ros::Msg
  {
    public:
      typedef bool _state_type;
      _state_type state;
      typedef int8_t _valve_number_type;
      _valve_number_type valve_number;

    valve_msg():
      state(0),
      valve_number(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      union {
        int8_t real;
        uint8_t base;
      } u_valve_number;
      u_valve_number.real = this->valve_number;
      *(outbuffer + offset + 0) = (u_valve_number.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valve_number);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
      union {
        int8_t real;
        uint8_t base;
      } u_valve_number;
      u_valve_number.base = 0;
      u_valve_number.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valve_number = u_valve_number.real;
      offset += sizeof(this->valve_number);
     return offset;
    }

    const char * getType(){ return "custom_msg/valve_msg"; };
    const char * getMD5(){ return "f60ba44565f980103448a6708624440b"; };

  };

}
#endif
