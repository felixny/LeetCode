// 238. Product of Array Except Self

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output;
    if (n < 1) return output;

    int product = 1;
    for (int i = 0; i < n; i++) {
      product *= nums[i];
      output.push_back(product);
    }

    product = 1;
    for (int i = n - 1; i > 0; i--) {
      output[i] = output[i - 1] * product;
      product *= nums[i];
    }

    output[0] = product;

    return output;
  }
};

void print_vec(vector<int> vec) {
  for (int e : vec) cout << e << " ";
  cout << endl;
}

int main() {
  vector<int> nums1 = {1, 2, 3, 4};

  print_vec(Solution().productExceptSelf(nums1));
  

  return 0;
}