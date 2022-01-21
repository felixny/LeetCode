// 117. Populating Next Right Pointers in Each Node II

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) {
      return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();

      for (int i = 0; i < n; i++) {
        Node* node = q.front();
        q.pop();

        if (i != n - 1) {
          node->next = q.front();
        } else
          node->next = NULL;

        if (node->left) q.push(node->left);

        if (node->right) q.push(node->right);
      }
    }
    return root;
  }
};
