#include <iostream> 
#include <stack>
#include <set>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;


int main()
{
    int n, k, m, f, s;
    cin >> n >> k >> m >> s >> f;
    map<int, int> res;
    res[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == f) 
        {
            cout << res[cur];
            return 0;
        }

        if(cur + k <= n && res.find(cur + k) == res.end()) 
        {
            q.push(cur + k);
            res[cur + k] = res[cur] + 1;
        }
        if(cur - m > 0 && res.find(cur - m) == res.end()) 
        {
            q.push(cur - m);
            res[cur - m] = res[cur] + 1;
        }

    }
    cout << -1 << endl;



    return 0;
}
