#include "TestPublisher.hpp"

TestPublisher::TestPublisher()
  : Node("test_publisher")
    , _count(0)
{
  _publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);
  _timer = this->create_wall_timer(500ms, std::bind(&TestPublisher::TimerCallback, this));
}

void TestPublisher::TimerCallback()
{
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(_count++);
  RCLCPP_INFO(this->get_logger(), "Pulbishing: '%s'", message.data.c_str());
  _publisher->publish(message);
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestPublisher>());
  rclcpp::shutdown();

  return 0;
}