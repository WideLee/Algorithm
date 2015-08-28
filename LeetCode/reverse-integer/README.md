##Reverse Integer
2015-08-28 21:52:23


Reverse digits of an integer.

```
Example1: x = 123, return 321
Example2: x = -123, return -321
```

**Have you thought about this?**

- Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

- If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

- Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

- For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

> Tags: `Math`

###题目分析

求一个数反过来，注意边界条件，一个数反过来会overflow

###我的解决方法
注意边界条件，Wrong Answer了一次，一开始以为可以直接通过运算之后的结果是否大于0来判断是否overflow，但一个数乘10之后就算overflow也可能大于0，测试用例里边1534236469就是一个例子。

所以，后来我是用(int_max-n) / 10判断是否溢出。

~~~c++
int reverse(int x) {
    bool sign = true;
    if (x < 0) {
        sign = false;
        x = -x;
    }
    int result = 0;
    while (x > 0) {
        int n = x % 10;
        if (result > (INT_MAX - n) / 10) {
            return 0;
        }
        result = result * 10 + n;
        x /= 10;
    }

    return sign ? result : -result;
}
~~~
