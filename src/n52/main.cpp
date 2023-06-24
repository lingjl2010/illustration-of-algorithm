#include <istream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // 两个链表找第一个相交，相同步长交换位置
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *node1 = headA;
    ListNode *node2 = headB;

    while (node1 != node2) {
      node1 = node1 != NULL ? node1->next : headB;
      node2 = node2 != NULL ? node2->next : headA;
    }
    return node1;
  }
};