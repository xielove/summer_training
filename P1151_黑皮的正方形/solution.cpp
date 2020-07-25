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
        unsigned long long n = 0;
        cin >> n;
        unsigned long long ans = 0;
        ans = n * (n+1)*(2*n+1) / 6;
        cout << ans << endl;
    }
};

int main() {
    Solution so;
    so.solution();
    return 0;
}
