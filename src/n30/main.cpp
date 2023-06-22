#include <iostream>
#include <limits>
#include <stack>

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min
函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
*/

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    int min = x;
    if (b_.size() > 0 && x > b_.top()) min = b_.top();

    b_.emplace(min);
    a_.emplace(x);
  }

  void pop() {
    a_.pop();
    b_.pop();
  }

  int top() { return a_.top(); }

  int min() { return b_.top(); }

 private:
  std::stack<int> a_;
  std::stack<int> b_;
};

int main(int argc, char* argv[]) {
  MinStack s;
  s.push(2147483646);
  s.push(2147483646);
  s.push(2147483647);
  s.top();
  s.pop();
  s.min();
  s.pop();
  s.min();
  s.pop();
  s.push(2147483647);
  s.top();
  s.min();
  s.push(-2147483648);
  s.top();
  s.min();
  s.pop();
  s.min();
  return 0;
}