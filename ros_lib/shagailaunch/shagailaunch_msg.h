#ifndef _ROS_shagailaunch_shagailaunch_msg_h
#define _ROS_shagailaunch_shagailaunch_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace shagailaunch
{

  class shagailaunch_msg : public ros::Msg
  {
    public:
      typedef int8_t _phase_type;
      _phase_type phase;
      typedef const char* _action_type;
      _action_type action;

    shagailaunch_msg():
      phase(0),
      action("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_phase;
      u_phase.real = this->phase;
      *(outbuffer + offset + 0) = (u_phase.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->phase);
      uint32_t length_action = strlen(this->action);
      varToArr(outbuffer + offset, length_action);
      offset += 4;
      memcpy(outbuffer + offset, this->action, length_action);
      offset += length_action;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_phase;
      u_phase.base = 0;
      u_phase.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->phase = u_phase.real;
      offset += sizeof(this->phase);
      uint32_t length_action;
      arrToVar(length_action, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_action; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_action-1]=0;
      this->action = (char *)(inbuffer + offset-1);
      offset += length_action;
     return offset;
    }

    const char * getType(){ return "shagailaunch/shagailaunch_msg"; };
    const char * getMD5(){ return "5d4369385089c16dc86085a13d1749a8"; };

  };

}
#endif
