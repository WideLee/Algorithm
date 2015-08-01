##Happy Number
2015-08-02 01:15:45

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

>**Example**: 19 is a happy number 
>
>```
>1^2 + 9^2 = 82 
>8^2 + 2^2 = 68
>6^2 + 8^2 = 100
>1^2 + 0^2 + 0^2 = 1
>```

>Tags: `Hash Table` `Math`

###题目分析
找到Happy Number，每一位数的平方和最后的结果为1

###我的解题思路
很容易发现int范围内经过一次运算的到的结果都不会超过1000，因此使用一个1000的bool数组记录是否产生循环，然后不断进行运算直到产生循环或者最后结果为1。

~~~c++
bool isHappy(int n) {
    if (n <= 0) {
        return false;
    }

    bool isVisited[1000] = {};
    int val = n;
    while (true) {
        val = sumOfNum(val);
        if (val == 1) {
            return true;
        }
        if (isVisited[val]) {
            return false;
        }
        isVisited[val] = true;
    }
}

int sumOfNum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
~~~

###更好地解决方法
摘自[https://leetcode.com/discuss/42436/short-4ms-c-solution](https://leetcode.com/discuss/42436/short-4ms-c-solution)


证明了任何一个数，如果是Happy number，那么会收敛到1，如果不是，那么会经过4, 16, 37, 58, 89, 145, 42, 20, 4, ...这样的循环，因此可以判断每位数的平方和是否等于4来判断是否Happy。

~~~c++
bool isHappy(int n) {
    while (true) {
        if (n == 1) { return true; }
        if (n == 4) { return false; }
        int next = 0;
        while (n) { 
            next += (n % 10) * (n % 10), n /= 10; 
        }
        n = next;
    }    
}
~~~

证明如下：
> From Wiki, in case you have not seen it: If n is not happy, then its sequence does not go to 1. Instead, it ends in the cycle:

> 4, 16, 37, 58, 89, 145, 42, 20, 4, ... To see this fact, first note that if n has m digits, then the sum of the squares of its digits is at most 9^2 m, or 81m.

> For m=4 and above,

> n\geq10^{m-1}>81m so any number over 1000 gets smaller under this process and in particular becomes a number with strictly fewer digits. Once we are under 1000, the number for which the sum of squares of digits is largest is 999, and the result is 3 times 81, that is, 243.

> In the range 100 to 243, the number 199 produces the largest next value, of 163. In the range 100 to 163, the number 159 produces the largest next value, of 107. In the range 100 to 107, the number 107 produces the largest next value, of 50. Considering more precisely the intervals [244,999], [164,243], [108,163] and [100,107], we see that every number above 99 gets strictly smaller under this process. Thus, no matter what number we start with, we eventually drop below 100. An exhaustive search then shows that every number in the interval [1,99] either is happy or goes to the above cycle.

> The above work produces the interesting result that no positive integer other than 1 is the sum of the squares of its own digits, since any such number would be a fixed point of the described process.

> There are infinitely many happy numbers and infinitely many unhappy numbers. Consider the following proof:

> 1 is a happy number, and for every n, 10n is happy since its sum is 1 and for every n, 2 × 10n is unhappy since its sum is 4 and 4 is an unhappy number.
