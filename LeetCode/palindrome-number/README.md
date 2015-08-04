##Palindrome Number 
2015-08-04 09:21:45

Determine whether an integer is a palindrome. Do this without extra space.

**Some hints:**

- Could negative integers be palindromes? (ie, -1)

- If you are thinking of converting the integer to string, note the restriction of using extra space.

- You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

- There is a more generic way of solving this problem.

>Tags： `Math`

###题目分析
判断一个数是否是回文数，不能使用另外的空间，指的是不能转化为字符串之后再比对。

###我的解决方法
每次通过数学把最高位和最低位找出来判断是否相等。
> 本来很简单，Wrong Answer了好多次…

**注意：**

1. 负数都不是回文数
2. -2147483648 取相反数之后不是 2147483648，会溢出
3. 各种边界条件都要注意，例如结束条件是x < 10 && p < 9 等等

自己的代码太丑就不贴上来了


###更好的解决方法
构建一个新的数，使得新数的最高位等于原数的最低位，如果这两个数相等那么说明原来的是回文数。

~~~c++
bool isPalindrome(int x) {
    if(x<0|| (x!=0 &&x%10==0)) return false;
    int sum=0;
    while(x>sum)
    {
        sum = sum*10+x%10;
        x = x/10;
    }
    return (x==sum)||(x==sum/10);
}

~~~
