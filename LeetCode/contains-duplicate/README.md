##Contains Duplicate
2015-08-02 00:30:21 

Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

>Tags: `Array` `Hash Table`

####题目分析
给定一个数组，判断数组是否有相同的元素。


####我的解题思路
给数组排序，然后遍历数组如果相邻的两个值一样，那返回true，如果找不到这样相同的两个数，那返回false，这个解法时间复杂度为O(nlogn)，空间复杂度为排序算法所需要的空间复杂度。

~~~c++
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            return true;
        }
    }
    return false;
}
~~~
####更好地解决方法
利用set没有重复元素的特性，只需要一行代码：

~~~c++
bool containsDuplicate(vector<int>& nums) {
	return set<int>(nums.begin(), nums.end()).size() < nums.size();
}

~~~
