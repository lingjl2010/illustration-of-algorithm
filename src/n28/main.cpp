#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    TreeNode *newTree;
    clone(root, &newTree);
    reverse(newTree);
    return equal(root, newTree);
  }

  // 二叉树复制
  void clone(TreeNode *root, TreeNode **NewRoot) {
    if (!root) {
      return;
    }

    *NewRoot = new TreeNode(root->val);
    clone(root->left, &(*NewRoot)->left);
    clone(root->right, &(*NewRoot)->right);
  }

  // 二叉树镜像
  void reverse(TreeNode *node) {
    if (!node) {
      return;
    }

    auto tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    reverse(node->left);
    reverse(node->right);
  }

  // 二叉树比较
  bool equal(TreeNode *tn1, TreeNode *tn2) {
    if (!tn1 && !tn2) return true;
    if ((tn1 && !tn2) || (tn2 && !tn1)) return false;
    if (tn1->val != tn2->val) return false;
    return equal(tn1->left, tn2->left) && equal(tn1->right, tn2->right);
  }
};

int main(int argc, char *argv[]) { return 0; }