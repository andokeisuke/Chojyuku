#include <ros/ros.h>  // rosで必要はヘッダーファイル
#include <std_msgs/Int64.h>
#include <std_msgs/Int16.h>
#include <chjk/vw_cmd.h> // ロボットを動かすために必要
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
#include <iostream>

#define int_memory 30000


double vx,vy,w,v_dir;//速度指令

int theta;//ジャイロからのヨー軸角度

int enc_per_m;//1mあたりのエンコーダの増加量
double predistance;
double preenc;



double state_odom_x;//オドメトリX座標[m]
double state_odom_y;//オドメトリY座標[m]
double state_odom_th; //オドメトリ姿勢[rad]


void get_vw(const chjk::vw_cmd::ConstPtr& cmd){
	vx = cmd->vx;
	vy = cmd->vy;
	w = cmd->w;
}

void get_pose(const std_msgs::Int16::ConstPtr& pose){
	
	state_odom_th = pose->data/180*M_PI;	
		

}

void get_enc(const std_msgs::Int64::ConstPtr& enc){

	double left_rear_enc = enc->data;
	double distance = left_rear_enc/enc_per_m;//右後ろ車輪の移動距離

	if(fabs(enc->data-preenc)>int_memory){//int型のオーバーフローの例外処理
		preenc = enc->data;
		predistance = distance;
		
	}

	v_dir = atan2(vy,vx);		


	if(!((w != 0)&&(vx == 0)&&(vy == 0))){//旋回せず並行移動している時

		state_odom_x= state_odom_x+(distance-predistance)*cos(v_dir);
	     	state_odom_y= state_odom_y+ (distance-predistance)*sin(v_dir);
	}
	       

	predistance  = distance;
	preenc = enc->data;
 
}





int main(int argc, char **argv){


	ros::init(argc, argv, "odom");
	ros::NodeHandle n;
	n.getParam("chjk_odometry/enc_per_m", enc_per_m);

	tf::TransformBroadcaster odom_broadcaster;
	ros::Time current_time;
	current_time = ros::Time::now();

	geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.frame_id = "odom";
	odom_trans.child_frame_id = "base_link";


	ros::Subscriber enc_sub = n.subscribe<std_msgs::Int64>("enc", 1, get_enc);
	ros::Subscriber pose_recv = n.subscribe<std_msgs::Int16>("gyro_pose", 1, get_pose);
	ros::Subscriber cmd_recv = n.subscribe<chjk::vw_cmd>("cmd", 1, get_vw);

	
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


    		odom_broadcaster.sendTransform(odom_trans);


    		ros::spinOnce();
    		r.sleep();
  	 }
}
