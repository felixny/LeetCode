// 15. 3Sum

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// TLE
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return {};
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i = n - 2; i++) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        // left right pointer
        int j = i + 1, k = n - 1;
        while (j < k) {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == 0) {
            result.push_back({nums[i], nums[j], nums[k]});
            while (j < k && nums[j] == nums[j + 1]) j++;
            while (j < k && nums[k] == nums[k - 1]) k--;
            j++;
            k--;
          } else if (sum > 0)
            k--;
          else
            j++;
        }
      }
    }
    return result;
  }
};

// accepeted O(n)
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
      // if next number is the same skips it
      if (i && nums[i] == nums[i - 1]) continue;
      // two pointers set up
      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          ++j;
          while (j < k && nums[j] == nums[j - 1]) ++j;
        } else if (nums[i] + nums[j] + nums[k] < 0) {
          ++j;
        } else {
          --k;
        }
      }
    }

    return ans;
  }
};