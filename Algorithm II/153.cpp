// 153. Find Minimum in Rotated Sorted Array

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// recursive
class Solution {
  int search(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int mid = l + (r - l) / 2;
    if (nums[mid] > nums[r]) return search(nums, mid + 1, r);
    if (nums[mid] < nums[r]) return search(nums, l, mid);
    return nums[r];
  }

 public:
  int findMin(vector<int>& nums) { return search(nums, 0, nums.size() - 1); }
};

// iterative
class Solution {
  /* int search(vector<int>& nums, int l, int r){
      if (l == r) return nums[l];
      int mid = l + (r-l)/2;
      if (nums[mid] > nums[r]) return search(nums,mid+1,r);
      if (nums[mid] < nums[r]) return search(nums, l, mid);
      return nums[r];
  } */

 public:
  int findMin(vector<int>& nums) {
    // return search(nums, 0, nums.size()-1);
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > nums[r]) l = mid + 1;
      if (nums[mid] < nums[r])
        r = mid;
      else
        nums[r];
    }

    return nums[l];
  }
};

int main() { return 0; }