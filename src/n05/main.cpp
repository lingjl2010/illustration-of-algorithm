#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    std::vector<int> offsets;
    for (int ii = 0; ii < s.length(); ii++) {
      if (s[ii] == ' ') {
        offsets.emplace_back(ii);
      }
    }

    char* src = (char*)s.c_str();
    std::string result;
    int preOffset = 0;
    for (int ii = 0; ii < offsets.size(); ii++) {
      int offset = offsets[ii];
      src[offset] = '\0';
      result += &src[preOffset];
      result += "%20";
      preOffset = offset + 1;
    }
    result += &src[preOffset];
    return result;
  }
};