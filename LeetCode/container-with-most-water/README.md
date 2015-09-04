##Container With Most Water
2015-09-01 11:52:02

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

>Tags: `Array` `Two Pointers`

###题目分析
给定一个数组，以数组的数作为线段的长度，元素的位置作为线段在数轴上的位置，找到能围起来面积最大的两个线段。

其中假设两个线段的位置为`i, j(j > i)`，线段的长度分别为`d(i), d(j)`，那么要要找到一个`i, j`，使得`V`最小。

```
V=min(d(i), d(j))*(j - i)
```
###我的解题思路
基本思路是从位置间隔最大开始找起，如果间隔缩小了，要保证新的最小线段比原来的长，面积才有可能比较原来的更大。因此有两个指针分别在数组的开头和结尾，每次把线段长度比较小的那个指针往中间移动，找到一个比原来长度更大的在比较面积，知道两个指针相交，得到的最大面积就为所求的结果。

~~~c++
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

~~~
