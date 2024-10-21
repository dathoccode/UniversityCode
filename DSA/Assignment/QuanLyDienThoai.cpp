#include <bits/stdc++.h> 

using namespace std;

class Phone
{
private:
    string id_, brand_;
    int year_;
    double price_;
public:
    Phone(string id = "", string brand = "", int year = 2024, double price = 0)
    {
        this->id_ = id;
        this->brand_ = brand;
        this->year_ = year;
        this->price_ = price;
    }
    friend istream &operator >>(istream &in, Phone &ph)
    {
        cout << "Nhap id san pham: ";
        in.ignore(1);
        getline(in, ph.id_);
        cout << "Nhap thuong hieu: ";
        in >> ph.brand_;
        cout << "Nhap nam san xuat: ";
        in >> ph.year_;
        cout << "Nhap gia(VND): ";
        in >> ph.price_;
        return in;
    }
    friend ostream &operator<< (ostream &out, Phone ph)
    {
        out << setw(20) << left << ph.id_ << " " << setw(10) << left << ph.brand_ << " " << setw(8) << ph.year_ << " " << ph.price_;
        return out;
    }
    string getId(){return id_;}
    friend bool operator < (Phone p1, Phone p2)
    {
        return p1.price_ < p2.price_;
    }

    friend bool operator == (Phone p1, Phone p2)
    {
        return (p1.brand_ == p2.brand_ && p1.id_ == p2.id_ && p1.price_ == p2.price_ && p1.year_ == p2.year_);
    }
};

class phoneList
{
private:
    list<Phone> lst;
public:
    phoneList(){}
    void enter()
    {
        int n;
        cout << "Nhap so phan tu: ";
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            Phone tmp;
            cin >> tmp;
            lst.push_back(tmp);
        }

    }

    void print()
    {
        for(int i = 0; i < lst.size(); i++)
        {
            cout << lst.front() << endl;
            lst.push_back(lst.front());
            lst.pop_front();
        }
    }
    void add(Phone p)
    {
        lst.push_back(p);
    }
    void remove(Phone p)
    {
        for(int i = 0; i < lst.size(); i++)
        {
            if(lst.front() == p) lst.pop_front();
            lst.push_back(lst.front());
            lst.pop_front();
        }
    }
    Phone find(string id)
    {
        Phone tmp("null", "null", 0, 0);
        for(auto p: lst)
        {
            if(p.getId() == id) 
            {
                return p;
            }
        }
        return tmp; 
    }

};

class app
{
private:
    phoneList lst;
public:
    void select()
    {
        int n; 
        cin >> n;
        Phone tmp;
        string s;
        switch(n)
        {
        case 1:
            lst.enter();
            break;
        case 2:
            cout << "Danh sach: " << endl;
            lst.print();
            break;
        case 3:
            cin >> tmp;
            lst.add(tmp);
            break;
        case 4:
            cout << "Nhap id dien thoai muon xoa: ";
            cin >> s;
            lst.remove(lst.find(s));
        case 5:
            cout << "Nhap id dien thoai muon tim: ";
            cin.ignore(1);
            getline(cin, s);
            tmp = lst.find(s);
            if(tmp.getId() != "null")
            {
                cout << lst.find(s);
            }
            else
            {
                cout << "Khong tim thay dien thoai." << endl;
            }
            
            break;
        default:
            return;
        }
        system("Pause");
        showMenu();
    }
    void showMenu()
    {
        system("CLS");
        cout << "---------------------------------------" << endl;
        cout << "----------------MENU-------------------" << endl;
        cout << "1. Nhap danh sach" << endl;
        cout << "2. Xuat danh sach" << endl;
        cout << "3. Them dien thoai" << endl;
        cout << "4. Xoa dien thoai" << endl;
        cout << "5. Tim dien thoai" << endl;
        cout << "Nhap lua chon: ";
        select();
    }
    app(phoneList l)
    {
        lst = l;
        showMenu();
    }
};

int main()
{
    //freopen("input.txt", "r", stdin);
    phoneList lst;
    app a(lst);    
    return 0;
}