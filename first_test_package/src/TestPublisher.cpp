#include "TestPublisher.hpp"

/**
  * @brief 新しいインスタンスを生成します。
**/
TestPublisher::TestPublisher()
  : Node("test_publisher")
    , _count(0)
{
  _publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);
  _timer = this->create_wall_timer(500ms, std::bind(&TestPublisher::TimerCallback, this));
}

/**
  * @brief タイマーによる周期的なコールバック処理をおこないます。
**/
void TestPublisher::TimerCallback()
{
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(_count++);
  RCLCPP_INFO(this->get_logger(), "Pulbishing: '%s'", message.data.c_str());
  _publisher->publish(message);
}

/**
 * @brief TestPublisher としてのエントリーポイントです。
 * @param argc コマンドライン入力引数の数を表します。
 * @param argv コマンドライン入力引数を表します。
 * @return int 終了コードを返します。正常な場合は 0 を返します。
**/
int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestPublisher>());
  rclcpp::shutdown();

  return 0;
}