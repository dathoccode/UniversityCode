#include <iostream> 

using namespace std;

//iterator
template<class T>
class myVector_iterator
{
private:
    T *cur;
public:
    myVector_iterator(T *c = NULL)
    {
        cur = c;
    }
    myVector_iterator<T> operator++()  //++cur
    {
        cur++;
        return cur;
    }
    myVector_iterator<T> operator++(T) //cur++
    {
        myVector_iterator<T> tmp = cur;
        cur++;
        return tmp;
    }
    T &operator*()
    {
        return *cur;
    }
    bool operator!=(myVector_iterator<T> t)
    {
        return cur != t.cur;
    }
};

//reverse_iterator
template<class T>
class myVector_reverse_iterator
{
private:
    T *cur;
public:
    myVector_reverse_iterator(T *c = NULL)
    {
        cur = c;
    }
    myVector_reverse_iterator<T> operator++()  //--cur
    {
        cur--;
        return cur;
    }
    myVector_reverse_iterator<T> operator++(T) //cur--
    {
        myVector_reverse_iterator<T> tmp = cur;
        cur--;
        return tmp;
    }
    T &operator*()
    {
        return *cur;
    }
    bool operator!=(myVector_reverse_iterator<T> t)
    {
        return cur != t.cur;
    }
};



//vector's basic functions
template <class T>
class myVector
{
private:
    int _size, _cap = 1;
    T *_buf;
public:
    myVector(int size = 0, T e = 0)
    {
        this->_size = size;
        this->_cap = size;
        _buf = new T[size];
        for(int i = 0; i < size; i++)
        {
            _buf[i] = e;
        }
    }
    ~myVector()
    {
        if(_buf) delete[] _buf;
    }
    int capacity() {return this->_cap;}
    int size() {return this->_size;}
    bool empty() {return !_size;}
    void push_back(T elem)
    {
        if(_size == _cap) 
        {
            this->_cap *= 2;
            T *tmp = _buf;
            _buf = new T[_cap];
            for(int i = 0; i < _size; i++)
            {
                _buf[i] = tmp[i];
            }
        }
        else
        {
            this->_buf[_size] = elem;
            this->_size++;
        }
    }
    void pop_back()
    {
        if(this->_size > 0)
        {
            this->_size--;
        }
    }
    T &front()
    {
        return this->_buf[0];
    }
    T &back()
    {
        return this->_buf[size-1];
    }
    T &operator[](int k)
    {
        return this->_buf[k];
    }
    void insert(int k, T e)
    {
        if(_size == _cap) 
        {
            _cap *= 2;
            T *tmp = _buf;
            _buf = new T[_cap];
            for(int i = 0; i < _size; i++)
            {
                _buf[i] = tmp[i];
            }
        }
        for(int i = _size; i > k; i--)
        {
            _buf[i] = _buf[i-1];
        }
        _buf[k] = e;
        _size++;
    }
    myVector &operator=(myVector<T> V)
    {
        this->_size = V._size;
        this->_cap = V._cap;
        if(_cap)
        {
            this->_buf = new T[this->_cap];
            for(int i = 0; i < this->_size; i++) this->_buf[i] = V._buf[i];
        }
        else
        {
            this->_buf = NULL;
        }
        return *this;
    }
    T* begin()
    {
        return _buf;
    }
    T* end()
    {
        return _buf + _size;
    }
    T* rbegin()
    {
        return _buf + _size - 1;
    }
    T* rend()
    {
        return _buf - 1;
    }

};

int main()
{
    myVector<int> V(7,6);
	cout<<"\nVector ban dau:";for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
	for(int i=0;i<V.size();i++) V[i]=i*i;
	cout<<"\nVector binhphuong:";for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
	V.push_back(11);
	V.push_back(13);
	V.insert(2,20);
	cout<<"\nVector :";for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
    cout << "\nDuyet: "; for(myVector_iterator<int> it = V.begin(); it != V.end(); it++) cout << *it << " ";
    cout << "\nRheverse iterating: "; for(myVector_reverse_iterator<int> it = V.rbegin(); it != V.rend(); it++) cout << *it << " ";
    return 0;
}