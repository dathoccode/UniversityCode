#include <iostream> 

using namespace std;

class A 
{
    public:
    A() { cout<<"A"; }
    ~A() { cout<<"~A"; }
};

class B: public A {
public:
B() { cout<<"B"; }
~B() { cout<<"~B"; }
};
class C {
A a;
public:
C() { cout<<"C"; }
~C() { cout<<"~C"; }
};
class D: public C {
B b;
public:
D() { cout<<"D"; }
~D() { cout<<"~D"; }
};
int main()
{
D d;
cout<<endl;
}