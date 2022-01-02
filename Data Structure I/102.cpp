// 102. Binary Tree Level Order Traversal

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;//Store the result
        if (!root) return res;// When the root node is empty, return directly

        queue<TreeNode*> q;// Define a queue, put a layer of elements into the queue each time
        q.push(root); // Put the root node first

        while (q.size()){
            int len = q.size();// First calculate the size of the queue, that is, how many elements there are in this layer (how many elements need to be put into res)
            vector<int> level;// used to store the elements of this layer
            
            for (int i = 0; i < len; ++i){
                // Take an element from the head of the queue and store it in level
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                // Determine whether the extracted element has left and right subtrees, if so, store it in queue q
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(level);// Store the nodes of this layer in the result res
        }
        return res;
    }
};