// 394. Decode String

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string recursive(string &s, int &index){
        string res;
        while(index < s.length() && s[index] != ']'){
            if (!isdigit(s[index])){
                res += s[index++];
            } else {
                int k = 0;
                while (index < s.length() && isdigit(s[index])){
                    k = k*10 + s[index++] - '0';
                }
                    index++;
                    string dec = recursive(s,index);
                    index++;
                    while(k-->0)
                        res += dec;
                
            }
        }
        
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return recursive(s,index);
    }
};

int main(){
    Solution lc394;
    string s = "3[a]2[bc]";
    cout << lc394.decodeString(s) << endl;
    
}