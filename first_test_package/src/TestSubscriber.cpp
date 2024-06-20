#include "TestSubscriber.hpp"

TestSubscriber::TestSubscriber()
  : Node("test_subscriber")
{
  _subscription = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&TestSubscriber::TopicCallback, this, _1));
}

void TestSubscriber::TopicCallback(const std_msgs::msg::String &msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestSubscriber>());
  rclcpp::shutdown();

  return 0;
}
