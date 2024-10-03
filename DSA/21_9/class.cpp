#include <iostream>
#include <vector>
#include "sv.cpp"
#include <map>

using namespace std;

class LopHoc
{
public:
    vector<SV> lop;
    double dtb()
    {
        int tmp = 0; 
        for(auto s:lop)
        {
            tmp += s._gpa;
        }
        return tmp ? tmp/lop.size():0;
    }

    ostream &operator<<(ostream &os, LopHoc L)
    {
        for(auto s:L.lop) os << s;
        return os;
    }

    void thongke()
    {
        map<int, int> m;
        for(auto s:lop)
        {
            m[s._age]++;
        }
        for(auto a:m)
        {
            cout << "tuoi: " << a.first << " - si so:" << a.second << endl;
        }
    }

};

int main()
{

    return 0;
}