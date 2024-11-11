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

double dis(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

istream &operator>>(istream &in, Point &pt)
{
    cout << "nhap hoanh do: ";
    in >> pt.x;
    cout << "nhap tung do: ";
    in >> pt.y;
    return in;
}

ostream &operator << (ostream &out, Point pt)
{
    out << "(" << pt.x << "," << pt.y << ")";
    return out;
}


pair<Point, Point> farthestPoints(int n, Point arr[])
{
    pair<Point, Point> res;
    double maxDis = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(dis(arr[i], arr[j]) > maxDis)
            {
                maxDis = dis(arr[i], arr[j]);
                res.first = arr[i];
                res.second = arr[j];
            }
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    Point p[n];
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    } 
    cout << endl;  
    cout << "cap diem cach xa nhau nhat la: " << farthestPoints(n, p).first << ", " << farthestPoints(n, p).second;

    return 0;
}