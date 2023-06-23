#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    std::set<int> tmp;
    vector<int>::iterator iter = nums.begin();
    for (; iter != nums.end(); iter++) {
      if (tmp.find(*iter) != tmp.end()) {
        return *iter;
      }
      tmp.insert(*iter);
    }
    return 0;
  }
};

int main(int argc, char* argv[]) { return 0; }