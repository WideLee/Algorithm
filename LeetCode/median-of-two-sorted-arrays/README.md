##Median of Two Sorted Arrays
2015-08-25 08:37:46


There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

>Tags： `Divide and Conquer` `Array` `Binary Search`


###题目分析
给定两个已经排好序的数组，找到这两个数组的中位数。该算法也可以扩展到找到这个数组的第k大的数。

###我的解决方法

使用归并排序，把这两个排好序的数组合并成一个排好序的大数组，然后直接找到该数组的中位数。这种方法的算法复杂度是O(m+n)，属于线性复杂度也是可以接受的。

~~~c++
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
~~~

###更好的解决方法
原文：[share my o(log(min(m,n)) solution with explanation](https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation)

大致的思路是使用二分查找，把两个数组分成四部分

```
           LeftPart            |            RightPart 
{ A[0], A[1], ... , A[i - 1] } | { A[i], A[i + 1], ... , A[m - 1] }
{ B[0], B[1], ... , B[j - 1] } | { B[j], B[j + 1], ... , B[n - 1] }
```
然后使得这个划分满足

```
1) LeftPart's length == RightPart's length (or RightPart's length + 1)

2) All elements in RightPart are greater than elements in LeftPart.
```

这样的算法复杂度为O(log(min(m,n)))

**注意边界条件！！Debug了好久= =**

~~~c++
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
~~~
