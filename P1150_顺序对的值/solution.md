# 顺序对的值

## 题目描述

给定一个序列a，a中任意两个元素都不等。如果i&lt;j,且a[i]&lt;a[j]，则我们称a[i],a[j]为一个顺序对，
这个顺序对的值是指a[i+1],a[i+2]…….a[j-1]中比a[i]大，且比a[j]小的数的个数。求一个序列中所有顺序对的值的和。

## 解题思路

### 方法一：暴力算法

用两个循环遍历整个序列，假设下标为i，j。对于每一对a[i]和a[j]，再使用一个循环去寻找比a[i]大，且比a[j]小的数。

时间复杂度：$O(n^3)$ <br/>
空间复杂度：$O(1)$

#### 代码

```cpp
int solution(vector<int> nums){
    int i, j, k;
    int ans = 0;
    for(i = 0; i < nums.size(); i++){
        for(j = i+1; j < nums.size(); j++){
            for(k = i+1; k < j; k++){
                if(a[k] > a[i] && a[k] < a[j]){
                    ans++;
                }
            }
        }
    }
    return ans;
}
```

### 方法二

暴力算法的时间复杂度太高，基本上不可能AC，那么现在考虑这么一种情况，对于序列中的每一个数a\[k\](0 &lt;= k &lt; n)，
在a[0]~a[k-1]之间比a[k]小的数的个数为l，在a[k+1]~a[n-1]之间考虑比a[k]大的数的个数r，那么a[k]作为某个区间[i, j]的顺序对中
比a[i]大的数，且比a[j]小的数。这样的区间一共是l*r个。

时间复杂度：$O(n)$ <br/>
空间复杂度：$O(1)$

#### 代码

```cpp
int solution(vector<int> nums){
    int i, j;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        int l = 0, r = 0;
        for(j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                l++;
            }
        }
        for(j = i+1; j < nums.size(); j++){
            if(nums[j] > nums[i]){
                r++;
            }
        }
        ans += l * r;
    }
    return ans;
}

```
