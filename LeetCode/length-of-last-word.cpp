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
    int lengthOfLastWord(string s) {
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
};

int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("a") << endl;
    return 0;
}