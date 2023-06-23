#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  // 深度遍历A树
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == NULL || B == NULL) {
      return false;
    }

    if (doisSubStructure(A, B)) {
      return true;
    }
    if (A->left != NULL && isSubStructure(A->left, B)) {
      return true;
    }
    if (A->right != NULL && isSubStructure(A->right, B)) {
      return true;
    }

    return false;
  }

  // 深度遍历比较A、B
  bool doisSubStructure(TreeNode* node1, TreeNode* node2) {
    if (node1->val != node2->val) {
      return false;
    }
    if (node2->left == NULL && node2->right == NULL) {
      return true;
    }
    if ((node1->left == NULL && node2->left != NULL) ||
        (node1->right == NULL && node2->right != NULL)) {
      return false;
    }
    bool b1 = true, b2 = true, exist = false;
    if (node1->left != NULL && node2->left != NULL) {
      exist = true;
      b1 = doisSubStructure(node1->left, node2->left);
    }

    if (node1->right != NULL && node2->right != NULL) {
      exist = true;
      b2 = doisSubStructure(node1->right, node2->right);
    }

    if (exist) {
      return b1 && b2;
    }
    return false;
  }
};

int main(int argc, char* argv[]) { return 0; }