#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        int result = 0;

        int S1 = (C - A) * (D - B);
        int S2 = (G - E) * (H - F);

        double x = (double) min(D, H) - max(B, F);
        double y = (double) min(C, G) - max(A, E);
        int coor = (x > 0 ? x : 0) * (y > 0 ? y : 0);

        result = S1 + S2 - coor;

        return result;
    }

    int max(int A, int B) {
        return A > B ? A : B;
    }

    int min(int A, int B) {
        return A < B ? A : B;
    }
};

int main() {
    Solution sol;

    // Most Important Test Case !!! Be Attention of OVERFLOW...

    cout << sol.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;

    return 0;
}