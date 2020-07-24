#include "segmatch/descriptors/cnn_ros_publisher.hpp"

namespace segmatch {

CNNPublisher::CNNPublisher(ros::NodeHandle& nh) : nh_(nh) {
  publisher_ = nh_.advertise<segmatch::tensorflow_msg>("tensorflow_interface", 50u);
}

void CNNPublisher::sendMessage(std::string s) {
  segmatch::tensorflow_msg msg;
  msg.data = s;
  msg.timestamp = ros::Time::now().toNSec();
  publisher_.publish(msg);
}

}  // namespace segmatch