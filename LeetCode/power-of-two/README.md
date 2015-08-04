##Power of Two
2015-08-04 09:42:05

Given an integer, write a function to determine if it is a power of two.

> Tags:  `Math` `Bit Manipulation`

###题目分析
判断一个数是否是2的倍数

###我的解决方法
说是O(1)的时间，因为int范围内2的倍数也只有31个，通过右移操作得到这31个2的倍数，然后一一判断是否相等。

~~~c++
bool isPowerOfTwo(int n) {
    if(n <= 0) {
       return false;
    }
    int pow = 1;
    for(int i = 0; i < 31; i++) {
       if(n == pow) {
           return true;
       }
       pow <<= 1;
    }
    return false;
}
~~~

###更好的解决方法
一行代码，不解释→_→

~~~c++
bool isPowerOfTwo(int n) {
    return (n > 0) && !(n & (n - 1));
}
~~~


