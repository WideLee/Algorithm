#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

#define INF -1

using namespace std;

// 1176. Two Ends
/* Sample Input

    4 3 2 10 4
    8 1 2 3 4 5 6 7 8
    8 2 2 1 5 3 8 7 3
    0
    Sample Output

    In game 1, the greedy strategy might lose by as many as 7 points.
    In game 2, the greedy strategy might lose by as many as 4 points.
    In game 3, the greedy strategy might lose by as many as 5 points.
*/

int data[1001];
int dp[1001][1001];

int main() {
    int n = 0, count = 0;

    scanf("%d", &n);
    while (n != 0) {
        count++;

        memset(data, 0, sizeof(data));
        memset(dp, 0, sizeof(dp));

        int sum = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", data + i);
            sum += data[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if ((i - j) % 2 == 0) {
                    dp[i][j] = INF;
                } else if ((i - j) == 1) {
                    dp[i][j] = data[i] > data[j] ? data[i] : data[j];
                } else {
                    int left, right;
                    if (data[j + 1] >= data[i]) {
                        left = j + 2;
                        right = i;
                    } else {
                        left = j + 1;
                        right = i - 1;
                    }
                    int left_data = data[j] + dp[right][left];

                    if (data[j] >= data[i - 1]) {
                        left = j + 1;
                        right = i - 1;
                    } else {
                        left = j;
                        right = i - 2;
                    }

                    int right_data = data[i] + dp[right][left];

                    dp[i][j] = left_data > right_data ? left_data : right_data;
                }
            }
        }


//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                printf("%d ", dp[i][j]);
//            }
//            printf("\n");
//        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", count, 2 * dp[n - 1][0] - sum);

        scanf("%d", &n);
    }
    return 0;
}