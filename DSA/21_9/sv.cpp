#include <iostream>

using namespace std;

class SV
{
public:
    string _name;
    int _age, _gpa;
    SV(string name, int age, int gpa)
    {
        this->_age = age;
        this->_name = name;
        this->_gpa = gpa;
    }

    
};

ostream &operator<<(ostream &os, SV sv)
{

}

istream &operator>>(istream &is, SV &sv)
{
    
}

int main()
{
    fstream;
    
    return 0;
}