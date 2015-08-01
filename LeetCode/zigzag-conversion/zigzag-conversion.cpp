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
    string convert(string s, int numRows) {
        string cons;

        if(numRows > 1) {
            int k = 2 * (numRows - 1);

            int cur = 0;
            while (cur < s.length()) {
                cons += s[cur];
                cur += k;
            }

            for (int i = 1; i < numRows - 1; i++) {
                cur = i;
                while (cur < s.length()) {
                    cons += s[cur];
                    int next = cur + k - 2 * i;
                    if (next < s.length()) {
                        cons += s[next];
                    }
                    cur += k;
                }
            }

            cur = numRows - 1;
            while (cur < s.length()) {
                cons += s[cur];
                cur += k;
            }
        } else {
            cons = s;
        }

        return cons;
    }
};

int main() {
    Solution sol;

    cout << sol.convert("A", 1) << endl;
    return 0;
}