#include "Worker1.hpp"

namespace FirstTestPackage::Publisher
{
  /**
  * @brief 新しいインスタンスを生成します。
  **/
  Worker1::Worker1()
  {
    cout << "Worker1!" << endl;
    _pt.x = 0;
    _pt.y = 0;
    _pt.z = 0;
  }

  /**
  * @brief 座標を移動します。
  **/
  void Worker1::Move()
  {
    _pt.x += 1;
    _pt.y += 2;
    _pt.z += 3;
  }

  /**
  * @brief 現在位置を取得します。
  * @return Point 現在位置を返します。
  **/
  Point Worker1::GetCurrentPoint()
  {
    return _pt;
  }
}
