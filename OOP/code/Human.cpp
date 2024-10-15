#include <iostream> 
#include <iomanip> 
#include <vector>

using namespace std;

class Human
{
private: 
    string name;
    int age;
public:
    Human()
    {

    }
    void enter()
    {
        cout << "nhap ten: ";
        cin.ignore(1);
        getline(cin, this->name);
        cout << "nhap tuoi: ";
        cin >> this->age;
    }
    void show()
    {
        cout << fixed;
        cout << setw(20) << left << name << setw(4) << age;
    }
};

class Soccer:public Human
{
private:
    int score, playTime;
public:
    Soccer()
    {

    }
    void enter()
    {
        this->Human::enter();
        cout << "nhap so ban thang: ";
        cin >> score;
        cout << "nhap so phut thi dau: ";
        cin >> playTime;
    }
    void show()
    {
        this->Human::show();
        cout << " " << score << " " << playTime;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<Soccer> a;
    for(int i = 0; i < n; i++)
    {
        a[i].enter();
    }
    for(int i = 0; i < n; i++)
    {
        a[i].show();
    }
    return 0;
}