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
    void solution(){
        unordered_set<int> s;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int t = 0;
            cin >> t;
            s.insert(t);
        }
        vector<int> v(s.begin(), s.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int num = v[i]+v[j];
                if(s.find(num) != s.end()){
                    s.erase(num);
                }
            }
        }
        cout << n - s.size() << endl;
    }

};

int main(int argc, char const *argv[])
{
    Solution so ;
    so.solution() ;
}
