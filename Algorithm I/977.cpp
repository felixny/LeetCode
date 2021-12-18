// 977. Squares of a Sorted Array
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    
    vector<int> temp;
    int mul;
    for (int i = 0; i < nums.size(); i++){
        mul = nums[i]*nums[i];
        cout << mul << endl;
        temp.push_back(mul);
    }

    sort(temp.begin(), temp.end());

  /*   for (auto x : temp)
        cout << x << " "; */
    return temp;
}

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> nums1 = {-7,-3,2,3,11};

    sortedSquares(nums);
    sortedSquares(nums1);

    return 0;
}