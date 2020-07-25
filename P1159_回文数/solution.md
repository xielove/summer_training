# 回文数

## 题目描述

若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。

例如：给定一个10进制数56，将56加65（即把56从右向左读），得到121是一个回文数。

又如：对于10进制数87：<br/>
STEP1：87+78  = 165                  STEP2：165+561 = 726<br/>
STEP3：726+627 = 1353                STEP4：1353+3531 = 4884<br/>
在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

写一个程序，给定一个N（2&lt;=N&lt;=10或N=16）进制数M，其中16进制数字为0-9与A-F，求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible!”

## 解题思路

### 方法一

这里涉及到两个问题，首先是N进制加法，其次是回文数的判断。<br/>

N进制加法：

```cpp
string int2char = "0123456789ABCDEF";
unordered_map<char, int> char2int = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},
};
string add(const string& a, const string& b, int base)
{
    int carry = 0;
    list<char> c;
    auto pa = a.rbegin();
    auto pb = b.rbegin();
    while (pa != a.rend() || pb != b.rend())
    {
        if (pa != a.rend())
        {
            carry += char2int[*pa];
            pa++;
        }
        if (pb != b.rend())
        {
            carry += char2int[*pb];
            pb++;
        }
        c.insert(c.begin(), int2char[carry % base]) ;
        carry /= base ;
    }
    if(carry != 0){
        c.insert(c.begin(), int2char[carry]) ;
    }
    return string(c.begin(), c.end()) ;
}
```

判断回文数

```cpp
bool isPalindromic(const string& s){
    int r = 0;
    int l = s.length()-1;
    while(r <= l){
        if(s[r] != s[l]){
            return false;
        }
        r++;
        l--;
    }
    return true;
}
```

整个程序最多是30次运算，每次运算包括一个N进制加法和一次判断回文数，这两个过程的时间复杂度都与字符串的长度有关。
设初始的字符串长度n，那么假设每次运算都进位，那么最多变成30+n位。

时间复杂度：O(m*n)，m是运算的步数，本题中m = 30
空间复杂度：O(m+n)

#### 代码

```cpp
void solution(string num, int base){
    int step = 0 ;
    while(step <= 30){
        if(isPalindromic(num)){
            cout << "STEP=" << step << endl;
            return;
        }
        string temp(num);
        reverse(temp.begin(), temp.end());
        num = add(num, temp, base);
        step++;
    }
    cout << "Impossible!" << endl;
}
```
