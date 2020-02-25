//publishだけする
#include"ros/ros.h"
#include"std_msgs/Float64.h"
#include<sstream>

int main(int argc,char **argv){

	ros::init(argc,argv,"gyro_pub2");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise <std_msgs::Float64>("target_posture",1000);

	ros::Rate loop_rate(5);
	while(ros::ok()){
		std_msgs::Float64 msg;
		msg.data = 0;
		pub.publish(msg);

		ros::spinOnce;
		loop_rate.sleep();
	}
	return 0;

}
