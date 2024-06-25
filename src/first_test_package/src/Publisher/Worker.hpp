#include <iostream>
#include <chrono>

#include "first_test_messages/msg/point.hpp"

using namespace std;
using namespace std::chrono_literals;
using namespace first_test_messages::msg;

namespace FirstTestPackage::Publisher
{
  class Worker
  {
    public:
      /**
       * @brief 新しいインスタンスを生成します。
      **/
      Worker();

      /**
       * @brief 座標を移動します。
      **/
      void Move();

      /**
       * @brief 現在位置を取得します。
       * @return Point 現在位置を返します。
      **/
      Point GetCurrentPoint();

    private:
      /**
       * @brief デモ用の座標
      **/
      Point _pt;
  };
}
