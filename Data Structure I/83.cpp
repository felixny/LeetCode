// 83. Remove Duplicates from Sorted List

#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode *CreateList(int n) {
  ListNode *head;
  ListNode *p, *pre;
  int i;
  head = (ListNode *)malloc(sizeof(ListNode));
  head->next = NULL;
  pre = head;
  for (i = 1; i <= n; i++) {
    p = (ListNode *)malloc(sizeof(ListNode));
    cin >> p->val;
    pre->next = p;
    pre = p;
  }
  p->next = NULL;

  return head->next;
}
/*-------------------------Output linked list-----------------------
 * ------------*/
void PrintList(ListNode *h) {
  ListNode *p;

  p = h;  // Head node without empty
  while (p) {
    cout << p->val << " ";
    p = p->next;
    cout << endl;
  }
}
class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *pre = head;
    ListNode *pNode = head;
    while (pNode != NULL) {
      while (pNode->val == pre->val) {
        if (pNode->next != NULL)
          pNode = pNode->next;
        else {
          pre->next = NULL;
          return head;
        }
      }
      pre->next = pNode;
      pre = pre->next;
    }
    return head;
  }
};
int main() {
  int n1;
  ListNode *h1;
  cout << "Enter the number of nodes in linked list 1" << endl;
  cin >> n1;
  h1 = CreateList(n1);
  cout << "Linked list 1 is:" << endl;
  PrintList(h1);
  Solution s;
  ListNode *h2;
  h2 = s.deleteDuplicates(h1);
  cout << "After weight removal, the linked list is:" << endl;
  PrintList(h2);
  return 0;
}