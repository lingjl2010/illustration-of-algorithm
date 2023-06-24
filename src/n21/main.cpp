#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    for (int i = 0, j = 0; j < nums.size(); j++) {
      if (nums[j] % 2 != 0) {
        std::swap(nums[i], nums[j]);
        i++;
      }
    }
    return nums;
  }
};