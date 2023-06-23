#include <iostream>
#include <stack>

/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和
deleteHead
，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回
-1 )

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/5d3i87/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

class CQueue {
 public:
  CQueue() : preOpt(0) {}

  void appendTail(int value) {
    if (preOpt == 1) {
      while (b.size() != 0) {
        a.emplace(b.top());
        b.pop();
      }
    }
    preOpt = 0;
    a.push(value);
  }

  int deleteHead() {
    if (preOpt == 0) {
      while (a.size() != 0) {
        b.emplace(a.top());
        a.pop();
      }
    }
    preOpt = 1;
    if (b.size() == 0) {
      return -1;
    }

    int ret = b.top();
    b.pop();
    return ret;
  }

 private:
  std::stack<int> a;
  std::stack<int> b;
  int preOpt;  // 0: appendTail, 1: deleteHead
};

int main(int argc, char* argv[]) {
  CQueue queue;
  queue.appendTail(3);
  int a1 = queue.deleteHead();
  a1 = queue.deleteHead();
  a1 = queue.deleteHead();
  return 0;
}
