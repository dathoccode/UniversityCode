#include <iostream> 
#include <list>

using namespace std;
int main()
{
    int n, k; 
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    list<int> lst;
    int res = 0;
    for(int i = 0; i < k; i++)
    {
        if(res < a[i]) res = a[i]; 
    }
    lst.push_back(res);
    for(int i = k; i < n; i++)
    {
        if(a[i-k+1] == res) 
        {
            for(int j = i - k + 2; j < i + 2; j++) res = res<a[j]?a[j]:res;
        }
        if(res < a[i]) res = a[i];
        lst.push_back(res);
    }

    for(auto it = lst.begin(); it != lst.end(); it++) cout << *it << " ";
    return 0;
}