#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Student{
private:
    string name;
    int finalExam;
    int classEval;
    bool iscadre;
    bool iswest;
    int papers;

public:
    Student(string n, int f, int c, bool cadre, bool west, int p):
        name(n), finalExam(f), classEval(c), iscadre(cadre), iswest(west), papers(p){

        }
    string getName(){return name;}
    int evalScholar(){
        int sum = 0;
        if(finalExam > 80 && papers >= 1) sum += 8000;
        if(finalExam > 85 && classEval > 80) sum += 4000;
        if(finalExam > 90) sum += 2000;
        if(finalExam > 85 && iswest) sum += 1000;
        if(classEval > 80 && iscadre) sum += 850;
        return sum;
        
    }
};

class Solution{
public:
    void solution(){
        int n;
        cin >> n;
        vector<Student> data;
        int imax = 0;
        int vmax = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            string name;
            int fe, ce, pa;
            char ca, we;
            cin >> name >> fe >> ce >> ca >> we >> pa;
            data.emplace_back(Student{name, fe, ce, ca == 'Y', we == 'Y', pa});
            int v = data[i].evalScholar();
            if(v > vmax){
                vmax = v;
                imax = i;
            }
            sum += v;
        }
        cout << data[imax].getName() << endl;
        cout << vmax << endl;
        cout << sum << endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution so ;
    so.solution() ;
}
