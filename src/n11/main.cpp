#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  // 思路：第一个出现变小趋势的值，肯定是最小值
  int minArray(vector<int>& numbers) {
    if (numbers.size() == 0) {
      return 0;
    } else if (numbers.size() == 1) {
      return numbers[0];
    }

    int flag = numbers[0];
    for (int ii = 1; ii < numbers.size(); ii++) {
      if (numbers[ii] < flag) {
        flag = numbers[ii];
        break;
      }
    }

    return flag;
  }
};