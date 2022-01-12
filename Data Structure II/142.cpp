// 142. Linked List Cycle II
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    bool isCycle = false;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        isCycle = true;
        break;
      }
    }

    if (!isCycle) return nullptr;

    slow = head;

    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};