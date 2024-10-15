#include <iostream> 

using namespace std;

class node
{
public:
    int e;
    node* left;
    node* right;
    node(int n)
    {
        e = n;
        if(n >= 4 && n % 2 == 0)
        {
            left = new node(n/2 - 2);
            right = new node(n/2 + 2);
        }
        else
        {
            left = right = NULL;
        }
    }
};

void preorder(node* t)
{
    if(t == 0) return;
    cout << t->e << " ";
    preorder(t->left);
    preorder(t->right);
}

void inorder(node* t)
{
    if(t == 0) return;
    inorder(t->left);
    cout << t->e << " ";
    inorder(t->right);
}

void postorder(node *t)
{
    if(t == 0) return;
    inorder(t->left);
    inorder(t->right);
    cout << t->e << " ";

}

void draw(node* t, string prompt = "\n")
{
    if(t == 0) return;
    draw(t->left, prompt+"\t");
    cout << prompt << t->e;
    draw(t->right, prompt + "\t");
}

int sum(node* t)
{
    int s = 0;
    if(t == NULL) return 0;
    return t->e + sum(t->left) + sum(t->right);

}

int main()
{
    int n; cin >> n;
    node* t = new node(n);
    draw(t);
    cout << endl;
    cout << "tong: " << sum(t);
    return 0;
}