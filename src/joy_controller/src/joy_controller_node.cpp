#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>
#include <chjk/vw_cmd.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Int16.h>
#include <math.h>
#include <sstream>

double MAX_VEL,MAX_ANGULAR_VEL;

int SPD_TRY;

ros::Subscriber joy_sub;
ros::Publisher	cmd_pub;
ros::Publisher try_pub;

struct Joystick
{
	float linear_x;
	float linear_y;
	float w;
};

Joystick Joystick;
chjk::vw_cmd cmd;

void get_joy(const sensor_msgs::Joy& joy){

	double x = -joy.axes[0];
	double y = joy.axes[1];

	std_msgs::Int16 trying;

	double v_dir = atan2(y,x);

	cmd.vy = MAX_VEL*sin(v_dir);
	cmd.vx = MAX_VEL*cos(v_dir);

  	cmd.w = MAX_ANGULAR_VEL*joy.axes[2];//右スティックの左右
	if(abs(cmd.w)>MAX_ANGULAR_VEL){
		if(cmd.w>0) cmd.w = MAX_ANGULAR_VEL;
		else cmd.w = -MAX_ANGULAR_VEL;
	}

	if(x == 0 && y == 0){
		cmd.vy = 0;
		cmd.vx = 0;
	}

	//トライ
	trying.data = SPD_TRY*joy.axes[5];

	cmd_pub.publish(cmd);
	try_pub.publish(trying);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "joy");

	ros::NodeHandle n;
	
	n.getParam("joy_controller/MAX_VEL",MAX_VEL);
	n.getParam("joy_controller/MAX_ANGULAR_VEL",MAX_ANGULAR_VEL);
	n.getParam("joy_controller/SPD_TRY",SPD_TRY);

	joy_sub = n.subscribe("joy", 1, get_joy);
	
	cmd_pub = n.advertise<chjk::vw_cmd>("cmd",1);
	try_pub = n.advertise<std_msgs::Int16>("try_topic",1);

	ros::Rate r(10.0);

	while(n.ok()){

		ros::spinOnce();

		r.sleep();
	}
}





