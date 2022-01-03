// 235. Lowest Common Ancestor of a Binary Search Tree

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* current = root;

    while (current) {
      if (current->val > p->val && current->val > q->val) {
        current = current->left;
      } else if (current->val < p->val && current->val < q->val) {
        current = current->right;
      } else {
        break;
      }
    }
    return current;
  }
};