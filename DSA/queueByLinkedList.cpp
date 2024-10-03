#include <iostream>

using namespace std;

template <class T>
class node
{
public:
    T elem;
    node *next;
    node (T e)
    {
        this->elem = e;
        this->next = NULL;
    }
};

template <class T>
class QUEUE
{
public:
    node<T> *head, *trail;
    int n;
    QUEUE() 
    {
        n = 0; 
        head = trail = NULL;
    }
    ~QUEUE() {while(n > 0) pop();}
    bool empty()
    {
        return n == 0;
    }
    int size()
    {
        return n;
    }
    void pop()
    {
        node<T> *p = head;
        head = p->next;
        delete p;
        n --;
        if(!n) trail = NULL;
    }
    void push(T e)
    {
        if(n == 0) head = trail = new node<T>(e);
        else
        {
            trail = trail->next = new node<T>(e);
        }
        n++;
    }
    T &front()
    {
        return head->elem;
    }
    T &back()
    {
        return trail->elem;
    }
};

int main()
{
    QUEUE<int> q;
    q.push(12);
    q.push(22);
    node<int> *h = q.head;
    while(h != NULL)
    {
        cout << h->elem << " ";
        h = h->next;
    }
    return 0;
}