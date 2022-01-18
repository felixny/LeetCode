// 82. Remove Duplicates from Sorted List II

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* sentinel = new ListNode(0, head);

    // predecessor = the last node
    // before the sublist of duplicates
    ListNode* pred = sentinel;

    while (head != nullptr) {
      // if its a beginning of duplicates sublist
      // skip all duplicates
      if (head->next != nullptr && head->val == head->next->val) {
        // move until the end of duplicates sublist
        while (head->next != nullptr && head->val == head->next->val) {
          head = head->next;
        }
        // skip all duplicates
        pred->next = head->next;
        // otherwise, move predecessor
      } else {
        pred = pred->next;
      }

      // move forward
      head = head->next;
    }

    return sentinel->next;
  }
};