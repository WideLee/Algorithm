##Longest Common Prefix

2015-09-07 10:48:57

Write a function to find the longest common prefix string amongst an array of strings.

> Tags: `String`

###题目分析
找到一个字符串数组中最长的公共前缀。

###我的解决方法
遍历数组依次对比最长公共子串，题目不难，不过我记录最长子串的位置最后在用substr提取出来的方法用了12ms似乎有点长。

~~~c++
string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
        return "";
    }
    unsigned long longest = strs[0].length();

    for (int i = 1; i < strs.size(); i++) {
        unsigned long index = 0;
        while (index < strs[i].length()
               && index < longest
               && strs[i][index] == strs[0][index]) {
            index++;
        }
        longest = index;
    }

    return strs[0].substr(0, longest);
}
~~~

###更好的解决方法

每次都遍历数组，查看相应位置的字符是否一样，这样要注意边界条件，得到的运行时间为4ms

~~~c++
string longestCommonPrefix(vector<string> &strs) {
    string longest;
    int index = 0;
    int size = strs.size();
    if (size == 0) {
        return longest;
    }
    while (true) {
        if (index == strs[0].length()) {
            return longest;
        }
        char c = strs[0][index];
        for (int i = 1; i < size; i++) {
            if (index == strs[i].length() || strs[i][index] != c) {
                return longest;
            }
        }
        index++;
        longest += c;
    }
}
~~~
