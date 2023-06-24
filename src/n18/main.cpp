#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* deleteNode(ListNode* head, int val) {
    while (head->val == val) {
      head = head->next;
    }
    ListNode* pre = head;
    for (ListNode* node = pre->next; node != NULL; node = node->next) {
      if (node->val == val) {
        pre->next = node->next;
      }

      pre = pre->next;
    }
    return head;
  }
};