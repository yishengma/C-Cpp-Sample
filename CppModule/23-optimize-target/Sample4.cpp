//
// Created by 海盗的帽子 on 2020/6/16.
//
#include <iostream>
#include <vector>

using namespace std;
//左值：有内存、有名字
//右值：没内存、没名字
class Text {

};
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


    CMyString(CMyString &&str) //
    {
        cout << "CMyString(CMyString&&)" << endl;
        //把临时对象的资源移动过来
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

    //临时对象直接匹配到右值引用赋值构造函数
    //
    CMyString& operator=(CMyString &&str)
    {
        cout << "operator=(CMyString&&)" << endl;
        if (this == &str)
            return *this;

        delete[]mptr;

        //这里直接将字符串指向的对象赋值给这个对象
        //将原本的对象销毁，避免资源的拷贝
        //即把临时对象的资源移动过来
        mptr = str.mptr;
        str.mptr = nullptr;
        return *this;
    }

    const char* c_str()const { return mptr; }
private:
    friend CMyString operator+(const CMyString &lhs,
                               const CMyString &rhs);
    char *mptr;

};

//new 之后没有delete 内存泄露
//CMyString operator+(const CMyString &lhs,
//                    const CMyString &rhs)
//{
//    char *ptmp = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
//    strcpy(ptmp, lhs.mptr);
//    strcat(ptmp, rhs.mptr);
//    return CMyString(ptmp);
//
//}

//方法内一次new delete ，返回时拷贝又一次
//CMyString operator+(const CMyString &lhs,
//                    const CMyString &rhs)
//{
//    char *ptmp = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
//    CMyString tmpStr;
//    tmpStr.mptr = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
//    strcpy(tmpStr.mptr, lhs.mptr);
//    strcat(tmpStr.mptr, rhs.mptr);
//    delete []ptmp;
//    return tmpStr;
//}

//直接使用右值引用，只有一次拷贝，没有 new delete
CMyString operator+(const CMyString &lhs,
                    const CMyString &rhs)
{
    //char *ptmp = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
    CMyString tmpStr;
    tmpStr.mptr = new char[strlen(lhs.mptr) + strlen(rhs.mptr) + 1];
    strcpy(tmpStr.mptr, lhs.mptr);
    strcat(tmpStr.mptr, rhs.mptr);
    //delete []ptmp;//
    return tmpStr; //
    //return CMyString(ptmp);
}



int main () {
    int a = 10;//10在寄存器，无内存，右值
    int &b = a;//
//    int &&c = a;//无法将左值绑定到右值


//    int &c = 10;//不能用一个左值引用绑定右值
    const int &c = 20;//可以，因为默认生成
    //int tmp = 20;
    //const int &c = tmp;


    int &&d = 20;//可以把一个右值绑定到右值引用

    Text &&e = Text();//把临时变量当作右值


    //一个右值引用变量是一个左值，有内存有名字


    //
    CMyString str1 = "aaa";

    vector<CMyString> vec;
    vec.push_back(str1);//左值引用的拷贝构造
    vec.push_back(CMyString("vvv"));//右值引用拷贝构造
}
