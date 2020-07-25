#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution{
public:
    static unordered_map<char, int> char2int;
    static string int2char;
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
    void solution(){
        int base = 10;
        string num ;
        int step = 0 ;
        cin >> base;
        cin >> num;
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
};

string Solution::int2char = "0123456789ABCDEF";
unordered_map<char, int> Solution::char2int = {
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

int main(int argc, char const *argv[])
{
    Solution so ;
    so.solution() ;
}
