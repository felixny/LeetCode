// 94. Binary Tree Inorder Traversal

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// recursive
class Solution {
 public:
  vector<int> ans;
  vector<int> inorderTraversal(TreeNode *root) {
    preorder(root);
    return ans;
  }

  void preorder(TreeNode *root) {
    if (root == NULL) return;

    preorder(root->left);
    ans.push_back(root->val);
    preorder(root->right);
  }
};

// iterative
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> t;
    TreeNode *node = root;
    while (node != nullptr || !t.empty()) {
      while (node != nullptr) {
        t.push(node);
        node = node->left;
      }
      node = t.top();
      t.pop();
      ans.push_back(node->val);
      node = node->right;
    }

    return ans;
  }
};
