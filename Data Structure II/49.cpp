// 49. Group Anagrams

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        int n = strs.size();

        string tmp;
        for (int i = 0; i < n; i++){
            tmp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            map[strs[i]].push_back(tmp);
        }

        vector<vector<string>> result;

        for (auto itr = map.begin(); itr != map.end(); itr++){
            result.push_back(itr->second);
        }

        return result;
    }
};



int main(){

   

    return 0;
}