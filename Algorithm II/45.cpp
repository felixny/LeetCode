// 45. Jump Game II

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int l = 0, r = 0;

    while (r < n - 1) {
      int farthest = r;
      for (int i = l; i <= min(r, n - 1); i++) {
        farthest = max(farthest, i + nums[i]);
      }

      l = r + 1;
      r = farthest;
      count++;
    }

    return count;
  }
};
