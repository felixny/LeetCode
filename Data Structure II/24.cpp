// 24. Swap Nodes in Pairs

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
  ListNode* swapPairs(ListNode* head) {
    // dummy node
    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy;
    ListNode* current = head;

    // point the next of dummy node to the head
    dummy->next = head;

    // this node will be used to traverse the list

    // loop until we reach to the second last node
    while (current != nullptr && current->next != nullptr) {
      prev->next = current->next;
      current->next = current->next->next;
      prev->next->next = current;
      current = current->next;
      prev = prev->next->next;
    }
    return dummy->next;
  }
};