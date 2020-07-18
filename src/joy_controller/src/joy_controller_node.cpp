#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/Int64.h>
#include <math.h>
#include <sstream>

#define MIN_VEL 0.1

double MAX_VEL,MAX_ANGULAR_VEL,DELAY_TIME;

int ENC_NUM,TRY_SPEED;

ros::Subscriber joy_sub;
ros::Publisher cmd_pub;
ros::Publisher try_pub;
ros::Publisher standby_pub;

struct Joystick
{
	float linear_x;
	float linear_y;
	float w;
};

Joystick Joystick;
geometry_msgs::Twist cmd;
std_msgs::Int64 standby_state;
std_msgs::Int16MultiArray try_num;

void get_joy(const sensor_msgs::Joy& joy){

	double x = joy.axes[0];
	double y = joy.axes[1];


	double v_dir = atan2(y,x);

	cmd.linear.x = MAX_VEL*sin(v_dir);
	cmd.linear.y = MAX_VEL*cos(v_dir);


  	cmd.angular.z = MAX_ANGULAR_VEL*joy.axes[2];//右スティックの左右
	if(abs(joy.axes[2]) < 1) cmd.angular.z = 0;
	if(abs(cmd.angular.z)>MAX_ANGULAR_VEL){
		if(cmd.angular.z>0) cmd.angular.z = MAX_ANGULAR_VEL;
		else cmd.angular.z = -MAX_ANGULAR_VEL;
	}

	if(x == 0 && y == 0){
		cmd.linear.x = 0;
		cmd.linear.y = 0;
	}
	if(hypotf(x,y)<1){
		cmd.linear.x = 0;
		cmd.linear.y = 0;
	}

	//トライ
	try_num.data.resize(4);
	try_num.data[0] = joy.axes[5];
	try_num.data[1] = ENC_NUM;
	try_num.data[2] = TRY_SPEED;
	try_num.data[3] = DELAY_TIME;

	if(joy.buttons[8]){

		standby_state.data = -standby_state.data;



	}

	



	cmd_pub.publish(cmd);
	standby_pub.publish(standby_state);
	try_pub.publish(try_num);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "joy");

	ros::NodeHandle n;
	
	n.getParam("joy_controller/MAX_VEL",MAX_VEL);
	n.getParam("joy_controller/MAX_ANGULAR_VEL",MAX_ANGULAR_VEL);
	n.getParam("joy_controller/ENC_NUM",ENC_NUM);
	n.getParam("joy_controller/TRY_SPEED",TRY_SPEED);
	n.getParam("joy_controller/DELAY_TIME",DELAY_TIME);


	joy_sub = n.subscribe("joy", 1, get_joy);
	
	cmd_pub = n.advertise<geometry_msgs::Twist>("cmd",1);
	try_pub = n.advertise<std_msgs::Int16MultiArray>("try_topic",1);
	standby_pub = n.advertise<std_msgs::Int64>("standby",1);

	cmd.linear.x = 0;
	cmd.linear.y = 0;
	cmd.angular.z = 0;

	standby_state.data = 1;

	ros::Rate r(10.0);

	while(n.ok()){

		ros::spinOnce();

		r.sleep();
	}
}





