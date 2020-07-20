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
        int num = 0, x = 0;
        cin >> num >> x;
        int ans = 0;
        for(int i = 1; i <= num; i++){
            int j = i;
            while(j != 0){
                if(j % 10 == x){
                    ans++;
                }
                j /= 10;
            }
        }
        cout << ans << endl;
    }
};

int main() {
    Solution so;
    so.solution();
    return 0;
}
