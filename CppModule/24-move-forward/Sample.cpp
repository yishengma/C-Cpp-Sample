//
// Created by 海盗的帽子 on 2020/6/17.
//
#include <iostream>
using namespace std;
class CMyString
{
public:
    CMyString(const char *str = nullptr)
    {
        cout << "CMyString(const char*)" << endl;
        if (str != nullptr)
        {
            mptr = new char[strlen(str) + 1];
            strcpy(mptr, str);
        }
        else
        {
            mptr = new char[1];
            *mptr = '\0';
        }
    }
    ~CMyString()
    {
        cout << "~CMyString" << endl;
        delete[]mptr;
        mptr = nullptr;
    }
    CMyString(const CMyString &str)
    {
        cout << "CMyString(const CMyString&)" << endl;
        mptr = new char[strlen(str.mptr) + 1];
        strcpy(mptr, str.mptr);
    }
    CMyString(CMyString &&str)
    {
        cout << "CMyString(CMyString&&)" << endl;
        mptr = str.mptr;
        str.mptr = nullptr;
    }
    CMyString& operator=(const CMyString &str)
    {
        cout << "operator=(const CMyString&)" << endl;
        if (this == &str)
            return *this;

        delete[]mptr;

        mptr = new char[strlen(str.mptr) + 1];
        strcpy(mptr, str.mptr);
        return *this;
    }
    CMyString& operator=(CMyString &&str)
    {
        cout << "operator=(CMyString&&)" << endl;
        if (this == &str)
            return *this;

        delete[]mptr;

        mptr = str.mptr;
        str.mptr = nullptr;
        return *this;
    }
    const char* c_str()const { return mptr; }
private:
    char *mptr;

    friend CMyString operator+(const CMyString &lhs,
                               const CMyString &rhs);
    friend ostream& operator<<(ostream &out, const CMyString &str);
};
CMyString operator+(const CMyString &lhs,
                    const CMyString &rhs)
{
    CMyString tmpStr;
    tmpStr.mptr = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
    strcpy(tmpStr.mptr, lhs.mptr);
    strcat(tmpStr.mptr, rhs.mptr);
    return tmpStr;
}
ostream& operator<<(ostream &out, const CMyString &str)
{
    out << str.mptr;
    return out;
}

template<typename T>
struct Allocator
{
    T* allocate(size_t size)
    {
        return (T*)malloc(sizeof(T) * size);
    }
    void deallocate(void *p)
    {
        free(p);
    }
    void construct(T *p, const T &val)
    {
        new (p) T(val);
    }
    void construct(T *p, T &&val)
    {
        new (p) T(std::move(val));
    }

    void destroy(T *p)
    {
        p->~T();
    }
};


template<typename T, typename Alloc = Allocator<T>>
class vector1
{
public:
    vector1(int size = 10)
    {

        _first = _allocator.allocate(size);
        _last = _first;
        _end = _first + size;
    }
    ~vector1()
    {

        for (T *p = _first; p != _last; ++p)
        {
            _allocator.destroy(p);
        }
        _allocator.deallocate(_first);
        _first = _last = _end = nullptr;
    }
    vector1(const vector1<T> &rhs)
    {
        int size = rhs._end - rhs._first;
        _first = _allocator.allocate(size);
        int len = rhs._last - rhs._first;
        for (int i = 0; i < len; ++i)
        {
            _allocator.construct(_first + i, rhs._first[i]);
        }
        _last = _first + len;
        _end = _first + size;
    }
    vector1<T>& operator=(const vector1<T> &rhs)
    {
        if (this == &rhs)
            return *this;

        for (T *p = _first; p != _last; ++p)
        {
            _allocator.destroy(p);
        }
        _allocator.deallocate(_first);

        int size = rhs._end - rhs._first;
        _first = _allocator.allocate(size);
        int len = rhs._last - rhs._first;
        for (int i = 0; i < len; ++i)
        {
            _allocator.construct(_first + i, rhs._first[i]);
        }
        _last = _first + len;
        _end = _first + size;
        return *this;
    }
    void pop_back()
    {
        if (empty())
            return;
        --_last;
        _allocator.destroy(_last);
    }
    T back()const
    {
        return *(_last - 1);
    }
    bool full()const { return _last == _end; }
    bool empty()const { return _first == _last; }
    int size()const { return _last - _first; }

    void push_back(const T &val)
    {
        if (full())
            expand();

        _allocator.construct(_last, val);
        _last++;
    }

    void push_back(T &&val)
    {
        if (full())
            expand();

        //因为一个右值引用变量本身是一个左值，所以这里 construct 还是使用的左值引用
        //使用std::move 强转 为右值
        _allocator.construct(_last,std::move(val));
        _last++;
    }

private:
    T *_first;
    T *_last;
    T *_end;
    Alloc _allocator;

    void expand()
    {
        int size = _end - _first;
        //T *ptmp = new T[2 * size];
        T *ptmp = _allocator.allocate(2 * size);
        for (int i = 0; i < size; ++i)
        {
            //ptmp[i] = _first[i];
            _allocator.construct(ptmp + i, _first[i]);
        }
        //delete[]_first;
        for (T *p = _first; p != _last; ++p)
        {
            _allocator.destroy(p);
        }
        _allocator.deallocate(_first);
        _first = ptmp;
        _last = _first + size;
        _end = _first + 2 * size;
    }
};

int main()
{
    CMyString str1 = "aaa";
    vector1<CMyString> vec;

    cout << "-----------------------" << endl;
    vec.push_back(str1);
    vec.push_back(CMyString("bbb"));
    cout << "-----------------------" << endl;

    return 0;
}



CMyString GetString(CMyString &str)
{
	const char* pstr = str.c_str();
	CMyString tmpStr(pstr);
	return tmpStr;
}
