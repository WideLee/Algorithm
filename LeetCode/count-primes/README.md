##Count Primes 
2015-08-02 01:06:16

Count the number of prime numbers less than a non-negative number, n.

>Tags: `Hash Table` `Math`

###题目分析
计算n以内的素数的个数。

###我的解题思路
使用[Sieve of Eratosthenes](http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)方法，删掉所有素数的倍数剩下来的就是素数。

~~~c++
int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j = 2; j <= n / i; j++) {
                isPrime[i * j] = false;
            }
        }
    }
    return count;
}
~~~

###注意事项
1. 由于n的范围题目没有给出，第一次提交的时候数组大小开得太小了导致Runtime Error，最好的方法是使用vector动态设置数组大小，这样可以初始化数组为`true`，但这样耗时比较长。
