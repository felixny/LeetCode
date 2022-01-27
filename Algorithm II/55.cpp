// 55. Jump Game

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int reachable = 0;
    for (int i = 0; i < n; i++) {
      if (reachable < i) return false;

      reachable = max(reachable, i + nums[i]);
    }

    return true;
  }
};
