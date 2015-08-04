##Summary Ranges
2015-08-04 10:26:29

Given a **sorted integer array without duplicates**, return the summary of its ranges.

For example, given `[0,1,2,4,5,7]`, return `["0->2","4->5","7"]`.

> Tags: `Array`

###题目分析
给定一个排好序而且没有重复的整数数组，将这个数组归纳成字符串

###我的解决方法
按照要求依次遍历数组，如果遇到前后相差不是1的就往结果的数组里添加一个字符串，注意边界条件。

~~~c++
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
~~~
