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
    int reverse(int x) {
        bool sign = true;
        if (x < 0) {
            sign = false;
            x = -x;
        }
        int result = 0;
        while (x > 0) {
            int n = x % 10;
            if (result > (INT_MAX - n) / 10) {
                return 0;
            }
            result = result * 10 + n;
            x /= 10;
        }

        return sign ? result : -result;
    }
};


int main() {
    Solution sol;

    cout << sol.reverse(1000000003) << endl;
    cout << sol.reverse(1534236469) << endl;
    return 0;
}