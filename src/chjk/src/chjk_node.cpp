#include <ros/ros.h>
#include <chjk/unit_cmd.h>
#include <chjk/vw_cmd.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <std_msgs/Float64.h>
#include <math.h>
#include <sstream>




double alpha,r;
double now_theta;//現在の姿勢
double v_dir;
double target_v[2],target_w;//目標速度
double local_v[2];//local座標系での指令ベクトル




ros::Subscriber cmd_recv,pose_recv;


ros::Publisher	left_front_pub,
		left_rear_pub,
		right_front_pub,
		right_rear_pub;


chjk::unit_cmd left_front,left_rear,right_front,right_rear;


void rotation(double *new_v,double *pre_v,double theta);

void get_pose(const geometry_msgs::Twist::ConstPtr& pose){

	
	now_theta = pose->angular.z;


}


void get_vw(const geometry_msgs::Twist::ConstPtr& msg){




	target_v[0] = msg->linear.x;
	target_v[1] = msg->linear.y;
	target_w = msg->angular.z;



	rotation(local_v,target_v,-now_theta);//速度指令をlocal座標変換

	

	if(!(target_v[0] == 0 && target_v[1] == 0 && target_w == 0) ){

		right_front.deg = (atan2(local_v[1] + target_w*r*cos(alpha),local_v[0] - target_w*r*sin(alpha)))/M_PI*180;		
		left_front.deg = (atan2(local_v[1] - target_w*r*cos(alpha),local_v[0] - target_w*r*sin(alpha)))/M_PI*180;
		left_rear.deg = (atan2(local_v[1] - target_w*r*cos(alpha),local_v[0] + target_w*r*sin(alpha)))/M_PI*180;
		right_rear.deg = (atan2(local_v[1] + target_w*r*cos(alpha),local_v[0] + target_w*r*sin(alpha)))/M_PI*180;
	}

	right_front.vel = hypotf(local_v[1] + target_w*r*cos(alpha),local_v[0] - target_w*r*sin(alpha));
	left_front.vel = hypotf(local_v[1] - target_w*r*cos(alpha),local_v[0] - target_w*r*sin(alpha));
	left_rear.vel = hypotf(local_v[1] - target_w*r*cos(alpha),local_v[0] + target_w*r*sin(alpha));
	right_rear.vel = hypotf(local_v[1] + target_w*r*cos(alpha),local_v[0] + target_w*r*sin(alpha));

	if(right_front.deg<0){
		right_front.deg = right_front.deg + 180;
		right_front.vel = -right_front.vel;
	}
	if(left_front.deg<0){
		left_front.deg = left_front.deg + 180;
		left_front.vel = -left_front.vel;
	}
	if(left_rear.deg<0){
		left_rear.deg = left_rear.deg + 180;
		left_rear.vel = -left_rear.vel;
	}
	if(right_rear.deg<0){
		right_rear.deg = right_rear.deg + 180;
		right_rear.vel = -right_rear.vel;
	}





	left_front_pub.publish(left_front);
	left_rear_pub.publish(left_rear);
	right_rear_pub.publish(right_rear);
	right_front_pub.publish(right_front);

}

int main(int argc,char **argv){
	ros::init(argc,argv,"chojyuku");
	ros::NodeHandle nh;
	ros::Rate loop_rate(100);

	nh.getParam("chjk_node/alpha", alpha);
	alpha = alpha /180 *M_PI;
	nh.getParam("chjk_node/r", r);
	pose_recv = nh.subscribe("spe",1,get_pose);
	cmd_recv = nh.subscribe("cmd",1,get_vw);
	left_front_pub = nh.advertise<chjk::unit_cmd>("left_front",1);
	left_rear_pub = nh.advertise<chjk::unit_cmd>("left_rear",1);
	right_front_pub = nh.advertise<chjk::unit_cmd>("right_front",1);
	right_rear_pub = nh.advertise<chjk::unit_cmd>("right_rear",1);

	while (ros::ok())
	{
		ros::spinOnce();
		loop_rate.sleep();

	}
	return 0;
}

void rotation(double *new_v,double *pre_v,double theta){

	new_v[0] = pre_v[0]*cos(theta) -pre_v[1]*sin(theta); 

	new_v[1] = pre_v[0]*sin(theta) +pre_v[1]*cos(theta);

}

void add(double *new_v,double *pre_v1,double *pre_v2){

	new_v[0] = pre_v1[0] + pre_v2[0]; 

	new_v[1] = pre_v1[1] + pre_v2[1]; 

}

void cross_product(double *a, double *b, double *c)
{

	c[0] = a[1]*b[2] - a[2]*b[1];
	c[1] = a[2]*b[0] - a[0]*b[2];
	c[2] = a[0]*b[1] - a[1]*b[0];
  
}




