#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    int len = size(head);
    if (len < k) {
      return NULL;
    }

    ListNode* node = head;
    for (int i = 0; i < len - k; i++, node = node->next) {
    }
    return node;
  }

  int size(ListNode* head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }
};