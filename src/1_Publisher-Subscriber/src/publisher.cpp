#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "publisher");

    ros::NodeHandle nh;

    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("Publisher", 10);

    ros::Rate loop_rate(60);

    while (ros::ok()) {

        std_msgs::String msg;
        msg.data = "Hello World!";
        
        topic_pub.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}
