#include <iostream> 

using namespace std;

template<class T>
class Node
{
private:
    T _elem;
    Node<T>* _next;
public:
    Node<T>(T elem, Node<T>* next = NULL)
    {
        _elem = elem;
        _next = next;
    }
    Node<T>* &getNext(){return _next;}
    T &getElem() {return _elem;}
};

template<class T>
class myLinkedListStack
{
private:
    int _size;
    Node<T> *_head;
public:
    myLinkedListStack(int size = 0, Node<T> *head = NULL)
    {
        this->_size = size;
        this->_head = head;
    }
    int size()
    {
        return this->_size;
    }
    void push(T e)
    {
        Node<T> *tmp = new Node<T>(e, _head);
        _head = tmp;
        _size++;
    }
    void pop()
    {
        if(_size <= 1)
        {
            _head = NULL;
            _size = 0;
            return;
        }
        _head = _head->getNext();
        _size--;
    }
    T &top()
    {
        return _head->getElem();
    }
    bool empty()
    {
        if(this->_size == 0) return true;
        return false;
    }
};


int main()
{
    myLinkedListStack<string> myLove;
    myLove.push("hongngoc");
    myLove.push("abc");
    myLove.push("hngoc1");
    myLove.push("hngoc2");
    myLove.push("last pushed");
    cout << myLove.size() << endl;
    while(myLove.size())
    {
        cout << myLove.top() << " "; 
        myLove.pop();
    }

    return 0;
}