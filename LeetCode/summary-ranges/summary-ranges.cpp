#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()) {
            return result;
        }
        int pre = nums[0];
        string summary = to_string(pre);
        bool has_more = false;
        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i] != pre + 1 || i == nums.size()) {
                if(has_more) {
                    summary = summary + "->" + to_string(pre);
                }
                string str = summary.c_str();
                result.push_back(str);
                summary = to_string(nums[i]);
                has_more = false;
            } else {
                has_more = true;
            }
            pre = nums[i];
        }

        return result;
    }

    void print(vector<string> strs) {
        for(int i = 0; i < strs.size(); i++) {
            cout << strs[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    Solution sol;
    int n;
    while (cin >> n) {
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        sol.print(sol.summaryRanges(nums));
    }

    return 0;
}