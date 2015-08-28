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
    int myAtoi(string str) {
        double result = 0;
        bool is_begin = false;
        bool sign = true;
        bool overflow = false;
        for (int i = 0; i < str.length(); i++) {
            if (!is_begin && str[i] == ' ') {
                continue;
            } else if (!is_begin && (str[i] == '+' || str[i] == '-')) {
                is_begin = true;
                sign = (str[i] != '-');
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                is_begin = true;
                result = result * 10 + (str[i] - '0');
                overflow = !((sign && result < INT_MAX)
                           || (!sign && result > INT_MIN));
            } else {
                break;
            }
        }
        if (overflow) {
            return sign ? INT_MAX : INT_MIN;
        } else {
            return sign ? result : -result;
        }
    }
};


int main() {
    Solution sol;

    cout << sol.myAtoi("-2147483649") << endl;
    cout << atoi("-2147483649") << endl;
    cout << sol.myAtoi("2147483648") << endl;
    cout << atoi("2147483648") << endl;
    cout << sol.myAtoi("-1") << endl;
    cout << atoi("-1") << endl;
    cout << sol.myAtoi("-2147483647") << endl;
    cout << atoi("-2147483647") << endl;
    return 0;
}