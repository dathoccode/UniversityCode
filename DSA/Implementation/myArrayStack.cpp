#include <iostream> 

using namespace std;

template<class T>
class myArrayStack
{
private:
    int _size, _cap;
    T *_buf;
public:
    myArrayStack(int size = 0, T e = NULL)
    {
        this->_cap = size;
        this->_size = size;
        _buf = new T[_cap];
        for(int i = 0; i < size; i++) 
        {
            _buf[i] = e;
        }
    }
    ~myArrayStack()
    {
        if(_buf)
        {
            delete[] _buf;
        }
    }
    void push(T e)
    {
        if(this->_size >= this->_cap)
        {
            this->_cap = this->_cap * 2 + 1;
            T *tmp = this->_buf;
            _buf = new T[_cap];
            for(int i = 0; i < this->_size;i++)
            {
                _buf[i] = tmp[i];
            }
        }
        _buf[_size] = e;
        _size++;
    }
    void pop()
    {
        if(_size > 0) this->_size--;
    }
    T &top()
    {
        return _buf[_size-1];
    }
    int size()
    {
        return this->_size;
    }
    bool empty()
    {
        return !this->_size;
    }
    void clear()
    {
        _size = 0;
    }
};

int main()
{
    myArrayStack<int> st;
    for(int i = 0; i < 10; i++) st.push(i * i);
    cout << "khai bao khong tham so: ";
    for(int i = 0; i < 10; i++) {cout << st.top() << " "; st.pop();}
    cout << endl;
    myArrayStack<int> st2(10, 1);
    cout << "khai bao co tham so: ";
    for(int i = 0; i < 10; i++) {cout << st2.top() << " "; st.pop();}
    return 0;
}