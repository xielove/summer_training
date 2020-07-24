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
        vector<int> nums(size);
        for(auto &it : nums){
            cin >> it;
        }
        cout << solution(nums) << endl;
    }
    int solution(vector<int>& nums){
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
};

int main() {
    Solution so;
    so.solution();
    return 0;
}

