#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Fraction
{
private:
    int tu,mau;
public:
    Fraction(int tu, int mau);
    Fraction();
    ~Fraction();
    void nhap();
    void xuat();
    void standard();
    friend Fraction operator+ (Fraction f1, Fraction f2);
    friend Fraction operator- (Fraction f1, Fraction f2);
    friend Fraction operator- (Fraction f);
    friend istream &operator >> (istream &in, Fraction &f);
    friend ostream &operator << (ostream &out, Fraction f);

};

Fraction::Fraction(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau;
}

Fraction::Fraction()
{
    this->tu = 0;
    this->mau = 1;
}

Fraction::~Fraction()
{
    cout << "fraction destroyed" << endl;
}

void Fraction::nhap()
{
    cout << "enter the fraction:";
    char tmp;
    cin >> this->tu >> tmp >> this->mau;
}

void Fraction::xuat()
{
    cout << this->tu << "/" << this->mau << endl;
}

void Fraction::standard()
{
    for(int i = sqrt(this->tu) + 1; i > 0; i--)
    {
        if(this->tu % i == 0 && this->mau % i == 0)
        {
            this->tu /= i;
            this->mau /= i;
        }
    }
}

Fraction operator+(Fraction f1, Fraction f2)
{
    Fraction res;
    res.tu = f1.tu * f2.mau + f1.mau * f2.tu;
    res.mau = f1.mau * f2.mau;
    res.standard();
    return res;
}

Fraction operator- (Fraction f1, Fraction f2)
{
    Fraction res;
    res.tu = f1.tu * f2.mau - f1.mau * f2.tu;
    res.mau = f1.mau * f2.mau;
    res.standard();
    return res;
}

Fraction operator- (Fraction f)
{
    f.tu *= -1;
    return f;
}

istream &operator >>(istream &in, Fraction &f)
    {
        in >> f.tu;
        in >> f.mau;
        return in;
    }
ostream &operator << (ostream &out, Fraction f)
    {
        f.standard();
        out << f.tu << "/" << f.mau << " ";
        return out;
    }

int main()
{

    return 0;
}