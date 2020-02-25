#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <chjk/vw_cmd.h>
#include <geometry_msgs/Pose2D.h>
#include <math.h>
#include <sstream>




double r;
double now_theta;//現在の姿勢
double v_dir;
double target_v[2],target_w;//目標速度
double local_v[2];//local座標系での指令ベクトル




ros::Subscriber cmd_recv,pose_recv;


ros::Publisher	left_front_pub,
		right_front_pub,
		back_pub;


std_msgs::Float64 left_front,right_front,back;


void get_pose(const geometry_msgs::Pose2D::ConstPtr& pose){

	
	now_theta = pose->theta;


}


void get_vw(const chjk::vw_cmd::ConstPtr& msg){




	target_v[0] = msg->vx;
	target_v[1] = msg->vy;
	target_w = msg->w;




	right_front.data = target_v[0]/2 - sqrt(3)/2 * target_v[1] + r * target_w;
	left_front.data = target_v[0]/2 + sqrt(3)/2 * target_v[1] + r * target_w;
	back.data = -target_v[0] + r * target_w;





	left_front_pub.publish(left_front);
	right_front_pub.publish(right_front);
	back_pub.publish(back);

}

int main(int argc,char **argv){
	ros::init(argc,argv,"omni");
	ros::NodeHandle nh;

	nh.getParam("omni_node/r", r);
	pose_recv = nh.subscribe("pose",1,get_pose);
	cmd_recv = nh.subscribe("cmd",1,get_vw);
	left_front_pub = nh.advertise<std_msgs::Float64>("left_front",1);
	right_front_pub = nh.advertise<std_msgs::Float64>("right_front",1);
	back_pub = nh.advertise<std_msgs::Float64>("back",1);

	ros::spin();
	return 0;
}





