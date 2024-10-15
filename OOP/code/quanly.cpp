#include <iostream> 

using namespace std;

class Company
{
private: 
    string name;
    int year;
public:
    Company(string _name, int _year)
    {
        this->name = _name;
        this->year = _year;
    }
    string getName(){return name;}
    int getYear(){return year;}
    void setName(string _name) {this->name = _name;}
    void setYear(int _year) {this->year = _year;}
    void print()
    {
        cout << name << " " << year << " ";
    }
    void nhap()
    {
        string n;
        int y;
        cin.ignore(1);
        cout << "nhap ten cong ty: ";
        getline(cin, n);
        this->name = n;
        cout << "nhap nam thanh lap: ";
        cin >> y;
        this->year = y;
    }
};

class SWCompany : public Company
{
private:
    int devs;
public:
    SWCompany(string _name = "unknow", int _year = 0, int _devs = 0) : Company(_name, _year)
    {
        this->devs = _devs;
    }
    int getDevs(){return devs;}
    void setDevs(int _devs) {this->devs = _devs;}
    void print()
    {
        this->Company::print();
        cout << devs << endl;
    }
    void nhap()
    {
        this->Company::nhap();
        cout << "nhap so dev: ";
        int d; cin >> d;
        setDevs(d);
    }
};

class EPCompany : public Company
{
private:
    int trucks;
public:
    EPCompany(string _name = "unknown", int _year = 0, int _trucks = 0) : Company(_name, _year)
    {
        this->trucks = _trucks;
    }
    int getTrucks(){return trucks;}
    void setTrucks(int _trucks){this->trucks = _trucks;}
    void print()
    {
        this->Company::print();
        cout << trucks << endl;
    }
    void nhap()
    {
        this->Company::nhap();
        cout << "nhap so xe: ";
        int t; cin >> t;
        setTrucks(t);
    }
};

void yc1(SWCompany *sw, int n)
{
    for(SWCompany* it = sw; it != sw+n; it++)
    {
        if(it->getYear() > 2000)
        {
            it->print();
        }
    }
}

int main()
{
    cout << "nhap n, m: ";
    int n, m;
    cin >> n >> m;
    SWCompany *swc = new SWCompany[n];
    EPCompany *epc = new EPCompany[m];
    for(int i = 0; i < n; i++)
    {
        swc[i].nhap();
    }
    for(int i = 0; i < m; i++)
    {
        epc[i].nhap();
    }
    cout << "danh sach SWC: " << endl;
    for(int i = 0; i < n; i++)
    {
        swc[i].print();
    }
    return 0;
}