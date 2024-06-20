#include "Worker.hpp"

namespace FirstTestPackage::Publisher
{
  /**
  * @brief 新しいインスタンスを生成します。
  **/
  Worker::Worker()
  {
    cout << "Worker!" << endl;
    _count = 0;
  }

  /**
  * @brief カウンタインクリメントをおこないます。
  **/
  void Worker::IncrementCount()
  {
    _count++;
  }

  /**
  * @brief カウンタの現在値を取得します。
  * @return size_t 現在値を返します。
  **/
  size_t Worker::GetCount()
  {
    return _count;
  }
}
