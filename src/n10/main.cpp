#include <iostream>
using namespace std;
class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
      int sum = (a + b) % 1000000007;
      a = b;
      b = sum;
    }
    return a;
  }
};

int main(int argc, char* argv[]) {
  int r = Solution().fib(45);
  return 0;
}