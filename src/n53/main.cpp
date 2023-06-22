#include <istream>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int count = 0;
    for (int num : nums) {
      if (num == target) {
        count++;
      } else if (count > 0) {
        break;
      }
    }
    return count;
  }

  int missingNumber(vector<int>& nums) {
    int flag = 0;
    for (int num : nums) {
      if (num != flag) {
        return flag;
      }
      flag++;
    }
    return flag;
  }
};