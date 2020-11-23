#include <iostream>
#include "deque"
#include "vector"

using namespace std;

template <class T>
class ComplexNum
{
    private:
        T re;
        T im;
    public:
        ComplexNum(int r = 0, int i =0)
        {  re = r;   im = i; }
        friend ostream & operator << (ostream &out, const ComplexNum &c);
        friend istream & operator >> (istream &in,  ComplexNum &c);
};  

template <typename T>
class Queue
{
    private:
        T *queuePtr;
        int size;
        int begin, end, elemcount;
    public:
        Queue(int s)
        {
            size = s;
            begin = 0;
            end = 0;
            elemcount = 0;
            queuePtr = new T[size + 1];

        }
        ~Queue()
        {
            delete [] queuePtr;
        }
        bool push_bck(const T);
        bool pop_frnt();
        void printQueue();
};

template <typename T>
bool Queue<T>::push_bck(const T value)
{
    if (elemcount > size)
        return false;
    queuePtr[end++] = value;
    elemcount++;
    if (end > size)
        end -= size + 1;
    return true;
}
template <typename T>
bool Queue<T>::pop_frnt()
{
    if (elemcount == 0)
        return false;
    T returnVal = queuePtr[begin++];
    elemcount--;
    if (begin > size)
        begin -= size + 1;
    return true;
}

template <typename T>
void Queue<T>::printQueue()
{
    for(int ix = end; ix >= begin; ix--)
        cout << "|" << "    " << queuePtr[ix] << endl;
}




template<>
bool Queue<string>::push_bck(const string *value)
{
    if (elemcount > size)
        return false;
    queuePtr[end++] = value;
    elemcount++;
    if (end > size)
        end -= size + 1;
    return true;
}
