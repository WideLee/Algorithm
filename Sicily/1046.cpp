#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// 1046. Plane Spotting
/* Sample Input
    3
    10 5 5
    1 5 0 2 1 4 2 5 0 2
    10 3 5
    10 3 1 4 2 6 3 0 8 0
    5 5 5
    1 2 3 4 5
   Sample Output

    Result for run 1:
    4-8
    2-8
    6-10
    1-8
    2-6
    Result for run 2:
    1-6
    1-7
    1-9
    Result for run 3:
    1-5

*/

int data[301];

class Period {
public:
    Period() {
        begin = end = 0;
    }

    Period(int begin, int end) {
        this->begin = begin;
        this->end = end;
    }

    int begin;
    int end;

    int length() {
        return end - begin;
    }

    float average() {
        float sum = 0;
        for (int i = begin; i < end; i++) {
            sum += data[i];
        }

        return sum / (end - begin);
    }
};

bool cmp(Period a, Period b) {
    if (a.average() == b.average()) {
        if (a.length() == b.length()) {
            return a.end < b.end;
        } else {
            return a.length() > b.length();
        }
    } else {
        return a.average() > b.average();
    }
}

int main() {
    int t = 0;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n, min_len, num;
        Period p[100000];
        int size = 0;

        memset(data, 0, sizeof(data));
        cin >> n >> num >> min_len;

        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + min_len; j <= n; j++) {
                p[size++] = Period(i, j);
            }
        }


        sort(p, p + size, cmp);

        if (size > num) {
            size = num;
        }

        cout << "Result for run " << k << ":" << endl;
        for (int i = 0; i < size; i++) {
            cout << p[i].begin + 1 << "-" << p[i].end << endl;
        }
    }
    return 0;
}