    #include <iostream>
    #include <vector>
    using namespace std;

    int main()
    {
        string a, b;
        long mem;
        cin >> a >> b;
        vector<long> A, B;
        for(auto x = a.rbegin(); x != a.rend(); x++)
        {
            A.push_back(*x - '0');
        }
        for(auto x = b.rbegin(); x != b.rend(); x++)
        {
            B.push_back(*x - '0');
        }
        vector<long> C(A.size() + B.size() + 1, 0);
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < B.size(); j++)
            {
                C[i+j] += A[i] * B[j];
            }
        }
        for(int i = 0; i < C.size(); i++)
        {
            mem = C[i] / 10;
            C[i] %= 10;
            C[i + 1] += mem;
        }
        while(C.back() == 0) C.pop_back();
        for(auto it = C.rbegin(); it != C.rend(); it++ ) cout << *it;
        return 0;
    }