#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<Wire.h>
#include<ros.h>
#include<std_msgs/Int16MultiArray.h>

#include "ti2c.h"
#include "ise_motor_driver.h"


uint8_t addr = 0x15;

IseMotorDriver m1=IseMotorDriver(addr);
ros::NodeHandle nh;

int cmd,enc_num,mt_speed,delay_time;
long int enc;

void task_cb(const std_msgs::Int16MultiArray& msg)
{

  cmd= msg.data[0];
  enc_num = msg.data[1];
  mt_speed = msg.data[2];
  delay_time = msg.data[3];

   if(cmd == 1){

    
    m1.setSpeed(-mt_speed);
    /*while(enc_num > enc){
      enc = m1.encorder();
      delay(10);

      //nh.spinOnce();
      //m1.setSpeed(0);
  
      
      
    }
    m1.setSpeed(0);
    delay(delay_time);
    m1.setSpeed(mt_speed);
    while(enc>0){
      enc = m1.encorder();
      delay(10);
      //nh.spinOnce();
    }

     m1.setSpeed(0);*/
  }
  else if (cmd == -1){
    m1.setSpeed(mt_speed);
    
  }
  else{
    
      m1.setSpeed(0);
    
    
    }
 

  
}

ros::Subscriber<std_msgs::Int16MultiArray>sub("try_topic",task_cb);
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  nh.initNode();
  nh.subscribe(sub);
  m1.setSpeed(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
  nh.spinOnce();

 
  
}
