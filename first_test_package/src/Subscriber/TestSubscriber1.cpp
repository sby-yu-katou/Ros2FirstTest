#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "first_test_messages/msg/point.hpp"

using std::placeholders::_1;

namespace FirstTestPackage::Subscriber
{
  /**
  * @brief テスト用のサブスクライバーを表します。
  **/
  class TestSubscriber1 : public rclcpp::Node
  {
    public:
      /**
      * @brief 新しいインスタンスを生成します。
      **/
      TestSubscriber1()
        : Node("test_subscriber1")
      {
        _subscription = this->create_subscription<first_test_messages::msg::Point>("topic1", 10, std::bind(&TestSubscriber1::TopicCallback, this, _1));
      }

    private:
      /**
      * @brief トピック通信を受信したときのコールバック処理です。
      * @param msg 受信したメッセージを表します。
      **/
      void TopicCallback(const first_test_messages::msg::Point &pt) const
      {
        RCLCPP_INFO(this->get_logger(), "I heard: (%ld, %ld, %ld)", pt.x, pt.y, pt.z);
      }

      /**
      * @brief トピック通信を受信するためのノード
      **/
      rclcpp::Subscription<first_test_messages::msg::Point>::SharedPtr _subscription;
  };
}

/**
 * @brief TestSubscriber1 としてのエントリーポイントです。
 * @param argc コマンドライン入力引数の数を表します。
 * @param argv コマンドライン入力引数を表します。
 * @return int 終了コードを返します。正常な場合は 0 を返します。
**/
int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FirstTestPackage::Subscriber::TestSubscriber1>());
  rclcpp::shutdown();

  return 0;
}
