#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "std_msgs/Int8.h"
#include <iostream>
using namespace std;

int tablenum;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void tablenumcall(const std_msgs::Int8 msg);

void tablenumcall(const std_msgs::Int8::ConstPtr& msg){
    tablenum = msg->data;
}



int main(int argc, char** argv){
    int x;
    tablenum=-1;
    ros::init(argc, argv, "Navigation");
    ros::NodeHandle n;
    ros::Publisher bringback_pub = n.advertise<std_msgs::Int8>("bringback", 10);
    ros::Subscriber sub_int8 = n.subscribe("bring", 10, tablenumcall);
    ros::start();

    MoveBaseClient ac("move_base", true);
    std_msgs::Int8 bbmsg;

    while(ros::ok()){
        ROS_INFO("Start Navigation");
        printf("%d\n",tablenum);
        //MoveBaseClient ac("move_base", true);
        if(tablenum == 1){ 
            while(!ac.waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
            }
            move_base_msgs::MoveBaseGoal goal;
            goal.target_pose.header.frame_id = "map"; //base_footprint map地图坐标系 base_laser 
            goal.target_pose.header.stamp = ros::Time::now();
            goal.target_pose.pose.position.x = -1.82349491119;
            goal.target_pose.pose.position.y = 0.416509687901;
            goal.target_pose.pose.position.z = 0;
            goal.target_pose.pose.orientation.x = 0.0;
            goal.target_pose.pose.orientation.y = 0.0;
            goal.target_pose.pose.orientation.z = 0.985040672505;
            goal.target_pose.pose.orientation.w = -0.172322005298;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("Hooray, the base moved 1 meter forward");
                bbmsg.data = 1;
                tablenum = -1;
            }
            else{
                ROS_INFO("The base failed to move forward 1 meter for some reason");
                bbmsg.data = 0;
            }
            bringback_pub.publish(bbmsg);
        }
        else if(tablenum == 2){
            while(!ac.waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
            }
            move_base_msgs::MoveBaseGoal goal;
            goal.target_pose.header.frame_id = "map"; //base_footprint map地图坐标系 base_laser 
            goal.target_pose.header.stamp = ros::Time::now();
            goal.target_pose.pose.position.x = -0.804682731628;
            goal.target_pose.pose.position.y = -2.36768269539;
            goal.target_pose.pose.position.z = 0;
            goal.target_pose.pose.orientation.x = 0.0;
            goal.target_pose.pose.orientation.y = 0.0;
            goal.target_pose.pose.orientation.z = 0.990772821876;
            goal.target_pose.pose.orientation.w = -0.135533078735;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("Hooray, the base moved 1 meter forward");
                bbmsg.data = 1;
                tablenum = -1;
            }
            else{
                ROS_INFO("The base failed to move forward 1 meter for some reason");
                bbmsg.data = 0;
            }
            bringback_pub.publish(bbmsg);
        }
        else if(tablenum == 0){
            while(!ac.waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
            }
            move_base_msgs::MoveBaseGoal goal;
            goal.target_pose.header.frame_id = "map"; //base_footprint map地图坐标系 base_laser 
            goal.target_pose.header.stamp = ros::Time::now();
            goal.target_pose.pose.position.x = -0.239704608917;
            goal.target_pose.pose.position.y = -0.251727938652;
            goal.target_pose.pose.position.z = 0;
            goal.target_pose.pose.orientation.x = 0.0;
            goal.target_pose.pose.orientation.y = 0.0;
            goal.target_pose.pose.orientation.z = 0.147069071302;
            goal.target_pose.pose.orientation.w = 0.989126224638;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("Hooray, the base moved 1 meter forward");
                bbmsg.data = 1;
                tablenum = -1;
            }
            else{
                ROS_INFO("The base failed to move forward 1 meter for some reason");
                bbmsg.data = 0;
            }
            bringback_pub.publish(bbmsg);
        }
        else if(tablenum == 3){
            while(!ac.waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
            }
            move_base_msgs::MoveBaseGoal goal;
            goal.target_pose.header.frame_id = "map"; //base_footprint map地图坐标系 base_laser 
            goal.target_pose.header.stamp = ros::Time::now();
            goal.target_pose.pose.position.x = -1.35249888897;
            goal.target_pose.pose.position.y = 1.59389472008;
            goal.target_pose.pose.position.z = 0;
            goal.target_pose.pose.orientation.x = 0.0;
            goal.target_pose.pose.orientation.y = 0.0;
            goal.target_pose.pose.orientation.z = 0.811332499732;
            goal.target_pose.pose.orientation.w = 0.584584959504;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("Hooray, the base moved 1 meter forward");
                bbmsg.data = 1;
                tablenum = -1;
            }
            else{
                ROS_INFO("The base failed to move forward 1 meter for some reason");
                bbmsg.data = 0;
            }
            bringback_pub.publish(bbmsg);
        }
        
        bbmsg.data = 0;
        ros::spinOnce();
    }
    return 0;
}
