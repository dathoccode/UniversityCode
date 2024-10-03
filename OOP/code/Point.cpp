#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Point
{
private:
    int x, y;
public:
    Point(int x, int y);
    Point();
    ~Point();
    void nhap();
    void xuat();
    double dis();
    friend double dis(Point p1, Point p2);
    friend istream &operator>> (istream &in, Point &pt);
    friend ostream &operator<< (ostream &out, Point pt);
};


Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::~Point()
{
}

void Point::nhap()
{
    cout << "nhap hoanh do:";
    cin >> this->x;
    cout << "nhap tung do:";
    cin >> this->y;
}

void Point::xuat()
{
    cout << "("<< this->x << "," << this->y << ")" << endl;
}

double Point::dis()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

double dis(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

istream &operator>>(istream &in, Point &pt)
{
    in >> pt.x >> pt.y;
    return in;
}

ostream &operator << (ostream &out, Point pt)
{
    out << "(" << pt.x << "," << pt.y << ")";
    return out;
}


int main()
{
    Point A, B, C;
    cin >> A >> B >> C;
    cout << A << " " << B << " " << C << endl;
    double ab = dis(A, B), bc = dis(B, C), ac = dis(A, C);
    double p = (ab + bc + ac) / 2;
    double s = sqrt(p*(p-ab)*(p-bc)*(p-ac));
    cout << "dien tich tam giac ABC: " << fixed << setprecision(1) << s << endl;
    cout << "nhap n:";
    int n; cin >> n;
    Point *arr = new Point[n];
    double len = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i > 0) len+=dis(arr[i], arr[i-1]);
    }
    cout << "do dai duong gap khuc: " << len;
    return 0;
}