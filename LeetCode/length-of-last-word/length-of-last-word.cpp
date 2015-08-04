#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLastWord_normal(string s) {
        int result = 0;
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if(length != 0) {
                    result = length;
                }
                length = 0;
            } else {
                length++;
            }
        }
        if(length != 0) {
            result = length;
        }
        return result;
    }
    
    int lengthOfLastWord(string s) {
        int result = 0;
        int length = s.length();
        for(int i = length - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(result == 0) {
                    continue;
                } else {
                    break;
                }
            }
            
            result ++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("abc  aaaaaa") << endl;
    return 0;
}