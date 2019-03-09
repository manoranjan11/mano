#!/usr/bin/env python
import rospy                                   #for ROS packages
from std_msgs.msg import String
def callback(msg):                            
   print msg.data
rospy.init_node('topic_subscriber')            #initialisation for subscription
sub = rospy.Subscriber('random_messages', String, callback)  //Telling the channel to master node
rospy.spin()
