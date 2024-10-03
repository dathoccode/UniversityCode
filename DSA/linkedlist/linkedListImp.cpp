#include <iostream> 

using namespace std;

template<class T>
class node
{
    T elem;
    node* next;
    node(T e = 0, node<T>* n = null)
    {
        elem = e;
        next = n;
    }
};

template<class T>
class myList_iter
{
    node<T> *cur;
    myList_iter(node<T> * c = 0) {cur = c;}
    T &operator*() {return cur->elem;}
    bool operator !(myList_iter<T> it){return cur != it.cur;}
    myList_iter operator++() {return cur->next}
};



template<class T>
class myList
{
    node<T> *head, *trail;
    int n;
    myList()
    {
        head = trail = NULL;
        n = 0;
    }
    ~myList()
    {
        while(head)
        {
            node* tmp = head;
            head = head->next
            delete tmp;
        }
    }
    bool empty() return(n==0);
    int size() {return n;}
    T &front()
    {
        return head->elem;
    }
    T &back() {return trail->elem;}
    void push_front(T x)
    {
        if(n == 0) head = trail = new node<T>(x);
        else head = new node<T>(x, head);
        n++;
    }
    void push_back(T x)
    {
        if(n == 0) head = trail = new node<T>(x);
        else trail = trail->next = new node<T>(x);
        n++;
    }
    void pop_front()
    {
        if(n == 1) trail = head = NULL;
        else
        {
            node<T> *tmp = head;
            head=head->next;
            delete tmp;
        }
        n--;
    }
    void pop_back()
    {
        if(n==1) return pop_front();
        node<T>* tmp = head;
        while(tmp->next != trail)
        {
            tmp = tmp->next;
        }
        delete trail;
        trail = tmp;
        trail->next = NULL;
        n--;
    }
    
};

typedef myList_iter<class T> iterator;


int main()
{
    
    return 0;
}