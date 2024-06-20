#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

/**
 * @brief テスト用のサブスクライバーを表します。
**/
class TestSubscriber : public rclcpp::Node
{
  public:
    /**
     * @brief 新しいインスタンスを生成します。
    **/
    TestSubscriber();

  private:
    /**
    * @brief トピック通信を受信したときのコールバック処理です。
    * @param msg 受信したメッセージを表します。
    **/
    void TopicCallback(const std_msgs::msg::String &msg) const;

    /**
     * @brief トピック通信を受信するためのノード
    **/
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscription;
};
