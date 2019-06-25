#include "ros/ros.h"
#include "geometry_msgs/Pose2D.h"                          // to get desired position command
#include "turtlesim/Pose.h"                                // to read current position
#include "geometry_msgs/Twist.h"	                   // to send velocity command

// Function declarations
void ComPoseCallback(const geometry_msgs::Pose2D::ConstPtr& msg);
void CurPoseCallback(const turtlesim::Pose::ConstPtr& msg);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "TurtlesimPositionController_pubsub"); // connect to roscore
	ros::NodeHandle n;                                     // node object
	
	// register sub to get current position/pose
	ros::Subscriber CurPose_sub = n.subscribe("/turtle1/pose", 5, CurPoseCallback);
	// register pub to send twist velocity (cmd_vel)
	ros::Publisher Twist_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);

	ros::spin();
}

// call back to send new current Pose msgs
void CurPoseCallback(const turtlesim::Pose::ConstPtr& msg)			
{
	ROS_INFO("Received Pose msg");
	return;
}