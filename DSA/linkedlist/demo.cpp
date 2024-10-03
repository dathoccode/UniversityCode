#include <iostream> 
#include <list>

using namespace std;
int main()
{
    list<int> L1;
    list<int> L(1,4);
    for(int i = 0; i < 10; i++)
    {
        i%2?L.push_back(i):L.push_front(i);
    }
    cout << "L:";
    for(list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); it++) cout << *it << " ";
    cout << endl;
    for(list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); it++) cout << *it << " ";
    cout << endl;
    return 0;
}