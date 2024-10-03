#include <iostream> 
#include <stack>
#include <math.h>
#include <queue>

using namespace std;

void sol()
{
    queue<pair<string,int>> q;
    for(string x:{"dangdungcntt", "tienquanutc", "quang123", "maianh", "nguyenminhduc2820"})
    {
        q.push({x,1});
    }
    int n;
    cin >> n;
    int tmp = n;
    while(n > q.front().second)
    {
        n -= q.front().second;
        q.front().second *= 2;
        q.push(q.front());
        q.pop();
    }
    cout << tmp << " " << q.front().first << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) sol();
    return 0;
}