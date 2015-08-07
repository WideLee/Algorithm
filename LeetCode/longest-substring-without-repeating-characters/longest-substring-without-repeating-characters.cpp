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
    int lengthOfLongestSubstring(string s) {
        bool hash[128] = {false};
        int begin = 0, end = 0, max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (hash[s[i]]) {
                max_len = max_len > (end - begin) ? max_len : (end - begin);
                while(hash[s[i]]) {
                    hash[s[begin++]] = false;
                }
            }
            end++;
            hash[s[i]] = true;
        }
        return max_len > (end - begin) ? max_len : (end - begin);;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcde") << endl;
    return 0;
}