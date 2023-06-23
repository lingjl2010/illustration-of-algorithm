#include <iostream>
using namespace std;

class Solution {
 public:
  char firstUniqChar(string s) {
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      bool duplicate = false;
      for (int j = 0; j < s.size(); j++) {
        if (i == j) continue;
        char v = s[j];
        if (c == v) {
          duplicate = true;
          break;
        }
      }

      if (!duplicate) {
        return c;
      }
    }
    return ' ';
  }
};

int main(int argc, char* argv[]) { return 0; }