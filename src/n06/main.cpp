#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    vector<int> results;
    // recursionReversePrint(head, results);

    stackReversePrint(head, results);
    return results;
  }

  // 递归法
  void recursionReversePrint(ListNode* node, vector<int>& results) {
    if (node == NULL) {
      return;
    } else {
      recursionReversePrint(node->next, results);
      results.emplace_back(node->val);
    }
  }

  // 压栈法
  void stackReversePrint(ListNode* node, vector<int>& results) {
    std::stack<int> s;
    while (node != NULL) {
      s.emplace(node->val);
      node = node->next;
    }

    while (s.size() > 0) {
      results.emplace_back(s.top());
      s.pop();
    }
  }

  /*
   旗帜    1 -> 2 -> 3 -> 4
   NULL <- 1   2 -> 3 -> 4
   NULL <- 1 <- 2   3 -> 4
   NULL <- 1 <- 2 <- 3   4
   NULL <- 1 <- 2 <- 3 <- 4
   */
  // 反转链表
  ListNode* reverseList(ListNode* head) {
    // 旗帜位
    ListNode* pre = NULL;
    while (head != NULL) {
      // 记录下一位
      ListNode* next = head->next;

      // 把自己的next指向上一位
      head->next = pre;

      // 旗帜位和游标后移
      pre = head;
      head = next;
    }
    return pre;
  }

  // 递归法反转链表
  ListNode* recursionReverseList(ListNode* start, ListNode* last = NULL) {
    if (start == NULL) return last;

    ListNode* temp = start->next;

    start->next = last;

    return recursionReverseList(temp, start);
  }
};

int main(int argc, char* argv[]) {}