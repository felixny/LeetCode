// 160. Intersection of Two Linked Lists
#include <algorithm>
#include <iostream>
#include <map>
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode *pA = headA, *pB = headB;

    /*  a = a ? a->next : headB;
     b = b ? b->next : headA;
     三項演算子(ternary operator)
     */

    while (pA != pB) {
      if (pA == nullptr) {
        pA = headB;
      } else {
        pA = pA->next;
      }
      if (pB == nullptr) {
        pB = headA;
      } else {
        pB = pB->next;
      }
    }

    return pA;
  }
};
