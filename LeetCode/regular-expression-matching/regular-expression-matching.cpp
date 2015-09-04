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
    bool isMatch_rev(string s, string p) {

        // cout << s << ", " << p << endl;

        if (s.length() == 0 && p.length() == 0) {
            return true;
        }

        if (p.length() > 1 && p[1] == '*') {
            int begin = 0;
            while (begin < s.length() && (s[begin] == p[0] || p[0] == '.')) {
                if (isMatch(s.substr(begin + 1, s.length() - begin - 1),
                            p.substr(2, p.length() - 2))) {
                    return true;
                }
                begin++;
            }
            return isMatch(s, p.substr(2, p.length() - 2));
        } else {
            return (s.length() != 0) && (s[0] == p[0] || p[0] == '.')
                   && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
        }
    }

    bool isMatch(string s, string p) {
        bool dp[100][100] = {};
        dp[0][0] = true;

        int s_len = s.length();
        int p_len = p.length();

        for (int i = 0; i <= s_len; i++) {
            for (int j = 1; j <= p_len; j++) {
                if (p[j - 1] != '*' && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) {
                    dp[i][j] = dp[i - 1][j - 1] && i > 0;
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]
                               || (i > 0 && dp[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
                } else {
                    dp[i][j] = false;
                }
            }
        }

        // print(dp, s_len, p_len);
        return dp[s_len][p_len];

    }

    void print(bool dp[100][100], int x, int y) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    Solution sol;

    cout << sol.isMatch("abbbc", "ab*c") << endl;
    cout << sol.isMatch("ac", "ab*c") << endl;
    cout << sol.isMatch("abbc", "ab*bbc") << endl;
    cout << sol.isMatch("abcbcd", "a.*c.*d") << endl;
    cout << sol.isMatch("aa", "a") << endl;
    cout << sol.isMatch("aa", "aa") << endl;
    cout << sol.isMatch("aaa", "aa") << endl;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("aa", ".*") << endl;
    cout << sol.isMatch("ab", ".*") << endl;
    cout << sol.isMatch("aab", "c*a*b") << endl;
    cout << sol.isMatch("ab", ".*c") << endl;
    cout << sol.isMatch("a", "ab*") << endl;
    cout << sol.isMatch("a", ".*..a*") << endl;
    cout << sol.isMatch("", ".") << endl;

    return 0;
}