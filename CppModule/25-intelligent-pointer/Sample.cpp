//
// Created by 海盗的帽子 on 2020/6/17.
//
#include <memory>
#include <scoped_allocator>

using namespace std;
//智能指针:保证做到资源的自动释放
//不带引用计数的智能指针
//auto_ptr scoped_ptr unique_ptr
//带引用计数的智能指针
//shared_prt ,weak_ptr

//智能指针交叉引用问题
//多线程访问共享对象问题
//自定义删除器

//裸指针
//int * p = new int(10);


//手动智能指针(智能指针实际上是一个对象)
//利用对象在出作用域自动析构的特征，来做到资源的自动释放
//问题：智能指针能否在堆上，可以但是这样和裸指针一样，没什么用
template<typename T>
class SmartPtr {
public:
    SmartPtr(T *ptr = nullptr) : ptr(ptr) {

    }

    virtual ~SmartPtr() {
        delete ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T* operator&() {
        return ptr;
    }

private:
    T *ptr;
};


int main() {
    SmartPtr<int> ptr(new int );
    *ptr = 1;

    SmartPtr<int> ptr2(new int );
    ptr2 = ptr;
    //怎么解决浅拷贝问题
    //auto_ptr<int> ptr1(new int );
    //_LIBCPP_INLINE_VISIBILITY auto_ptr(auto_ptr& __p) throw() : __ptr_(__p.release()) {}
    //_LIBCPP_INLINE_VISIBILITY _Tp* release() throw()
    //    {
    //        _Tp* __t = __ptr_;
    //        __ptr_ = 0;
    //        return __t;
    //    }
    //auto_ptr 赋值之后销毁前一个，所以永远是最后一个对象管理对象
    //即会转移对象的所有权


    //scoped_ptr<int> ptr1(new int );
    //scoped_ptr<const scoped_ptr<T>&> delete
    //scoped_ptr<T>& operator=(const scoped_ptr<T> &p) delete
    //不能使用拷贝构造函数，delete

    //unique_ptr<int> ptr1(new int );
    //_LIBCPP_INLINE_VISIBILITY
    //  unique_ptr& operator=(unique_ptr&& __u) _NOEXCEPT {
    //    reset(__u.release());
    //    __ptr_.second() = _VSTD::forward<deleter_type>(__u.get_deleter());
    //    return *this;
    //  }
    //带右值引用的参数的拷贝构造，不带左值
    //相当于把 p1 的资源移动给 p2
    //相比auto_ptr 是比较明显的代码指明
    unique_ptr<int> p1(new int );
    unique_ptr<int> p2(std::move(p1));


}

