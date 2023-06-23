#include <iostream>

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) {
      return NULL;
    }

    Node* pre = new Node(head->val);
    Node* newHead = pre;
    for (Node* cur = head->next; cur != NULL;
         cur = cur->next, pre = pre->next) {
      pre->next = new Node(cur->val);
    }

    for (Node *cur = head, *pre = newHead; cur != NULL;
         cur = cur->next, pre = pre->next) {
      if (cur->random == NULL) continue;
      for (Node *cur2 = head, *pre2 = newHead; cur2 != NULL;
           cur2 = cur2->next, pre2 = pre2->next) {
        if (cur->random == cur2) {
          pre->random = pre2;
          break;
        }
      }
    }

    return newHead;
  }
};

int main(int argc, char* argv[]) { return 0; }