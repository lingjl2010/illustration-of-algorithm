#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // 合并排序列表
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *ret = new ListNode(0), *ret2 = ret, *n1 = l1, *n2 = l2;
    for (; n1 && n2;) {
      if (n1->val < n2->val) {
        ret->next = n1;
        n1 = n1->next;
      } else {
        ret->next = n2;
        n2 = n2->next;
      }
      ret = ret->next;
    }

    if (n1) {
      ret->next = n1;
    } else if (n2) {
      ret->next = n2;
    }

    return ret2->next;
  }
};

int main(int argc, char* argv[]) { return 0; }
