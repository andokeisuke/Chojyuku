#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Pose2D.h>


int main(int argc, char** argv){

	ros::init(argc, argv, "my_tf_listener");

	ros::NodeHandle n;

	ros::Publisher pose_pub =n.advertise<geometry_msgs::Twist>("/pose", 1);

	tf::TransformListener tf_listener;
	geometry_msgs::Pose2D pose;

	ros::Rate rate(10.0);

	while (n.ok()){

		try{
			tf::StampedTransform trans;
			tf_listener.waitForTransform("map", "base_link",ros::Time(0), ros::Duration(0.5));
			tf_listener.lookupTransform("map", "base_link", ros::Time(0), trans);
			pose.x = trans.getOrigin().x();
			pose.y = trans.getOrigin().y();
			pose.theta = tf::getYaw(trans.getRotation())/M_PI*180;
		}
		catch(tf::TransformException &e){
			ROS_WARN("%s", e.what());
		}

		pose_pub.publish(pose);
  
  	}
  	return 0;
}


