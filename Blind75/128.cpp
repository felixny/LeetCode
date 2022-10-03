// longest consecutive seq
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxSum = 0;
        unordered_set<int> num_set(nums.begin(),nums.end());
        for (int num : nums){
            // if num is found?
            if (num_set.find(num-1) == num_set.end()){
                int cur = num;
                int cur_len = 1;
                while(num_set.find(cur+1) != num_set.end()){
                    cur++;
                    cur_len++;
                }
                maxSum = max(maxSum,cur_len);
            }
        }
        
        return maxSum;
    }
};

int main(){
    Solution lc128;
    vector<int> nums = {100,4,200,1,3,2};
    cout << lc128.longestConsecutive(nums) << endl;

}