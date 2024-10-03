#include <iostream>
using namespace std;

//move n plates from s to d
void HaNoiTower(int n, char source, char des, char mid)
{
    if(n > 1) HaNoiTower(n - 1, source, mid, des);

    //move 1 plate
    cout << "move" << n << "th plate from " << source << " to " << des << endl;

    if(n>1) HaNoiTower(n - 1, mid, des, source); 
}

int main()
{
    HaNoiTower(5, 'A', 'B', 'C');
    return 0;
}