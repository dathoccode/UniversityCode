#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Polynomial
{
private:
    int n;
    double *buff;
public:
    Polynomial();
    Polynomial(int n, double *a);
    Polynomial(const Polynomial &p);
    ~Polynomial();
    friend ostream &operator << (ostream &os, Polynomial pln);
    friend istream &operator >> (istream &is, Polynomial &pln);
    friend Polynomial &operator + (Polynomial p1, Polynomial p2);
    friend Polynomial &operator - (Polynomial p1, Polynomial p2);

};

Polynomial::Polynomial()
{

}

Polynomial::Polynomial(int n, double *a)
{
    this->n = n;
    this->buff = new double[n];
    this->buff = a;
}
 
Polynomial::Polynomial(const Polynomial &p)
{
    this->n = p.n;
    this->buff = p.buff;
}

Polynomial::~Polynomial()
{

}

ostream &operator << (ostream &os, Polynomial pln)
{
    os << "[";
    for(int i = 0; i <= pln.n ; i++)
    {
        os << pln.buff[i] << " ";
    }
    os << "]";
    return os;
}

istream &operator >> (istream &is, Polynomial &p)
{
    cout << "nhap bac: ";
    is >> p.n;
    p.buff = new double[p.n];
    cout << "nhap cac he so: ";
    for(int i = 0; i <= p.n; i++)
    {
        is >> p.buff[i];
    }
    return is;
}

Polynomial &operator + (Polynomial p1, Polynomial p2)
{
    if(p1.n > p2.n) return p2 + p1;
    Polynomial res(p2.n, NULL);
    int gap = p2.n - p1.n;
    for(int i = 0; i < gap; i++)
    {
        res.buff[i] = p2.buff[i];
    }
    for(int i = 0; i < p1.n; i++)
    {
        res.buff[i + gap] = p1.buff[i] + p2.buff[i + gap];
    }
    return res;
}


int main()
{
    Polynomial p1,p2,p3;
    cin >> p1 >> p2;
    cout << p1 << p2;
    p1 + p2;
    return 0;
}