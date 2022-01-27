// 413. Arthmetic Slices

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int current = 0;
    int result = 0;

    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        current += 1;
      } else {
        current = 0;
      }
      result += current;
    }

    return result;
  }
};
