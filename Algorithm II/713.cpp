// 713. Subarray Product Less Than K

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int result = 0, product = 1, left = 0, right = 0;
        while(right<nums.size()){
            product *= nums[right];
            while (product >= k){
                product /= nums[left];
                left++;
            }
            result += (right - left) +1;
            right++;
        }

        return result;
    }
};

int main(){


    return 0;
}