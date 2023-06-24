#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      if (nums[left] + nums[right] > target) {
        right--;
      } else if (nums[left] + nums[right] < target) {
        left++;
      } else {
        ret.emplace_back(nums[left]);
        ret.emplace_back(nums[right]);
        return ret;
      }
    }
    return ret;
  }
};