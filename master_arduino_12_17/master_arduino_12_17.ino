
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <Wire.h>


#include <ros.h>
#include <chjk/unit_cmd.h>



#include "ti2c.h"
#include "ise_motor_driver.h"
#define ENC_PER_ROT 4048//360度のエンコーダの値
#define signal_dot 1000


ros::NodeHandle  nh;

struct MotorHandler
{
  public:
  double target_vel;

};



// ============================== arguments ==============================

IseMotorDriver right_front = IseMotorDriver(0x00);//20
IseMotorDriver right_rear = IseMotorDriver(0x00);//21
IseMotorDriver left_front = IseMotorDriver(0x00);//22
IseMotorDriver left_rear = IseMotorDriver(0x00);//23
IseMotorDriver right_front_st = IseMotorDriver(0x23);//23
IseMotorDriver right_rear_st = IseMotorDriver(0x21);//21
IseMotorDriver left_front_st = IseMotorDriver(0x20);//20
IseMotorDriver left_rear_st = IseMotorDriver(0x22);//22   

                                                         

MotorHandler right_front_handler;
MotorHandler right_rear_handler;
MotorHandler left_front_handler;
MotorHandler left_rear_handler;
MotorHandler right_front_st_handler;
MotorHandler right_rear_st_handler;
MotorHandler left_front_st_handler;
MotorHandler left_rear_st_handler;



// ============================== callback ==============================

void set_target(MotorHandler *mh, MotorHandler *mh_st, double target_vel, double target_deg_st)
{
  mh -> target_vel = target_vel*signal_dot;//[mm/s]
  mh_st -> target_vel = int(target_deg_st*ENC_PER_ROT/360);//[enc]
}




void wh_cb_rfront(const chjk::unit_cmd& msg)
{
  set_target(&right_front_handler, &right_front_st_handler, msg.vel, msg.deg);

 right_front_st.setSpeed(right_front_st_handler.target_vel);
 
 
  right_front.setSpeed(right_front_handler.target_vel);
}

void wh_cb_rrear(const chjk::unit_cmd& msg)
{
  set_target(&right_rear_handler, &right_rear_st_handler, msg.vel, msg.deg);

  right_rear.setSpeed(right_rear_handler.target_vel);
  right_rear_st.setSpeed(right_rear_st_handler.target_vel);
}

void wh_cb_lfront(const chjk::unit_cmd& msg)
{
  
  set_target(&left_front_handler, &left_front_st_handler,  msg.vel, msg.deg);

  left_front.setSpeed(left_front_handler.target_vel);
  left_front_st.setSpeed(left_front_st_handler.target_vel);
  
}

void wh_cb_lrear(const chjk::unit_cmd& msg)
{
  set_target(&left_rear_handler, &left_rear_st_handler,  msg.vel, msg.deg);

  left_rear.setSpeed(left_rear_handler.target_vel);
  left_rear_st.setSpeed(left_rear_st_handler.target_vel);
}


ros::Subscriber<chjk::unit_cmd>right_front_sub("right_front",wh_cb_rfront);
ros::Subscriber<chjk::unit_cmd>right_rear_sub("right_rear",wh_cb_rrear);
ros::Subscriber<chjk::unit_cmd>left_front_sub("left_front",wh_cb_lfront);
ros::Subscriber<chjk::unit_cmd>left_rear_sub("left_rear",wh_cb_lrear);


// ==================== functions ==================== //


void setup() {

  
  Wire.begin();
  // Wire.setClock(400000);
  nh.initNode();
  
  nh.subscribe(right_front_sub);
  nh.subscribe(right_rear_sub);
  nh.subscribe(left_front_sub);
  nh.subscribe(left_rear_sub);



//  nh.advertise(chatter);

 

  
}



void loop() {
 
 delay(1);
  nh.spinOnce();
  
}
