##Isomorphic Strings 
2015-08-04 08:37:48

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. ==No two characters may map to the same character but a character may map to itself.==

For example,
Given`"egg"`, `"add"`, return true.

Given `"foo"`, `"bar"`, return false.

Given `"paper"`, `"title"`, return true.

**Note:**
You may assume both s and t have the same length.

>Tags: `Hash Table`

###题目分析
判断两个字符串是否同构，其实就是找到一个一一对应的对应关系，使得A字符串的每个不同的字母都能对应到B字符串当中，注意不能对应到同一个字母，也就是说A和B同构反过来也要B和A同构。

###我的解决方法
使用一个哈希表存储字符的对应关系，还有一个数组存储一个字符是否已经被对应过。第一次提交Wrong Answer，注意“ab”和“aa”这两个字符串***不是***同构的。

~~~c++
bool isIsomorphic(string s, string t) {
    char map_table[128] = {};
    bool is_matched[128] = {};
    if (s.length() != t.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        char d = map_table[c];
        if (d == 0) {
            if (is_matched[t[i]]) {
                return false;
            } else {
                map_table[c] = t[i];
                is_matched[t[i]] = true;
            }
        } else {
            if (d != t[i]) {
                return false;
            }
        }
    }

    return true;
}
~~~

###更好地解决方法
据说0ms…使用两个哈希表，就不需要记录is_matched了

~~~c++
bool isIsomorphic(char* s, char* t) {
    char charArrS[256] = { 0 };
    char charArrT[256] = { 0 };
    int i = 0;
    while (s[i] !=0)
    {
        if (charArrS[s[i]] == 0 && charArrT[t[i]] == 0)
        {
            charArrS[s[i]] = t[i];
            charArrT[t[i]] = s[i];
        }
        else
        if (charArrS[s[i]] != t[i] || charArrT[t[i]] != s[i])
            return false;
        i++;
    }

    return true;
}
~~~
