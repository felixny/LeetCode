// 560. Subarray Sum Equals K
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        if (n==0) return 0;
        map<int,int> map;
        int count = 0;
        int i =0;
        
        while(i < n){
            sum += nums[i];
            
            if (sum == k) count += 1;
            
            // found
            if (map.find(sum-k) != map.end()){
                cout << "called" << endl;
                count += map[sum-k];
            }
            
            cout << sum << " sum " << endl;
            cout << map[sum] << ": before" << endl;
            map[sum] += 1;
            cout << "value: " << map[sum] << endl;
            
            i += 1;
        }

        for (const auto& [key,value] : map){
            cout << "[" << key << ", " << value << "]\n";
        }
        
        return count;
    }
};

int main(){
    Solution lc560;
    vector<int> test = {1,2,3};
    cout << lc560.subarraySum(test, 3) << endl;
    
}