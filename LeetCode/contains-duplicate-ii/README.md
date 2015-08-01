##Contains Duplicate II 
2015-08-02 00:58:24

Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

>Tags: `Array` `Hash Table`

###题目分析
找到两个相同的元素位置分别为$i, j$使得他们的位置差不超过$k$
###我的解题思路
使用Map，使用元素的值作为Key，他们在数组的位置作为Value，在遍历数组的过程中，如果有相同的元素加到Map中，就可以对比他们的位置，如果满足条件，返回true，如果不满足，更新当前元素值的位置继续遍历。

~~~c++
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
~~~
