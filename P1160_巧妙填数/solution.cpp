#include <iostream>
#include <sstream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution{
public:
    bool check(int num){
        int x1 = num, x2 = num * 2, x3 = num * 3;
        if(x3 > 987){
            return false;
        }
        // 默认初始化，hash : {1, 0, 0...}
        // 当数字5出现在x1中，x2中会出现0
        int hash[10] = {1};
        int digit = 0;
        stringstream ss;
        ss << x1 << x2 << x3;
        for(auto ch : ss.str()){
            if(hash[ch-'0'] != 0)
                return false;
            hash[ch-'0'] = 1;
        }
        return true;
    }
    void solution(){
        for(int i = 123; i <= 329; i++){
            if(check(i)){
                cout << i << " " << i * 2 << " " << i * 3 << endl;
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution so ;
    so.solution() ;
}
