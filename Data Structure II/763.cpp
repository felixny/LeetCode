// 763. Partition Labels

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> end_index(26,0);
        for (int i = 0; i < s.length(); i++){
            end_index[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++){
            end = max(end,end_index[s[i] - 'a']);
            if (i == end){
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};

void print_vec(const vector<int> &vec) {
  for (int e : vec) cout << e << " ";
  cout << endl;
}


int main(){

    print_vec(Solution().partitionLabels("ababcbacadefegdehijhklij"));

    return 0;
}