#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>
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
geometry_msgs::Twist cmd;

void get_joy(const sensor_msgs::Joy& joy){

	double x = joy.axes[0];
	double y = joy.axes[1];

	std_msgs::Int16 trying;

	double v_dir = atan2(y,x);

	cmd.linear.x = MAX_VEL*sin(v_dir);
	cmd.linear.y = MAX_VEL*cos(v_dir);

  	cmd.angular.z = MAX_ANGULAR_VEL*joy.axes[2];//右スティックの左右
	if(abs(cmd.angular.z)>MAX_ANGULAR_VEL){
		if(cmd.angular.z>0) cmd.angular.z = MAX_ANGULAR_VEL;
		else cmd.angular.z = -MAX_ANGULAR_VEL;
	}

	if(x == 0 && y == 0){
		cmd.linear.x = 0;
		cmd.linear.y = 0;
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
	
	cmd_pub = n.advertise<geometry_msgs::Twist>("cmd",1);
	try_pub = n.advertise<std_msgs::Int16>("try_topic",1);

	ros::Rate r(10.0);

	while(n.ok()){

		ros::spinOnce();

		r.sleep();
	}
}





