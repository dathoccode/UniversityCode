#include <iostream> 
#include <list>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; 
    cin >> n >> k;
    list<pair<int, int>> lst;
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        while(!lst.empty() && lst.back().second <= x)
        {
            lst.pop_back();
        }
        lst.push_back({i, x});
        if(i >= k - 1)
        {
            while(lst.front().first <= i - k)
            {
                lst.pop_front();
            }
            cout << lst.front().second << " ";
        }
    }

    return 0;
}