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
    string intToRoman_bad(int num) {
        string roman;
        if (num >= 4000) {
            return roman;
        }
        while (num >= 1000) {
            roman += "M";
            num -= 1000;
        }

        if (num >= 900) {
            roman += "CM";
            num -= 900;
        } else if (num >= 500) {
            roman += "D";
            num -= 500;
        } else if (num >= 400) {
            roman += "CD";
            num -= 400;
        }

        while (num >= 100) {
            roman += "C";
            num -= 100;
        }

        if (num >= 90) {
            roman += "XC";
            num -= 90;
        } else if (num >= 50) {
            roman += "L";
            num -= 50;
        } else if (num >= 40) {
            roman += "XL";
            num -= 40;
        }

        while (num >= 10) {
            roman += "X";
            num -= 10;
        }

        if (num >= 9) {
            roman += "IX";
            num -= 9;
        } else if (num >= 5) {
            roman += "V";
            num -= 5;
        } else if (num >= 4) {
            roman += "IV";
            num -= 4;
        }

        while (num >= 1) {
            roman += "I";
            num -= 1;
        }

        return roman;
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
    for (int i = 1; i < 4000; i++) {
        cout << "\"" << sol.intToRoman_better(i) << "\",";
        if(i % 10 == 0) {
            cout << endl;
        }
    }
    return 0;
}