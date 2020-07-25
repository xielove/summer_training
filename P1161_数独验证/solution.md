# 数独验证

## 题目描述

数独规则如下:<br/>
每一行都用到1,2,3,4,5,6,7,8,9，位置不限，<br/>
每一列都用到1,2,3,4,5,6,7,8,9，位置不限，<br/>
每3×3的格子（共九个这样的格子）都用到1,2,3,4,5,6,7,8,9，位置不限，<br/>
游戏的过程就是用1,2,3,4,5,6,7,8,9填充空白，并要求满足每行、每列、每个九宫格都用到1,2,3,4,5,6,7,8,9。

输入一个9×9的数字矩阵，判断这是不是一个数独，如果是则输出Right，否则输出Wrong。

## 解题思路

### 方法一

将数独的每行，每列，每个九宫格存入一个数组中，只需要判断这个数组中没有重复元素就可以了。

时间复杂度：$O(n^2)$
空间复杂度：$O(n)$

#### 代码

```cpp
bool valid(vector<int>& nums){
    set<int> check(nums.begin(), nums.end());
    return check.size() == 9;
    // int hash[9] = {0};
    // for(auto n : nums){
    //     if(hash[n-1] != 0){
    //         return false;
    //     }
    //     hash[n-1] = 1;
    // }
    // return true;
}
bool checkSudoku(vector<vector<int>>& sudoku){
    for(auto &row : sudoku){
        if(!valid(row)) return false;
    }
    int len = 9;
    vector<int> col(len);
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            col[j] = sudoku[j][i] ;
        }
        if(!valid(col)) return false;
    }
    vector<vector<int>> bak(9);
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            bak[(i/3*3+j/3)].push_back(sudoku[i][j]);
        }
    }
    for(auto &row : bak){
        if(!valid(row)) return false;
    }
    return true;
}
```
