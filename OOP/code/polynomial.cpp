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
    Polynomial(int n);
    Polynomial(const Polynomial &p);
    ~Polynomial();
    friend ostream &operator << (ostream &os, Polynomial pln);
    friend istream &operator >> (istream &is, Polynomial &pln);
    friend Polynomial operator + (Polynomial p1, Polynomial p2);
    friend Polynomial &operator - (Polynomial p1, Polynomial p2);
    Polynomial &operator = (Polynomial p);

};

Polynomial::Polynomial()
{

}

Polynomial::Polynomial(int n)
{
    this->n = n;
    this->buff = new double[n+1];
}
 
Polynomial::Polynomial(const Polynomial &p)
{
    this->n = p.n;
    this->buff = new double[this->n + 1];
    for(int i = 0; i <= n; i++)
    {
        this->buff[i] = p.buff[i];
    }
}

Polynomial::~Polynomial()
{

}

Polynomial  &Polynomial::operator = (Polynomial p)
{
    delete[] this->buff;
    swap(this->n, p.n);
    swap(this->buff, p.buff);
    return *this;
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
    p.buff = new double[p.n + 1];
    cout << "nhap cac he so: ";
    for(int i = 0; i <= p.n; i++)
    {
        is >> p.buff[i];
    }
    cout << "done: " << endl;
    return is;
}

Polynomial operator + (Polynomial p1, Polynomial p2)
{
    if (p1.n < p2.n) {
        swap(p1, p2); // Ensure p1 is the larger polynomial
    }

    Polynomial res(p1.n); // Create a result polynomial with the larger degree
    for (int i = 0; i <= p1.n; i++) {
        res.buff[i] = p1.buff[i]; // Start with coefficients of p1
    }

    for (int i = 0; i <= p2.n; i++) {
        res.buff[i] += p2.buff[i]; // Add coefficients of p2
    }

    return res; // Return by value (which is safe)
}


int main()
{
    Polynomial p1,p2,p3;
    cin >> p1 >> p2;
    cout << p1 << endl << p2;
    return 0;
}