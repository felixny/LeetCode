// 334. Increasing Triplet Subsequence

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() < 3) {
      return false;
    }

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < min1) {
        min1 = nums[i];
      }

      if (nums[i] > min1) {
        min2 = min(nums[i], min2);
      }

      if (nums[i] > min2) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {5, 4, 3, 2, 1};
  vector<int> nums3 = {2, 4, -2, -3};

  cout << Solution().increasingTriplet(nums1) << endl;
  cout << Solution().increasingTriplet(nums2) << endl;

  cout << Solution().increasingTriplet(nums3) << endl;

  return 0;
}