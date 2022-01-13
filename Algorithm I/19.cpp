// 19. Remove Nth Node From End of List
// Two pointers

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    // move fast n steps
    for (int i = 0; i < n; i++) {
      if (fast->next == nullptr) {
        // if number of nodes equal to number of n
        if (i == n - 1) {
          head = head->next;
        }
        return head;
      }
      fast = fast->next;
    }

    // move both at one time
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    // re-link
    if (slow->next != nullptr) {
      slow->next = slow->next->next;
    }

    return head;
  }
};

int main() { return 0; }
