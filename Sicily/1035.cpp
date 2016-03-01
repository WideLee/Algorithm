#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

// 1035. DNA matching
/* Sample Input
    2
    3
    ATCG
    TAGC
    TAGG
    2
    AATT
    ATTA
   Sample Output
    1
    0
*/

bool isValid(string A, string B) {
    if (A.length() != B.length()) {
        return false;
    }

    for (int i = 0; i < A.length(); i++) {
        if (!((A[i] == 'A' && B[i] == 'T')
              || (A[i] == 'T' && B[i] == 'A')
              || (A[i] == 'G' && B[i] == 'C')
              || (A[i] == 'C' && B[i] == 'G'))) {
            return false;
        }
    }
    return true;
}

int main() {
    int t = 0;
    scanf("%d", &t);
    while (t-- > 0) {
        int n = 0;
        scanf("%d", &n);
        string dnas[128];
        bool used[128] = {};
        int result = 0;

        for (int i = 0; i < n; i++) {
            cin >> dnas[i];
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!used[i] && !used[j] && isValid(dnas[i], dnas[j])) {
                    result++;
                    used[i] = used[j] = true;
                }
            }
        }

        printf("%d\n", result);
    }
    return 0;
}