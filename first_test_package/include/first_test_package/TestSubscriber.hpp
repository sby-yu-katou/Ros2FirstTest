#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class TestSubscriber : public rclcpp::Node
{
  public:
    TestSubscriber();

  private:
    void TopicCallback(const std_msgs::msg::String &msg) const;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscription;
};
