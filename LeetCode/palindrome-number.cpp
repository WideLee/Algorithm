#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int p = 1, tempx = x;
        while (tempx > 9) {
            tempx /= 10;
            p *= 10;
        }
                
        int q = 10;
        while(true) {
            if(x < 10 && p < 9) {
                return true;
            }            
            int pre = x / p;
            int post = x % q;
            
            if(pre != post) {
                return false;
            }
                        
            x = x - pre * p;

            x = (x - post) / 10;
            
            p /= 100;
            
            // cout << p << endl;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    int n;
    while(cin >> n) {
        cout << sol.isPalindrome(n) << endl;
    }
    
    return 0;
}