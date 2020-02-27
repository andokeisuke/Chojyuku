#include <ros/ros.h>  // rosで必要はヘッダーファイル
#include <std_msgs/Int64MultiArray.h>
#include <std_msgs/Float64.h>
#include "geometry_msgs/Twist.h" // ロボットを動かすために必要
#include <geometry_msgs/Pose2D.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
#include <iostream>

#define int_memory 30000


double vx,vy,w,v_dir;//速度指令

int theta;//ジャイロからのヨー軸角度

double enc_per_m;//1mあたりのエンコーダの増加量
double predistance_x, predistance_y = 0;
double preenc_x,preenc_y = 0;



double state_odom_x;//オドメトリX座標[m]
double state_odom_y;//オドメトリY座標[m]
double state_odom_th; //オドメトリ姿勢[rad]


void get_vw(const geometry_msgs::Twist::ConstPtr& cmd){
	vx = cmd->linear.x;
	vy = cmd->linear.y;
	w = cmd->angular.z;
}

void get_pose(const std_msgs::Float64::ConstPtr& pose){
	
	state_odom_th = pose->data/180*M_PI;	
		

}

void get_enc(const std_msgs::Int64MultiArray::ConstPtr& enc){

	double enc_x = enc->data[0];
	double distance_x = (enc_x-preenc_x)/enc_per_m;
	double enc_y = enc->data[1];
	double distance_y = -(enc_y-preenc_y)/enc_per_m;


	if(fabs(enc_x-preenc_x)>int_memory){//int型のオーバーフローの例外処理
		distance_x = predistance_x;
		
	}
	if(fabs(enc_y-preenc_y)>int_memory){//int型のオーバーフローの例外処理
		distance_y = predistance_y;
		
	}

			


	
	state_odom_x= state_odom_x + distance_x * cos(state_odom_th) - distance_y * sin(state_odom_th);
	state_odom_y= state_odom_y + distance_x * sin(state_odom_th) + distance_y * cos(state_odom_th);
	
	       

	predistance_x = distance_x;
	predistance_y = distance_y;
	preenc_x = enc->data[0];
	preenc_y = enc->data[1];
 
}





int main(int argc, char **argv){


	ros::init(argc, argv, "odom");
	ros::NodeHandle n;
	n.getParam("/odometry/chjk_odometry/enc_per_m", enc_per_m);

	tf::TransformBroadcaster odom_broadcaster;
	ros::Time current_time;
	current_time = ros::Time::now();

	geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.frame_id = "odom";
	odom_trans.child_frame_id = "base_link";


	ros::Subscriber enc_sub = n.subscribe<std_msgs::Int64MultiArray>("enc", 1, get_enc);
	ros::Subscriber pose_recv = n.subscribe<std_msgs::Float64>("gyro_yaw", 1, get_pose);
	ros::Subscriber cmd_recv = n.subscribe<geometry_msgs::Twist>("cmd", 1, get_vw);
	ros::Publisher pose_pub = n.advertise<geometry_msgs::Pose2D>("odometry",1);

	
	ros::Rate r(40.0);


	while(n.ok()){

		current_time = ros::Time::now();
    		odom_trans.header.stamp = current_time;

		//odometryのtfを作成、発行
    		odom_trans.transform.translation.x = state_odom_x;
    		odom_trans.transform.translation.y = state_odom_y;
    		odom_trans.transform.translation.z = 0.0;
			geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(state_odom_th);
    		odom_trans.transform.rotation = odom_quat;
			geometry_msgs::Pose2D pose;
			pose.x = state_odom_x;
			pose.y = state_odom_y;
			pose.theta = state_odom_th;
			pose_pub.publish(pose);


    		odom_broadcaster.sendTransform(odom_trans);


    		ros::spinOnce();
    		r.sleep();
  	 }
}
