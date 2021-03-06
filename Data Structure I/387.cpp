// 387. First Unique Character in a String

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
    }
};

int main(){

    string s = "leetcode";
    string s1 = "loveleetcode";

    return 0;
}
class Solution {
    int firstUniqChar(string s) {
        int n = s.length();
        // set all 26 to zero
        vector<int> freq(26,0);
        for (int i = 0; s[i] != '\0'; i++){
            freq[s[i] - 'a'] += 1;
        }
        
        for (int i = 0; s[i] != '\0'; i++){
            if (freq[s[i] - 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};
