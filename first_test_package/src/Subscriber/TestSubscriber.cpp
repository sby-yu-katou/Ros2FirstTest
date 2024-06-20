#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

namespace FirstTestPackage::Subscriber
{
  /**
  * @brief テスト用のサブスクライバーを表します。
  **/
  class TestSubscriber : public rclcpp::Node
  {
    public:
      /**
      * @brief 新しいインスタンスを生成します。
      **/
      TestSubscriber()
        : Node("test_subscriber")
      {
        _subscription = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&TestSubscriber::TopicCallback, this, _1));
      }

    private:
      /**
      * @brief トピック通信を受信したときのコールバック処理です。
      * @param msg 受信したメッセージを表します。
      **/
      void TopicCallback(const std_msgs::msg::String &msg) const
      {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
      }

      /**
      * @brief トピック通信を受信するためのノード
      **/
      rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscription;
  };
}

/**
 * @brief TestSubscriber としてのエントリーポイントです。
 * @param argc コマンドライン入力引数の数を表します。
 * @param argv コマンドライン入力引数を表します。
 * @return int 終了コードを返します。正常な場合は 0 を返します。
**/
int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FirstTestPackage::Subscriber::TestSubscriber>());
  rclcpp::shutdown();

  return 0;
}
