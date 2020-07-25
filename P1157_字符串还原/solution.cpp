#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void solution() {
        int size = 0;
        cin >> size;
        int num = 3;
        vector<string> data(num);
        for(auto &str : data){
            cin >> str;
        }
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
                    cout << "k = " << j << endl;
                    cout << a << endl;
                    return ;
                }
            }
        }
    }
    inline char shift(char ch, int offset){
        return 'a' + (ch-'a' + offset + 26) % 26;
    }
};

int main() {
    Solution so;
    so.solution();
    //while(true){
        //char ch ;
        //int offset;
        //cin >> ch >> offset;
        //char re = so.shift(ch, offset);
        //cout << so.shift(ch, offset) << endl;
        //printf("%d\n", re);
    //}
    return 0;
}
