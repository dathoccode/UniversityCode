#include <bits/stdc++.h>

using namespace std;

void to3(int n)
{
    stack<int> st;
    while(n)
    {
        st.push(n % 3);
        n /= 3;
    }
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    int *arr = new int[t];
    for(int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < t; i++)
    {
        to3(arr[i]);
    }
    return 0;
}