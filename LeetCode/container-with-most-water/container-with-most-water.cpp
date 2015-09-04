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
    int maxArea(vector<int> &height) {
        int max = 0;
        int begin = 0;
        int end = height.size() - 1;
        while (begin <= end) {
            int hb = height[begin];
            int he = height[end];
            int area = min(hb, he) * (end - begin);
            max = area > max ? area : max;
            if (hb < he) {
                while (height[begin++] < hb);
            } else {
                while (height[end--] < he);
            }
        }
        return max;
    }
};


int main() {
    Solution sol;

    vector<int> height;
    height.push_back(1);
    height.push_back(2);
    height.push_back(5);
    height.push_back(7);
    height.push_back(9);
    height.push_back(4);
    cout << sol.maxArea(height) << endl;
    return 0;
}