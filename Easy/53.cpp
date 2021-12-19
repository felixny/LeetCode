// 53. maximum subarray
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
  int sum = INT_MIN;
  int max_sofar = 0;

  for (int i = 0; i < nums.size(); i++) {
    max_sofar = max_sofar + nums[i];

    if (sum < max_sofar) sum = max_sofar;
    if (max_sofar < 0) max_sofar = 0;
  }
  return sum;
}

int main() {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> nums1 = {5, 4, -1, 7, 8};
  vector<int> nums2 = {1};

  cout << maxSubArray(nums) << endl;
  cout << maxSubArray(nums1) << endl;
  cout << maxSubArray(nums2) << endl;

  return 0;
}