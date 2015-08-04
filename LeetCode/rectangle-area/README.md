##Rectangle Area
2015-08-04 09:58:01

Find the total area covered by two **rectilinear** rectangles in a **2D** plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

![](https://leetcode.com/static/images/problemset/rectangle_area.png)

Assume that the total area is never beyond the maximum possible value of `int`.

> Tags: `Math`

###题目分析
求两个矩形组成的总面积

###我的解决方法
本来还想通过Bitmap的方法，但后来想想范围太大了内存空间不够了，然后就想到纯数学的计算方法，先计算两个矩形的面积，然后减掉他们相交矩形的面积得到最后的总面积。

**Attention:**

提交的时候Wrong Answer了一组测试数据，注意计算过程中int的溢出，后来的解决方法是先强制转换成double再进行计算。

~~~c++
cout << sol.computeArea(
    -1500000001, 0, 
    -1500000000, 1, 
     1500000000, 0,
     1500000001, 1) << endl;
~~~
