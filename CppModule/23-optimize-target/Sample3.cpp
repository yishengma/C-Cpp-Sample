//
// Created by 海盗的帽子 on 2020/6/16.
//

#include <ostream>
#include <iostream>
using namespace std;
class Text {
public:



    Text(int ma = 10) : ma(ma) {
        cout << "Test " << ma << "普通构造函数" << endl;
    }

    virtual ~Text() {
        cout << "Test " << ma << "析构函数" << endl;
    }

    Text(const Text& text):ma(text.ma) {
        cout << "Test " << ma << "拷贝函数" << endl;
    }

    Text& operator = (const Text& text) {
        cout << "Test " << ma << "赋值函数" << endl;
    }

    int getData() {
        return ma;
    }

private:
    int ma;
};

//不能返回局部对象的引用或者指针
Text getObject(Text t) {
    int a = t.getData();
    Text text(a);//4.普通构造
    return text;//
}

int main() {
    Text t1;//1.普通构造函数
    Text t2;//2.普通构造函数
    //3.传递参数，t1 到 t 会拷贝构造
    //5.赋值构造
    t2 = getObject(t1);
    return 0;
}
//优化的三条规则
//1.函数参数传递过程中，对象优先按引用传递，不要按值传递
//2.Text getObject(Text t) {
//    int a = t.getData();
//    return Text(a);//直接构造对象赋值，这里不产生临时对象
//}
//当函数返回对象的时候，应该优先返回一个临时对象，而不要返回一个定义过的对象
//3.接收返回对象函数的时候，优先按初始化的方式接收，不要按赋值的方式