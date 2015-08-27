##Longest Palindromic Substring 
2015-08-27 11:43:14

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
>Tags:`String`

###题目分析

寻找一个字符串中出现的最长回文子串。

###我的解决方法

一个很简单的想法，先确定一个位置，然后依次往前和往后对比字符一不一样从而找到回文字符串，理论上这种方法的复杂度是O(n^2).

注意边界条件，如果字符串为空，字符串只有一个字符等情况。

优化方法是跳过相邻的所有相同字符，从而减少大量重复判断的次数。

~~~c++
while (end < s.length() - 1 && s[end] == s[end + 1]) {
    end++;
}
~~~
> **PS：** 测试数据里边有一个1000个‘a’组成的字符串，如果不进行适当优化那就果断TLE了╮(╯_╰)╭

~~~c++
string longestPalindrome(string s) {
    int max_length = 1;
    int min_begin = 0;

    if (s.empty()) {
        return "";
    }
    if (s.length() == 1) {
        return s;
    }

    for (int i = 0; i < s.length(); i++) {
        int begin = i;
        int end = i;

        while (end < s.length() - 1 && s[end] == s[end + 1]) {
            end++;
        }
        i = end;

        while (begin > 0 && end < s.length() - 1 && s[begin - 1] == s[end + 1]) {
            begin--;
            end++;
        }
        if (end - begin + 1 > max_length) {
            max_length = end - begin + 1;
            min_begin = begin;
        }
    }
    return s.substr(min_begin, max_length);
}
~~~


> From: [Simple C++ solution (8ms, 13 lines)](https://leetcode.com/discuss/32204/simple-c-solution-8ms-13-lines)
