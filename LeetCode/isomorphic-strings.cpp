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
    bool isIsomorphic(string s, string t) {
        char map_table[128] = {};
        bool is_matched[128] = {};
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            char d = map_table[c];
            if (d == 0) {
                if (is_matched[t[i]]) {
                    return false;
                } else {
                    map_table[c] = t[i];
                    is_matched[t[i]] = true;
                }
            } else {
                if (d != t[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isIsomorphic("ab", "aa") << endl;
    return 0;
}