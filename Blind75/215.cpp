// 215. Kth Largest Element in an Array

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) pq.push(nums[i]);
    // k = 2
   showpq(pq);

    for (int i = k; i < nums.size(); i++) {
        cout << "nums: " << nums[i] << endl;
        cout << "pq.top: " << pq.top() << endl;
      if (pq.top() < nums[i]) {
        pq.pop();
        pq.push(nums[i]);
      }
    }

    return pq.top();
  }

  void showpq(priority_queue<int, vector<int>, greater<int>> gq) {
    priority_queue<int, vector<int>, greater<int>> g = gq;
    while (!g.empty()) {
      cout << g.top();
      g.pop();
    }
    cout << '\n';
  }
};

int main() {
  Solution lc215;
  vector<int> test = {3, 2, 1, 5, 6, 4};
  cout << lc215.findKthLargest(test, 2) << endl;
}
