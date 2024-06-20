#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/**
 * @brief テスト用のパブリッシャーを表します。
 * 
**/
class TestPublisher : public rclcpp::Node
{
  public:
    /**
     * @brief 新しいインスタンスを生成します。
    **/
    TestPublisher();

  private:
    /**
     * @brief タイマーによる周期的なコールバック処理をおこないます。
    **/
    void TimerCallback();

    /**
     * @brief 周期的な処理を行うためのタイマー
    **/
    rclcpp::TimerBase::SharedPtr _timer;

    /**
     * @brief トピック通信を送信するためのノード
    **/
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _publisher;

    /**
     * @brief デモ用のカウンタ
    **/
    size_t _count;
};
