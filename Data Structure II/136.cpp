// 136. Single Number

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // bitwise operation: XOR ^
  // As a^b^c^a^b^d^d
  //   =a^a^b^b^d^d^c
  //   =0^  0^  0  ^c
  //   =c
  int singleNumber(vector<int>& nums) {
    int count = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      count = count ^ nums[i];
    }
    return count;
  }
};
int main() {
  vector<int> nums = {2, 2, 1};
  vector<int> nums1 = {4, 1, 2, 1, 2};

  cout << Solution().singleNumber(nums) << endl;
  cout << Solution().singleNumber(nums1) << endl;
}