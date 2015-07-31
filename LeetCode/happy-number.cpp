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


/**
 * If the next number in the sequence is 1, then the original number was happy.
 * If it was not happy, we enter a cycle that contains the number 4.
 * We could use a cycle detection strategy to do this also,
 * or just test for a given number in the (short) cycle as done here.

    class Solution {
    public:
        bool isHappy(int n) {
            while (true) {
                if (n == 1) { return true; }
                if (n == 4) { return false; }
                int next = 0;
                while (n) { next += (n % 10) * (n % 10), n /= 10; }
                n = next;
            }
        }
    };
 */

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }

        bool isVisited[1000] = {};
        int val = n;
        while (true) {
            val = sumOfNum(val);
            if (val == 1) {
                return true;
            }
            if (isVisited[val]) {
                return false;
            }
            isVisited[val] = true;
        }
    }

    int sumOfNum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

};

int main() {
    Solution sol;
    cout << sol.isHappy(29) << endl;
    return 0;
}