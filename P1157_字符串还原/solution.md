# 字符串还原

## 题目描述

一个长度为n的由小写字母组成的字符串$s_1~s_2~\cdots~s_n~$按如下方式加密成3种形式：<br/>

1. 将字符串翻转，即对于每一个$1\le i\le n~$来说，$s_i~$与$s_{n-i+1}~$对换。
2. 将字符串中每个字母变为其之后第k个字母，定义z之后的字母为a，其中$0 ≤ k ≤ 6$且为未知数。
3. 将字符串中每个字母变为其之前第k个字母，定义a之前的字母为z，k同2所述。

例如字符串abcd按上面3种方式加密后，在$k = 1$的情况下会依次变为：<br/>

1. dcba
2. bcde
3. zabc

现给出信中按以上3种形式分别加密后的3个字符串（不一定按上述例子的顺序），要求还原原来的字符串，并输出告诉小K。


## 解题思路

### 方法一

暴力解法：设字符串为A，B，C，则对于任意一个字符串S，假定其经过第一种变换，将S翻转得到原来的字符串，然后遍历$-6 &lt;= k &lt;= 6$，比对剩下的两个字符串。

时间复杂度: $O(n*k)$
空间复杂度: $O(1)$

#### 代码

```cpp
string solution(vector<string> data, int size){
    int num = 3;
    for(int i = 0; i < num; i++){
        string a = data[i];
        reverse(a.begin(), a.end());
        string &ls = data[(i+1)%num];
        string &rs = data[(i+2)%num];
        for(int j = -6; j <= 6; j++){
            bool flag = true;
            for(int k = 0; k < size; k++){
                if(shift(a[k], j) != ls[k] || shift(a[k], -j) != rs[k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return a;
            }
        }
    }
    return "";
}
```
