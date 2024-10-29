#include <ros/ros.h>
#include <rosbag/bag.h>
#include <ros/package.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "bag_write");

    std::string packagePath = ros::package::getPath("rosbag_learning");
    std::string bagsPath = packagePath + "/bags";

    ros::NodeHandle nh;
    // 创建bag对象
    rosbag::Bag bag;
    // 打开文件
    bag.open(bagsPath+"/test.bag", rosbag::BagMode::Write);
    // 写文件
    std_msgs::String msg;
    msg.data = "hello world";
    // 写入4帧
    for (size_t i = 0; i < 4; i++)
    {
        bag.write("/chatter", ros::Time::now(), msg);
    }
    // 关闭文件
    bag.close();

    return 0;
}
