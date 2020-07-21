# 珠心算测验

## 题目描述

集合中存在n个互不相同的数，其中有多少个数，恰好等于集合中另外两个（不同的）数之和？

## 解题思路

### 方法一

使用两重for循环可以计算集合中的任意两个数之和，然后再到集合中查找这个和值。这里要注意到的是如果不同的两个数可以得到相同的和，
因此需要将做好标记，或者从集合中移除这个和。可以考虑使用一个hash表和一个数组，前者用于查找后者可以遍历元素。

时间复杂度：$O(\log(n))$ </br>
空间复杂度：$O(n)$

#### 代码

```cpp

int solution(vector<int> nums){
    unordered_set<int> res(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            int sum = nums[i] + nums[j];
            if(res.find(sum) != res.end()){
                res.earse(sum);
            }
        }
    }
    return size - res.size();
}

```
