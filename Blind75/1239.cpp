// 1239. Maximum Length of a Concatenated String with Unique Characters
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
    int len{0};
public:
    int maxLength(vector<string>& arr) {
        checkLen("",arr,0);
        return len;
    }
    
    void checkLen(string str, vector<string> &arr, int itr){
        if (!isUnique(str)) return;
        
        if (str.size() > len) {
            len = str.size();
        }
        
        for (int i = itr; i < arr.size(); i++){
            cout << "str: " << str+arr[i] << endl;
            checkLen(str+arr[i],arr,i+1);
        }
    }
    
    bool isUnique(string word){
        unordered_set<char> set;
        for (auto s : word){
            cout << "s: " << s << endl;
            if (set.find(s) != set.end()) return false;
            set.insert(s);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> str = {"un","iq","ue"};
    Solution lc1239;
   cout << lc1239.maxLength(str) << endl;

    cout << ""+ str[1] << endl;
    unordered_set<char> string;
    for (auto s : str){
        cout << s << endl;
    }

    return 0;
}
