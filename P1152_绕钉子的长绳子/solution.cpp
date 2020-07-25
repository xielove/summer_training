#include <cstdio>
#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

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
// 题目概括：在平面上存在N个互不相交的半径为R的圆，圆与圆之间使用公切线连接，求这整个图形的外部的周长
// 这个周长包括两个部分，切线（直线段），弧线
// 可以证明的是：a. 所有的弧线段的长度之和等于一个半径为R的圆的周长(利用弧长公式：L = a * R, a是弧度)
//               b. 两个圆的公切线的线段长度等于两个圆的圆心距离
// 所以这个题目就很简单了，只需要依次求出两个圆之间的距离，这里要注意第一个圆和最后一个圆
// 最后加上2 * PI * R即可
int main(int argc, char *argv[])
{
    int size = 0;
    double radus = 0;
    cin >> size >> radus;
    double x0, y0;
    double x1, y1, x2, y2;
    double sum = 0;
    cin >> x1 >> y1;
    x0 = x2 = x1;
    y0 = y2 = y1;
    for(int i = 1; i < size; i++){
        cin >> x2 >> y2;
        sum += sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        x1 = x2;
        y1 = y2;
    }
    sum += sqrt((x0-x2)*(x0-x2) + (y0-y2)*(y0-y2));
    sum += 2 * PI * radus;
    printf("%.2f\n", sum);
    return 0;
}

