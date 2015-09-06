##Integer to Roman
2015-09-06 09:56:29

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

>Tags: `Math` `String`


###题目分析

把一个1-3999以内的数转换为罗马数字，罗马数字表示有如下关系：

| 数字 | 罗马字 | 数字 | 罗马字 |
|:----:|:---:|:-----:|:-----:| 
| 1 | I | 40 | XL |
| 2 | II | 99 | XCIX |
| 4 | IV | 100 | C |
| 5 | V | 400 | CD |
| 9 | IX | 500 | D |
| 10 | X | 900 | CM |
| 19 | XIX | 1000 | M |
| 20 | XX | 3000 | MMM |

> 对应规则：[规则](http://www.mathland.idv.tw/history/roman.htm)
> 
> 1. 重复数次决定倍数：1个罗马数字重复几次，就表示这个数的几倍。例如: ⅩⅩⅩ=30.
> 2. 右加左减：在一个较大的罗马数字的右边记上一个较小的罗马数字，表示大数字加小数字。
在一个较大的数字的左边记上1个较小的罗马数字，表示大数字减小数字。
但是，左减不能跨越一个位数。比如，99不可以用IC表示，而是用XCIX表示。此外，左减数字不能超过1位，比如8写成VIII，而非IIX。同理，右加数字不能超过3位，比如14写成XIV，而非XIIII。
> 3. 数字上加横线乘千或乘百万：在1个罗马数字的上方加上1条横线或者在右下方写M，表示将这个数字乘以1000，即是原数的1000倍。同理，如果上方有2条横线，即是原数的1000000倍。
> 4. 数码限制：同样数码最多只能出现3次，如40不能表示为XXXX，而要表示为XL。但是，由于IV是古罗马神话主神朱庇特（IVPITER，古罗马字母没有J和U）的首字，因此有时用IIII​​代替IV。一般大时钟(不包刮英国大笨钟)的时刻就以IIII代替IV，也可能是为了字体的对称性。


###我的解决方法
一个非常丑陋的解决方法，但速度还算挺快的。

从千位开始，如果大于1000就加上一个M，然后分别判断900，500，400，然后处理百位，以此类推。

~~~c++
string intToRoman_bad(int num) {
    string roman;
    if (num >= 4000) {
        return roman;
    }
    while (num >= 1000) {
        roman += "M";
        num -= 1000;
    }

    if (num >= 900) {
        roman += "CM";
        num -= 900;
    } else if (num >= 500) {
        roman += "D";
        num -= 500;
    } else if (num >= 400) {
        roman += "CD";
        num -= 400;
    }

    while (num >= 100) {
        roman += "C";
        num -= 100;
    }

    if (num >= 90) {
        roman += "XC";
        num -= 90;
    } else if (num >= 50) {
        roman += "L";
        num -= 50;
    } else if (num >= 40) {
        roman += "XL";
        num -= 40;
    }

    while (num >= 10) {
        roman += "X";
        num -= 10;
    }

    if (num >= 9) {
        roman += "IX";
        num -= 9;
    } else if (num >= 5) {
        roman += "V";
        num -= 5;
    } else if (num >= 4) {
        roman += "IV";
        num -= 4;
    }

    while (num >= 1) {
        roman += "I";
        num -= 1;
    }

    return roman;
}

~~~

以上代码有点长，重复的代码也有点多，可以提取出来成函数简化代码。

###更好地解决方法
一个更简单可扩展的解决方法，很好地把每个数码的表示方式分开。

~~~c++
string intToRoman_better(int num) {
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
}
~~~
