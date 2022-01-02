// 701. Insert into a Binary Search Tree

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
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

class Solution {
 public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    // if root is null
    if (root == nullptr) return new TreeNode(val);

    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }

    return root;
  }
};

class Solution {
 public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    // if root is null
    if (root == nullptr) return new TreeNode(val);

    TreeNode *p = root;
    while (true) {
      if (val < p->val) {
        // if p->left is empty
        if (p->left == nullptr) {
          p->left = new TreeNode(val);
          break;
        }
        p = p->left;
      } else {
        if (p->right == nullptr) {
          p->right = new TreeNode(val);
          break;
        }
        p = p->right;
      }
    }

    return root;
  }
};