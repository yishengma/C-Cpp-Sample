//
// Created by 海盗的帽子 on 2020/6/17.
//

//带引用计数的智能指针share_prt 和 weak_ptr
//带引用计数：多个智能指针可以管理同一个资源
//带引用计数：给每一个对象资源，匹配一个引用计数
//智能指针-》 资源的时候 -》引用计数+1
//智能指针-》不使用资源的时候-》引用计数-1， 计数为0 ，资源释放


//对智能指针引用计数的类
template<typename T>
class RefCnt {
public:
    RefCnt(T *ptr = nullptr) : ptr(ptr) {
        if (ptr != nullptr) {
            mount = 1;
        }
    }

    void addRef() {
        mount++;
    }

    int removeRef() {
        mount--;
        return mount;
    }

private:
    T* ptr;
    int mount;

};
template<typename T>
class SmartPtr {
public:
    SmartPtr(T *ptr = nullptr) : ptr(ptr) {
        pRefCnt = new RefCnt<T>(ptr);
    }

    virtual ~SmartPtr() {
        if (0 == pRefCnt->removeRef()) {
            delete ptr;
            ptr = nullptr;
        }
    }

    SmartPtr(const SmartPtr<T> &src):ptr(src.ptr),pRefCnt(src.pRefCnt) {
        if (ptr != nullptr) {
            pRefCnt->addRef();
        }
    }

    SmartPtr<T>& operator=(const SmartPtr<T> &src) {
        if (this == &src) {
            return *this;
        }
        //本身有资源，需要释放掉自己的
        //才能从别的地方接收赋值
        if (0 == pRefCnt->removeRef()) {
            delete ptr;
        }
        ptr = src.ptr;
        pRefCnt = src.pRefCnt;
        pRefCnt->addRef();
        return *this;
    }

    T& operator*() {
        return *ptr;
    }

    T* operator&() {
        return ptr;
    }

private:
    //指向资源的指针
    T *ptr;
    //指向资源引用计数对象的指针
    RefCnt<T>* pRefCnt;
};