/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 *
 *  *** Note: This core requires a bit big transmit buffer.                 ***
 *  ***       You have to enlarge the buffer in STM32FHardware.h like this. ***
 *  ***       l.55   const static uint16_t tbuflen = 512;                   ***
 */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_conf.h"
#include <mainpp.h>
#include <ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Int64.h>
#include <chjk/unit_cmd.h>


ros::NodeHandle nh;

std_msgs::Float64MultiArray enc;

extern double now_deg,now_vel;
extern double P1,I1,D1,pre_error1;
extern double P2,I2,D2,pre_error2;
int pwm_cmd;
double cmd_vel,cmd_deg;

void callback(const std_msgs::Int64& msg);

void get_cmd(const chjk::unit_cmd& cmd);

ros::Subscriber<std_msgs::Int64> sub("pwm", &callback);
ros::Subscriber<chjk::unit_cmd> sub_cmd("left_rear", &get_cmd);

ros::Publisher enc_pub("enc_left_rear", &enc);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}


void setup(void)
{
  enc.data_length = 2;
  enc.data = (double*)malloc(sizeof(double)*2);
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(sub_cmd);
  nh.advertise(enc_pub);


}

void loop(void)
{
  nh.spinOnce();
  enc.data[0] = now_deg;
  enc.data[1] = now_vel;
  enc_pub.publish(&enc);
  HAL_Delay(10);
}

void callback(const std_msgs::Int64& msg){
    pwm_cmd = msg.data;

}

void get_cmd(const chjk::unit_cmd& cmd){
    cmd_deg = cmd.deg;
    cmd_vel = cmd.vel;
    P1=0;
    I1=0;
    D1=0;
    pre_error1=0;

    P2=0;
    I2=0;
    D2=0;
    pre_error2=0;
}



