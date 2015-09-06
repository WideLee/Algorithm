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

    int romanToInt(string s) {
        int roman[26];
        roman['I' - 'A'] = 1;
        roman['V' - 'A'] = 5;
        roman['X' - 'A'] = 10;
        roman['L' - 'A'] = 50;
        roman['C' - 'A'] = 100;
        roman['D' - 'A'] = 500;
        roman['M' - 'A'] = 1000;

        int result = 0;
        int length = s.length();
        for (int i = 0; i < length - 1; i++) {
            if (roman[s[i] - 'A'] >= roman[s[i + 1] - 'A']) {
                result += roman[s[i] - 'A'];
            } else {
                result -= roman[s[i] - 'A'];
            }
        }

        result += roman[s[length - 1] - 'A'];

        return result;
    }

    string intToRoman_better(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};


int main() {
    Solution sol;
    string roman[4000];
    for (int i = 1; i < 4000; i++) {
        roman[i - 1] = sol.intToRoman_better(i);
    }

    for (int i = 0; i < 3999; i++) {
        if (sol.romanToInt(roman[i]) != i + 1) {
            cout << "ERROR!!!" << endl;
        }
    }

    return 0;
}