# 绕钉子的长绳子

## 题目描述

平面上给定n个半径为r，且互不相交的园，所有圆心的连线组成一个凸多边形。
现在，使用一根绳子将所有的园围起来，求绳子的周长。

## 解题思路

### 方法一

这个周长包括两个部分，圆与圆之间的切线（直线段），弧线。
可以证明的是：a. 所有的弧线段的长度之和等于一个半径为R的圆的周长(利用弧长公式：L = a * R, a是弧度)
              b. 两个圆的公切线的线段长度等于两个圆的圆心距离
所以这个题目就很简单了，只需要依次求出两个圆之间的距离，这里要注意第一个圆和最后一个圆
最后加上2 * PI * R即可。<br/>

这道题恶心的地方在于不给出PI的值，所谓精确到两位小数，还需要去试探。

时间复杂度：$O(1)$ <br/>
空间复杂度：$O(1)$

#### 代码

```cpp
const auto PI = 3.1415926;
struct Point{
    double x;
    double y;
};
double solution(vector<Point> pos, double radius){
    double ans = 0.0;
    for(int i = 0; i < pos.size(); i++){
        int j = (i+1) % pos.size();
        double x = pos[i].x - pos[j].x;
        double y = pos[i].y - pos[j].y;
        ans += sqrt(x*x + y*y);
    }
    return ans;
}
```
