// 206. Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {

      ListNode* prev = nullptr;
      ListNode* current = head;
      ListNode* temp = nullptr;

      while (current != nullptr){
        temp = current->next;
        // points to the previous
        current->next = prev;
        // points to where the current is
        prev = current;
        // move the head to temp
        current = temp;
      }

      return prev;
  }
};

