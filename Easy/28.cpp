// 28. Implement strStr()

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int strStr(string haystack, string needle){
    // if empty 
    if (!needle.size()){
        return 0;
    }

    for (int i = 0; i < haystack.size(); i++){
        if (haystack[i] == needle[0]){
            int j = 0;
            for (int j = 0; i < needle.size(); j++){
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == needle.size()) return i;
            
        }
    }
    return - 1;
}

int main(){
    

    return 0;
}