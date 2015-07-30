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
    int countPrimes(int n) {
        // bool isPrime[100000] = {};
        // Use vector to avoid the Runtime Error.
        vector<bool> isPrime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
                for (int j = 2; j <= n / i; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.countPrimes(120) << endl;
    return 0;
}