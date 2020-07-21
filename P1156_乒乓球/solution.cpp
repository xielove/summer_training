#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 每个输入文件包含若干行字符串（每行至多20个字母），
// 字符串有大写的W、L和E组成,也许中间有若干个空格。
// 其中E表示比赛信息结束，程序应该忽略E之后的所有内容,E后面可能有干扰文字。

class Solution{
public:
    void solution(){
        char ch;
        int li, wi, lj, wj;
        li = lj = wi = wj = 0;
        int ni = 11, nj = 21;
        stringstream outi, outj;
        while((ch = cin.get()) != 'E'){
            if(ch != 'W' && ch != 'L'){
                continue;
            }else if(ch == 'W'){
                wi++;
                wj++;
            }else if(ch == 'L'){
                li++;
                lj++;
            }
            if((wi >= 11 || li >= 11 ) && abs(wi-li) >= 2){
                outi << wi << ":" << li << endl;
                wi = li = 0;
            }
            if((wj >= 21 || lj >= 21 ) && abs(wj-lj) >= 2){
                outj << wj << ":" << lj << endl;
                wj = lj = 0;
            }
        }
        outi << wi << ":" << li << endl;
        wi = li = 0;
        outj << wj << ":" << lj << endl;
        wj = lj = 0;
        cout << outi.str() << endl;
        cout << outj.str() ;
    }
};

int main(int argc, char const *argv[])
{
    Solution so ;
    so.solution() ;
}
