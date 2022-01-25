// 78. Subsets

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  void subsets_rec(vector<int>& nums, int index, vector<vector<int>>& result) {
      // last element;
    if (index == nums.size() - 1) {
      result.push_back({});
      result.push_back({nums[index]});

    } else {
      subsets_rec(nums, index + 1, result);
      int n = result.size();
      for (int i = 0; i < n; i++) {
        vector<int> r = result[i];
        r.push_back(nums[index]);
        result.push_back(r);
      }
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) return {{}};
    vector<vector<int>> result;
    subsets_rec(nums, 0, result);

    return result;
  }
};

int main() { return 0; }
