##ZigZag Conversion 
2015-08-04 10:38:09


The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: `"PAHNAPLSIIGYIR"`
Write the code that will take a string and make this conversion given a number of rows:

~~~c++
string convert(string text, int nRows);
~~~

`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

> Tags: `String`


###题目分析
题目描述得不是很清楚，如果`nRows=4`，那么转换的形状如下：

```
A       G
|     / |
B    F  H
|   /   |
C  E    I
| /
D
```
转换后的字符串就是`"AGBFHCEID"`

###我的解决方法
其中`2n-2`个字符可以为一组，然后一行一行从相应位置取出字符，由于第一行和最后一行都是只有一个数，因此单独处理。

**注意：**

如果`numRows = 1`，按照之前的处理方法会因为`k = 0`出现死循环，，所以要单独出来特殊处理。

~~~c++
string convert(string s, int numRows) {
    string cons;

    if(numRows > 1) {
        int k = 2 * (numRows - 1);

        int cur = 0;
        while (cur < s.length()) {
            cons += s[cur];
            cur += k;
        }

        for (int i = 1; i < numRows - 1; i++) {
            cur = i;
            while (cur < s.length()) {
                cons += s[cur];
                int next = cur + k - 2 * i;
                if (next < s.length()) {
                    cons += s[next];
                }
                cur += k;
            }
        }

        cur = numRows - 1;
        while (cur < s.length()) {
            cons += s[cur];
            cur += k;
        }
    } else {
        cons = s;
    }

    return cons;
}
~~~
