// 33. Search in Rotated Sorted Array

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target){
          return mid;
          // check for uniform curve increasing upwards 
      } else if (nums[mid] >= nums[left]){
          if (target <= nums[mid] && target >= nums[left]){
              right = mid - 1;
          } else {
              left = mid + 1;
          }
      } else {
          if (target >= nums[mid] && target <= nums[right]){
              left = mid + 1;
          } else {
              right = mid - 1;
          }
      }
    }
    return -1;
  }
};