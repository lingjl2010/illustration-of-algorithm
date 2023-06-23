#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  // 广度优先算法
  vector<int> levelOrder1(TreeNode *root) {
    vector<int> result;
    if (root == NULL) {
      return result;
    }
    result.emplace_back(root->val);

    list<TreeNode *> tmp;
    tmp.emplace_back(root);
    while (tmp.size()) {
      TreeNode *node = tmp.front();
      tmp.pop_front();
      if (node->left != NULL) {
        result.emplace_back(node->left->val);
        tmp.push_back(node->left);
      }
      if (node->right != NULL) {
        result.emplace_back(node->right->val);
        tmp.push_back(node->right);
      }
    }
    return result;
  }

  // 广度优先算法
  vector<vector<int>> levelOrder2(TreeNode *root) {
    vector<vector<int>> results;
    if (root == NULL) {
      return results;
    }

    vector<int> result;
    result.emplace_back(root->val);
    results.emplace_back(result);

    list<TreeNode *> tmp;
    tmp.emplace_back(root);
    while (true) {
      vector<int> result;
      list<TreeNode *> tmp2;
      for (auto node : tmp) {
        if (node->left != NULL) {
          result.emplace_back(node->left->val);
          tmp2.push_back(node->left);
        }
        if (node->right != NULL) {
          result.emplace_back(node->right->val);
          tmp2.push_back(node->right);
        }
      }
      tmp = tmp2;
      if (result.size() > 0) {
        results.emplace_back(result);
      }
      if (tmp2.size() == 0) {
        break;
      }
    }
    return results;
  }

  // 广度优先算法
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> results;
    if (root == NULL) {
      return results;
    }

    vector<int> result;
    result.emplace_back(root->val);
    results.emplace_back(result);

    list<TreeNode *> tmp;
    tmp.emplace_back(root);
    int i = 1;
    while (true) {
      i++;
      vector<int> result;
      list<TreeNode *> tmp2;
      if (i % 2 != 0) {
        for (auto node : tmp) {
          if (node->left != NULL) {
            result.emplace_back(node->left->val);
          }
          if (node->right != NULL) {
            result.emplace_back(node->right->val);
          }
          if (node->left != NULL) {
            tmp2.push_front(node->left);
          }
          if (node->right != NULL) {
            tmp2.push_front(node->right);
          }
        }
      } else {
        for (auto node : tmp) {
          if ((node)->right != NULL) {
            result.emplace_back((node)->right->val);
          }
          if ((node)->left != NULL) {
            result.emplace_back((node)->left->val);
          }
          if ((node)->right != NULL) {
            tmp2.push_front((node)->right);
          }
          if ((node)->left != NULL) {
            tmp2.push_front((node)->left);
          }
        }
      }
      tmp = tmp2;
      if (result.size() > 0) {
        results.emplace_back(result);
      }
      if (tmp2.size() == 0) {
        break;
      }
    }
    return results;
  }
};

int main(int argc, char *argv[]) { return 0; }