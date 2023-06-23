#include <iostream>
#include <list>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  // 二叉树镜像
  TreeNode* mirrorTree(TreeNode* root) {
    reverse(root);
    return root;
  }

  void reverse(TreeNode* node) {
    if (!node) {
      return;
    }

    auto tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    reverse(node->left);
    reverse(node->right);
  }
};

int main(int argc, char* argv[]) { return 0; }