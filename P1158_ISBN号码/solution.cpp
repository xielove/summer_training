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
        string isbn;
        cin >> isbn;
        int identiy = 0;
        int num = 1;
        for(int i = 0; i < isbn.length()-1; i++){
            if(isbn[i] != '-'){
                identiy += (isbn[i] - '0') * num;
                num++;
            }
        }
        identiy = identiy % 11;
        char verify = (identiy == 10) ? 'X' : (identiy + '0');
        if(verify == isbn[isbn.length()-1]){
            cout << "Right" << endl;
        }else{
            isbn[isbn.length()-1] = verify;
            cout << isbn << endl;
        }
    }

};

int main(int argc, char const *argv[])
{
    Solution so ;
    so.solution() ;
}
