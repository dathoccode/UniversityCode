#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int elem;
    vector<node*> chil;
    node(int n)
    {
        elem = n;
        for(int i = 1; i*i <= n; i++)
        {
            if(n % i == 0) chil.push_back(new node((i-1) * ((n/i) + 1)));
        }
    }
};

void preorder(node *tr)
{
    cout << tr->elem << " ";
    for(auto a: tr->chil) preorder(a);
}

void postorder(node *tr)
{
    for(auto a: tr->chil) postorder(a);
    cout << tr->elem << " ";
}

void inorder(node *tr)
{
    if(tr->chil.size()) cout << tr->chil[0]->elem << " ";
    cout << tr->elem << " ";
    for(int i = 1; i < tr->chil.size(); i++) inorder(tr->chil[i]);
}

int sum(node *tr)
{
    int s = tr->elem;
    for(auto c:tr->chil) s += sum(c);
    return s;
}

int count(node *tr, int k = 0)
{
    if(tr->elem == k) return 1;
    else return 0;
    int s = 0;
    for(auto c:tr->chil) s += count(c, k);
    return s;
}

int main()
{

    int n;
    cin >> n;
    node *tr = new node(n);
    preorder(tr); cout << endl;
    inorder(tr); cout << endl;
    postorder(tr); cout << endl;
    return 0;
}