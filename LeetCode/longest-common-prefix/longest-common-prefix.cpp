#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        unsigned long longest = strs[0].length();

        for (int i = 1; i < strs.size(); i++) {
            unsigned long index = 0;
            while (index < strs[i].length()
                   && index < longest
                   && strs[i][index] == strs[0][index]) {
                index++;
            }
            longest = index;
        }

        return strs[0].substr(0, longest);
    }
};


int main() {
    Solution sol;
    vector<string> strs;
    strs.push_back("a");
    strs.push_back("abcsfa");
    strs.push_back("abcdefaaa");
    strs.push_back("");
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}