#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "first_test_messages/msg/point.hpp"

#include "Worker1.hpp"
#include "Worker2.hpp"

using namespace std::chrono_literals;

namespace FirstTestPackage::Publisher
{
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
      TestPublisher()
        : Node("test_publisher")
      {
        _publisher1 = this->create_publisher<first_test_messages::msg::Point>("topic1", 10);
        _publisher2 = this->create_publisher<first_test_messages::msg::Point>("topic2", 10);

        _timer1 = this->create_wall_timer(500ms, std::bind(&TestPublisher::Timer1Callback, this));
        _timer2 = this->create_wall_timer(1200ms, std::bind(&TestPublisher::Timer2Callback, this));
      }

    private:
      /**
        * @brief タイマー 1 による周期的なコールバック処理をおこないます。
      **/
      void Timer1Callback()
      {
        first_test_messages::msg::Point pt1 = _worker1.GetCurrentPoint();
        RCLCPP_INFO(this->get_logger(), "Pulbishing: (%ld, %ld, %ld)", pt1.x, pt1.y, pt1.z);
        _publisher1->publish(pt1);

        _worker1.Move();
      }

      /**
        * @brief タイマー 2 による周期的なコールバック処理をおこないます。
      **/
      void Timer2Callback()
      {
        first_test_messages::msg::Point pt2 = _worker2.GetCurrentPoint();
        RCLCPP_INFO(this->get_logger(), "Pulbishing: (%ld, %ld, %ld)", pt2.x, pt2.y, pt2.z);
        _publisher2->publish(pt2);

        _worker2.Move();
      }

      /**
      * @brief 周期的な処理を行うためのタイマー 1
      **/
      rclcpp::TimerBase::SharedPtr _timer1;

      /**
      * @brief 周期的な処理を行うためのタイマー 2
      **/
      rclcpp::TimerBase::SharedPtr _timer2;

      /**
      * @brief トピック通信を送信するためのノード
      **/
      rclcpp::Publisher<first_test_messages::msg::Point>::SharedPtr _publisher1;
      rclcpp::Publisher<first_test_messages::msg::Point>::SharedPtr _publisher2;

      /**
      * @brief デモ用の仕事人
      **/
      Worker1 _worker1;
      Worker2 _worker2;
  };
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
  rclcpp::spin(std::make_shared<FirstTestPackage::Publisher::TestPublisher>());
  rclcpp::shutdown();

  return 0;
}
