// 560. Subarray Sum Equals K

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
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return 0;

    map<int, int> map;
    int currentSum = 0;
    int i = 0;
    int count = 0;
    while (i < n) {
      currentSum += nums[i];

      if (currentSum == k) count += 1;

      // found
      if (map.find(currentSum - k) != map.end()) count += map[currentSum-k];

      map[currentSum] += 1;

      i += 1;
    }

    return count;
  }
};

int main() {
  //vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
  vector<int> nums2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  //cout << Solution().subarraySum(nums, 7) << endl;
  cout << Solution().subarraySum(nums2, 0) << endl;

  return 0;
}