#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    map<int, int> mup;

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator iter = mup.find(nums[i]);
            if(iter != mup.end()) {
                int j = iter->second;
                if(i - j <= k) {
                    return true;
                }
            }
            mup[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(1);
    cout << sol.containsNearbyDuplicate(num, 2) << endl;
    return 0;
}