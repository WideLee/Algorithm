## 3Sum

2017-03-08 10:44:38

Given an array *S* of *n* integers, are there elements *a*, *b*, *c* in *S* such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

>  **Note:** The solution set must not contain duplicate triplets.

```
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

> Tags: `Array` `Two Pointers`



### 题目分析

在一个数组中找到三个数使得他们的和为0

### 我的解题思路

直接使用暴力的方法，先固定一个数，然后使用map构建反向索引，找到所有可能相加等于目标的组合，同时，使用一个set来判断是否重复。

```c++
vector<vector<int>> threeSum_error(vector<int> &nums) {
    // Time Limit Exceeded
  	vector<vector<int> > result;

    sort(nums.begin(), nums.end());

    unordered_map<int, int> data;
    for (int i = 0; i < nums.size(); i++) {
      data[nums[i]] = i;
    }

    unordered_map<int, vector<pair<int, int>>> as;
    set<vector<int>> hash;

    int value = nums[0] + nums[1];
    vector<pair<int, int>> sums;
    sums.push_back(make_pair(0, 1));
    as[value] = sums;

    for (int i = 2; i < nums.size(); ++i) {
      if (as.find(-nums[i]) != as.end()) {
        vector<pair<int, int>> possible = as[-nums[i]];
        for (int j = 0; j < possible.size(); ++j) {
          vector<int> triple;
          triple.push_back(nums[possible[j].first]);
          triple.push_back(nums[possible[j].second]);
          triple.push_back(nums[i]);
          sort(triple.begin(), triple.end());
          if (hash.find(triple) == hash.end()) {
            result.push_back(triple);
            hash.insert(triple);
          }
        }
      }

      for (int j = 0; j < i; j++) {
        value = nums[j] + nums[i];
        vector<pair<int, int>> possible;
        if (as.find(value) != as.end()) {
          possible = as[value];
        }
        possible.push_back(make_pair(j, i));
        as[value] = possible;
      }

    }
    return result;
}

```

但这样会超时，后来发现超时的关键在于重复组合的判断

### 更好的方法

[AC C++ solution](https://discuss.leetcode.com/topic/8107/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments)

参考这个方法，首先对数组进行排序，然后固定第一个数，剩下两个数在数组中从两端开始往中间搜索，如果较小那个数加上较大的数大于目标，那么较大的数指针往前移动，反之就是较小的数的指针往后移动，直到找到相加和为目标的两个数或者指针交叉为止。

**只用这种方法还是会超时，缩短时间的关键在于重复元素的判断**

因为数组是经过排序的，因此相同的数一定会在相邻的位置，那么在把三个数放入result数组之后，分别往前往后调过所有相同的数

```c++
vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int> > result;

  sort(nums.begin(), nums.end());

  for (int index = 0; index < nums.size(); ++index) {
    int target = -nums[index];

    int front = index + 1;
    int end = nums.size() - 1;

    while (front < end) {
      int sum = nums[front] + nums[end];

      if (sum > target) {
        end--;
      } else if (sum < target) {
        front++;
      } else {
        vector<int> valid;
        valid.push_back(nums[index]);
        valid.push_back(nums[front]);
        valid.push_back(nums[end]);
        result.push_back(valid);

        // Processing duplicates of Number 2
        while (front < end && nums[front] == valid[1]) front++;

        // Processing duplicates of Number 3
        while (front < end && nums[end] == valid[2]) end--;
      }
    }

    while (index + 1 < nums.size() 
           && nums[index] == nums[index + 1]) {
      index++;
    }
  }

  return result;
}
```

