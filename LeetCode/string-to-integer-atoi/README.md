##String to Integer (atoi)  
2015-08-28 23:33:37 

Implement atoi to convert a string to an integer.

**Hint:** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

**Notes:** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

**Update (2015-02-10):**
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

**Requirements for atoi:**
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT\_MAX (2147483647) or INT\_MIN (-2147483648) is returned.

>Tags: `Math` `String`


###题目分析
模拟实现C语言的atoi函数，与原atoi不一样的地方是如果出现overflow，原atoi不进行处理，而这个输出INT\_MAX或INT\_MIN。

**注意：**

- 会出现'+'、'-'这两个符号
- 忽略字符串前的空格
- 在转换过程中遇到非数字字符，那么转换结束
- 边界条件！overflow

###我的解题思路

算是Wrong Answer了好多次了，之前一直没处理好那些INT\_MIN或INT\_MAX附近的值，没想清楚INT\_MIN的绝对值比INT\_MAX大1，后来采用的方法是先把结果存成double型，然后判断起来就比较方便了。最后Accept之后的用时是12ms。

~~~c++
int myAtoi(string str) {
    double result = 0;
    bool is_begin = false;
    bool sign = true;
    bool overflow = false;
    for (int i = 0; i < str.length(); i++) {
        if (!is_begin && str[i] == ' ') {
            continue;
        } else if (!is_begin && (str[i] == '+' || str[i] == '-')) {
            is_begin = true;
            sign = (str[i] != '-');
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            is_begin = true;
            result = result * 10 + (str[i] - '0');
            overflow = !((sign && result < INT_MAX)
                       || (!sign && result > INT_MIN));
        } else {
            break;
        }
    }
    if (overflow) {
        return sign ? INT_MAX : INT_MIN;
    } else {
        return sign ? result : -result;
    }
}
~~~
###更好地解决方法
运行时间8ms更简洁的代码，参考[8ms C++ solution, easy to understand](https://leetcode.com/discuss/39709/8ms-c-solution-easy-to-understand)

~~~c++
int myAtoi(string str) {
    long result = 0;
    int indicator = 1;
    for(int i = 0; i<str.size();)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
        while('0'<= str[i] && str[i] <= '9') 
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT_MAX) return INT_MAX;
            if(result*indicator <= INT_MIN) return INT_MIN;                
        }
        return result*indicator;
    }
}
~~~
