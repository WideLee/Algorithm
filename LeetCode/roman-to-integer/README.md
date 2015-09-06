##Roman to Integer 
2015-09-06 19:39:35

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

>Tags: `Math` `String`

###题目分析

把罗马数字转换成数字。

###我的解题思路

由于罗马数字字母表示的数通过加减法进行运算，如果当前罗马字母表示的数比下一位表示的数小，那需要进行减法，否则进行加法。

~~~c++
 int romanToInt(string s) {
    int roman[26];
    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;

    int result = 0;
    int length = s.length();
    for (int i = 0; i < length - 1; i++) {
        if (roman[s[i] - 'A'] >= roman[s[i + 1] - 'A']) {
            result += roman[s[i] - 'A'];
        } else {
            result -= roman[s[i] - 'A'];
        }
    }

    result += roman[s[length - 1] - 'A'];

    return result;
}
~~~
