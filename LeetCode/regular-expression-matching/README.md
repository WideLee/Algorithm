##Regular Expression Matching
2015-09-01 09:46:10

Implement regular expression matching with support for `'.'` and `'*'`.

```
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
```

>Tags:  `Dynamic Programming` `Backtracking` `String`

###题目分析
实现解析简单的正则表达式，只有`'.'`和`'*'`这两个符号，没有`'|'`和括号等。

###我的解题思路
两种解决方法，分别是:

**[使用递归的方法](http://articles.leetcode.com/2011/09/regular-expression-matching.html)**

1. If the next character of p is NOT ‘\*’, then it must match the current character of s. Continue pattern matching with the next character of both s and p.
2. If the next character of p is ‘\*’, then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p… Until we could not match any more characters.

**[使用动态规划的方法](https://leetcode.com/discuss/43860/9-lines-16ms-c-dp-solutions-with-explanations)**

This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

1. P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2. P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
3. P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.



~~~c++

bool isMatch_rev(string s, string p) {
    if (s.length() == 0 && p.length() == 0) {
        return true;
    }

    if (p.length() > 1 && p[1] == '*') {
        int begin = 0;
        while (begin < s.length() && (s[begin] == p[0] || p[0] == '.')) {
            if (isMatch(s.substr(begin + 1, s.length() - begin - 1),
                        p.substr(2, p.length() - 2))) {
                return true;
            }
            begin++;
        }
        return isMatch(s, p.substr(2, p.length() - 2));
    } else {
        return (s.length() != 0) && (s[0] == p[0] || p[0] == '.')
               && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
    }
}

bool isMatch_dp(string s, string p) {
    bool dp[100][100] = {};
    dp[0][0] = true;

    int s_len = s.length();
    int p_len = p.length();

    for (int i = 0; i <= s_len; i++) {
        for (int j = 1; j <= p_len; j++) {
            if (p[j - 1] != '*' && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) {
                dp[i][j] = dp[i - 1][j - 1] && i > 0;
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2]
                           || (i > 0 && dp[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[s_len][p_len];
}
~~~
