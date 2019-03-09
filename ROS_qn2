#include "ros/ros.h"                                  //header files for ROS and C++
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  
     ros::init(argc, argv, "talker");                 //mentioning the node as talker
   
  
     ros::NodeHandle n;
  
     ros::Publisher message = n.advertise<std_msgs::String>("random_messages", 1000); //initialisation for pubishing to master node
  
     ros::Rate loop_rate(10);                        //rate of publishing the code
 
    
     while (ros::ok())
     {
 
      std_msgs::String msg;                          //initialisation of string
   
      std::stringstream ss;
      ss << "Hello World " ;
      msg.data = ss.str();
   
      ROS_INFO("%s", msg.data.c_str());
   
  
      message.publish(msg);                         //sending the message
  
      ros::spinOnce();
  
      loop_rate.sleep();
      
     }
 
 
    return 0;
 }
