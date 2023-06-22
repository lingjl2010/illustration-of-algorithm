#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    return doFind2(matrix, target);
  }

  // 递归法
  bool doFind(vector<vector<int>>& matrix, int target, int i, int j) {
    if (i >= matrix.size() || j >= matrix[i].size()) {
      return false;
    }

    if (matrix[i][j] == target) {
      return true;
    }

    else if (matrix[i][j] > target) {
      return doFind(matrix, target, i, j + 1) ||
             doFind(matrix, target, i + 1, j);
    }
    return false;
  }

  // 迭代法
  bool doFind2(vector<vector<int>>& matrix, int target) {
    for (auto m : matrix) {
      for (auto n : m) {
        if (n == target) {
          return true;
        } else if (n > target) {
          break;
        }
      }
    }

    return false;
  }

  // 技巧法
  // 从左下角开始
  // 每行从左往后，元素比target小，则右移动， 元素比target大，则上移一行
  bool doFind3(vector<vector<int>>& matrix, int target) {
    int i = matrix.size() - 1, j = 0;
    while (i >= 0 && j < matrix[0].size()) {
      if (matrix[i][j] > target)
        i--;
      else if (matrix[i][j] < target)
        j++;
      else
        return true;
    }
    return false;
  }
};