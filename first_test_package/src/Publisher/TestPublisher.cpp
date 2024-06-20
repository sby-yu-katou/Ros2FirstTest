#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "first_test_messages/msg/point.hpp"

#include "Worker.hpp"

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
        _publisher = this->create_publisher<first_test_messages::msg::Point>("topic", 10);
        _timer = this->create_wall_timer(500ms, std::bind(&TestPublisher::TimerCallback, this));
      }

    private:
      /**
        * @brief タイマーによる周期的なコールバック処理をおこないます。
      **/
      void TimerCallback()
      {
        first_test_messages::msg::Point pt = _worker.GetCurrentPoint();
        RCLCPP_INFO(this->get_logger(), "Pulbishing: (%ld, %ld, %ld)", pt.x, pt.y, pt.z);
        _publisher->publish(pt);

        _worker.Move();
      }

      /**
      * @brief 周期的な処理を行うためのタイマー
      **/
      rclcpp::TimerBase::SharedPtr _timer;

      /**
      * @brief トピック通信を送信するためのノード
      **/
      rclcpp::Publisher<first_test_messages::msg::Point>::SharedPtr _publisher;

      /**
      * @brief デモ用の仕事人
      **/
      Worker _worker;
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
