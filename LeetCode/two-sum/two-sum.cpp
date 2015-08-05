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
    vector<int> twoSum_binarySearch(vector<int> &nums, int target) {
        vector<int> result;
        vector<int> copy(nums);

        sort(copy.begin(), copy.end());
        int size = copy.size();
        for (int i = 0; i < size; i++) {
            int num = target - copy[i];
            int index = binarySearch(copy, i + 1, size - 1, num);

            if (index != -1) {
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j] == copy[i] || nums[j] == num) {
                        result.push_back(j + 1);
                    }
                }
                break;
            }
        }
        return result;
    }

    int binarySearch(vector<int> nums, int begin, int end, int val) {
        int low = begin;
        int high = end;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == val)
                return mid;
            else if (nums[mid] > val)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<int, int> data;
        for (int i = 0; i < nums.size(); i++) {
            data[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (data.find(target - nums[i]) != data.end()
                && i != data[target - nums[i]]) {
                result.push_back(i + 1);
                result.push_back(data[target - nums[i]] + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int a[4] = {0, 3, 2, 4};
    vector<int> nums;
    for (int i = 0; i < 4; i++) {
        nums.push_back(a[i]);
    }
    cout << (sol.twoSum(nums, 6))[0] << " " << (sol.twoSum(nums, 6))[1] << endl;
    return 0;
}