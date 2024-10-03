#include <iostream> 
#include <vector>

using namespace std;

template <class T>
class Vector
{
public:
    int _cap = 0, _size = 0;
    T* buff;
    Vector();
    Vector(int n);
    T &front();
    T &back();
    void push_back(T e);
    void pop_back();
    int size();
    int capacity();
    bool empty();
    void insert(iterator it, T e);

};

template <class T> Vector<T>::Vector()
{

}

template <class T> Vector<T>::Vector(int n)
{
    this->_size = n;
}

template <class T> T& Vector<T>::front()
{
    if(!this->_size) return NULL;
    return *(this->buff);
}

template <class T> T& Vector<T>::back()
{
    return *(this->buff + this->_size);
}

template <class T> void Vector<T>::push_back(T e)
{
    if(this->_size == this->_cap)
    {
        this->_cap *= 2;
        T *tmp = this->buff;
        this->buff = new T[this->_cap];
        for(int i = 0; i < this->_size; i++)
        {
            this->buff[i] = tmp[i];
        }
    }
    this->buff[this->_size++] = e;
}

template <class T> void Vector<T>::pop_back()
{
    this->buff(this->_size--) = NULL;
}

template <class T> int Vector<T>::size()
{
    return this->_size;
}

template <class T> int Vector<T>::capacity()
{
    return this->_cap;
}

template <class T> bool Vector<T>::empty()
{
    return !(this->_size);
}

template <class T> void Vector<T>::insert(iterator it, T e)
{
    
}


int main()
{
    
    return 0;
}