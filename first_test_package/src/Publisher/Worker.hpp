#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

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
       * @brief カウンタインクリメントをおこないます。
      **/
      void IncrementCount();

      /**
       * @brief カウンタの現在値を取得します。
       * @return size_t 現在値を返します。
      **/
      size_t GetCount();

    private:
      /**
       * @brief デモ用のカウンタ
      **/
      size_t _count;
  };
}
