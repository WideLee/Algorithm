##Length of Last Word
2015-08-04 08:48:43

Given a string s consists of upper/lower-case alphabets and empty space characters `' '`, return the length of last word in the string.

If the last word does not exist, return 0.

**Note**: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = `"Hello World"`,
return `5`.

>Tags: `String`

###题目分析
找到一个字符串中最后一个单词的长度

###我的解决方法
> Wrong Answer了两次，注意边界条件

遍历字符串，如果是空格，重置单词长度，如果长度不为0，则把单词长度保存下来，如果是字母则单词长度+1。

> 现在想想，似乎可以从字符串尾开始遍历起，遇到第一个不是空格的字符开始，直到开头或空格。

~~~c++
int lengthOfLastWord(string s) {
    int result = 0;
    int length = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if(length != 0) {
                result = length;
            }
            length = 0;
        } else {
            length++;
        }
    }
    if(length != 0) {
        result = length;
    }
    return result;
}
~~~

###更好地解决方法
评论区里果然有从字符串尾部开始遍历起得方法，如下：

~~~c
int lengthOfLastWord(const char *s) {
    while(*s) s++;
    s--;
    while(*s == ' ') s--;
    int len = 0;
    while (*s) {
        if (*s == ' ') {
            break;
        }
        else if (*s-- != ' ') len++;
    }
    return len;
}
~~~

我的C++实现方法如下：

~~~c++
int lengthOfLastWord(string s) {
    int result = 0;
    int length = s.length();
    for(int i = length - 1; i >= 0; i--) {
        if(s[i] == ' ') {
            if(result == 0) {
                continue;
            } else {
                break;
            }
        }
        
        result ++;
    }
    return result;
}
~~~
