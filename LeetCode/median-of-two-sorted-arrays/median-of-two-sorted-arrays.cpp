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
    double findMedianSortedArrays_old(vector<int> &nums1, vector<int> &nums2) {
        vector<int> total;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (i == nums1.size()) {
                total.push_back(nums2[j++]);
            } else if (j == nums2.size()) {
                total.push_back(nums1[i++]);
            } else {
                if (nums1[i] < nums2[j]) {
                    total.push_back(nums1[i++]);
                } else {
                    total.push_back(nums2[j++]);
                }
            }
        }
        return (double) (total[(total.size() - 1) / 2] + total[total.size() / 2]) / 2;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        if (m == 0) {
            return (double) (nums2[n / 2] + nums2[(n - 1) / 2]) / 2;
        }

        int imin = 0;
        int imax = m;

        while (imin <= imax) {
            int imid = (imin + imax) / 2;
            int j = (m + n + 1) / 2 - imid;

            if (j > 0 && imid < m && nums2[j - 1] > nums1[imid]) {
                imin = imid + 1;
            } else if (imid > 0 && j < n && nums1[imid - 1] > nums2[j]) {
                imax = imid - 1;
            } else {
                int num1, num2;
                if (imid == 0) {
                    num1 = nums2[j - 1];
                } else if (j == 0) {
                    num1 = nums1[imid - 1];
                } else {
                    num1 = max(nums1[imid - 1], nums2[j - 1]);
                }

                if ((m + n) % 2 == 1) {
                    return num1;
                }

                if (imid == m) {
                    num2 = nums2[j];
                } else if (j == n) {
                    num2 = nums1[imid];
                } else {
                    num2 = min(nums1[imid], nums2[j]);
                }

                return (double) (num2 + num1) / 2;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;
    nums1.push_back(1);
//    nums1.push_back(2);
//    nums1.push_back(5);
//    nums1.push_back(7);
//    nums1.push_back(9);
    // 1 3 4 5 7 9
    // 2 3 4 6
    nums2.push_back(2);
//    nums2.push_back(2);
//    nums2.push_back(3);
//    nums2.push_back(6);
    
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}