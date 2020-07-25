#include <iostream>
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
    void readSudoku(vector<vector<int>>& sudoku){
        int len = 9;
        sudoku.resize(len);
        for(auto &row: sudoku){
            row.resize(len);
            for(auto &num : row){
                cin >> num;
            }
        }
    }
    void solution(){
        int n = 0;
        cin >> n;
        vector<vector<int>> sudoku(n);
        vector<bool> ans(n);
        for(int i = 0; i < n; i++){
            readSudoku(sudoku);
            bool valid = checkSudoku(sudoku);
            ans[i] = valid;
        }
        for(auto valid : ans)
            cout << (valid ? "Right" : "Wrong") << endl;
        
    }
};


int main(int argc, char const *argv[])
{
    Solution so ;
    so.solution() ;
}

