#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) { return doRecursionReverseList(head); }

  // 遍历法
  ListNode* doReverseList(ListNode* head) {
    ListNode* pre = NULL;
    while (head != NULL) {
      ListNode* next = head->next;

      head->next = pre;

      pre = head;
      head = next;
    }

    return pre;
  }

  ListNode* doRecursionReverseList(ListNode* cur, ListNode* pre = NULL) {
    if (cur == NULL) return pre;

    ListNode* next = cur->next;

    cur->next = pre;

    return doRecursionReverseList(next, cur);
  }
};

int main(int argc, char* argv[]) {}