#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32                                              #importing packages


pub = rospy.Publisher('battery_warning_light', Int32, queue_size =1)        #publishing to a channel
value=0

def callback(msg):
    global value 
    value = msg.data
    print value
   

def listener():
   rospy.init_node('topic_subscriber')                                       #initialisation of a subscriber
   sub = rospy.Subscriber('battery_level', Int32, callback)
   rate = rospy.Rate(1)

   
   c=0   
   while not rospy.is_shutdown():
      count = 1
      c +=1
      if value<=33:
         if c%2!=0:
             count=1
             pub.publish(count)
         else:
             count = 0
             pub.publish(count)
      if value>33:
             pub.publish(count)
  
      rate.sleep()

    if __name__=='__main__':
    listener()
