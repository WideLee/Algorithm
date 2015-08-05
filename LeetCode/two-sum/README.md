##Two Sum
2015-08-05 11:03:57

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

```
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
```

> Tags: `Array` `Hash Table`

###题目分析
给定一个数组和一个目标数，找出数组中相加的结果能得到目标数的两个数的位置。

    注意：数组会出现两个相同的元素。

###我的解决方法
一开始想到的就是暴力的解决方法，这样需要O(n^2)的时间复杂度，然后想到了二分查找，为了不改变原数组的顺序，复制一个新数组并对那个数组进行排序，然后从新数组中按顺序取出一个数，然后使用二分查找在新数组剩下的数中找到与给定数的和为目标数的数的位置，如果找到了，那就遍历原数组，找到那两个数原来的位置输出就可以了，这样的解决方法时间复杂度是O(nlogn)

~~~c++
vector<int> twoSum(vector<int> &nums, int target) {
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

~~~

###官方的解决方法
#####O(n2) runtime, O(1) space – Brute force:

The brute force approach is simple. Loop through each element x and find if there is another value that equals to target – x. As finding another value requires looping through the rest of array, its runtime complexity is O(n2).

#####O(n) runtime, O(n) space – Hash table:

We could reduce the runtime complexity of looking up a value to O(1) using a hash map that maps a value to its index.

使用哈希来实现，Key是数组元素的值，Value是元素的位置，由于数组中会出现重复元素，所以要使用unordered_map来进行处理，我使用这个方法的实现如下：

~~~c++
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
~~~

> 注意判断`i != data[target - nums[i]]`，不然会返回两个相同的位置。

**然而这种方法耗时20ms，我的第一种方法耗时12ms，估计是构建unordered_map需要的时间比较长(???)**

###更好的解决方法
一个比较简洁的使用unordered_map的解法，在遍历的过程中往哈希表里边添加元素。

~~~c++
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
            //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);
            result.push_back(i + 1);            
            return result;
        }

        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}
~~~
