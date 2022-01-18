// 162. Find Peak Element

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// recursive
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    // return find(nums,0,nums.size()-1);
    // iterative
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[m + 1]) r = m;
      else l = m+ 1;
    }
    return l;
  }

 private:
  int find(vector<int>& nums, int l, int r) {
    if (l == r) return l;
    int m = l + (r - l) / 2;
    // if right side is bigger
    if (nums[m] > nums[m + 1])
      return find(nums, l, m);
    else
      return find(nums, m + 1, r);
  }
};