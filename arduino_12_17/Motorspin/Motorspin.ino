#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<Wire.h>
#include<ros.h>
#include<std_msgs/Int16.h>

#include "ti2c.h"
#include "ise_motor_driver.h"

uint8_t addr = 0x13;
IseMotorDriver m1=IseMotorDriver(addr);
ros::NodeHandle nh;

void task_cb(const std_msgs::Int16& msg)
{
 m1.setSpeed(msg.data);
}

ros::Subscriber<std_msgs::Int16>sub("topicA",task_cb);
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
  nh.spinOnce();
}
