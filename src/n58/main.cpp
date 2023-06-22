#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    if (n >= s.size() || n <= 0) {
      return s;
    }
    char* str = (char*)s.c_str();
    std::string ret = &str[n];
    str[n] = '\0';
    ret += str;
    return ret;
  }
};