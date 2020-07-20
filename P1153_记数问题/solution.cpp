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
        string num;        
        int tar = 0;
        cin >> num >> tar;
        int ans = 0;
        for(auto it : num){
            ans += (it == tar+'0') ? 1 : 0;
        }
        cout << ans << endl;
    }
};

int main() {
    Solution so;
    so.solution();
    return 0;
}
