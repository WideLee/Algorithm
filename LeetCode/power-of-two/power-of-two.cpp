#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
//        if(n <= 0) {
//            return  false;
//        }
//        int pow = 1;
//        for(int i = 0; i < 31; i++) {
//            if(n == pow) {
//                return true;
//            }
//            pow <<= 1;
//        }
//        return false;

        // This is The better solution!
        return (n > 0) && !(n & (n - 1));
    }
};

int main() {

    Solution sol;
    int n;
    while (cin >> n) {
        cout << sol.isPowerOfTwo(n) << endl;
    }

    return 0;
}