#ifndef _ROS_custom_msg_RL_h
#define _ROS_custom_msg_RL_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace custom_msg
{

  class RL : public ros::Msg
  {
    public:
      typedef int64_t _right_type;
      _right_type right;
      typedef int64_t _left_type;
      _left_type left;

    RL():
      right(0),
      left(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_right;
      u_right.real = this->right;
      *(outbuffer + offset + 0) = (u_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right);
      union {
        int64_t real;
        uint64_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_right;
      u_right.base = 0;
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right = u_right.real;
      offset += sizeof(this->right);
      union {
        int64_t real;
        uint64_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left = u_left.real;
      offset += sizeof(this->left);
     return offset;
    }

    const char * getType(){ return "custom_msg/RL"; };
    const char * getMD5(){ return "b18a642f9d124a9e6cb20a01284787da"; };

  };

}
#endif
