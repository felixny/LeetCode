// 21. Merge Two Sorted Lists
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == NULL) return list2;
  if (list2 == NULL) return list1;

  ListNode *head, *current1, *current2;

  // smaller head will be current
  // if list1 is smaller than list2 then list1 will be head
  if (list1->val <= list2->val) {
    head = current1 = list1;
    current2 = list2;
  } else {
    head = current1 = list2;
    current2 = list1;
  }

  if (current1->next == NULL) {
    current1->next = current2;
    return current1;
  }

  while (current2 != NULL && current1 != NULL) {
    if (current1->next == NULL) {
      current1->next = current2;
      current1 = NULL;

      // current 1 value is greater
    } else if (current2->val <= current1->next->val) {
      ListNode* tmp = current1->next;
      current1->next = current2;
      current2 = current2->next;
      current1->next->next = tmp;
    } else {
      current1 = current1->next;
    }
  }

  return head;
}

int main() {}