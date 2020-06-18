//
// Created by 海盗的帽子 on 2020/6/18.
//

#include <vector>

/**
 c++ 函数的升级版

 函数对象的缺点：需要创建个对象


 lambda 表达式的语法

 [捕获外部变量](行参列表)->返回值{操作代码}

  [捕获外部变量]
  []:表示不捕获任何外部变量
  [=]:以值的方式捕获外部的所有变量
  [&]:以传引用的方式捕获外部的所有变量
  [this]:捕获外部的this 指针
  [=,&a]:以传值的方式捕获外部的所有变量，但是a变量以传引用的方式
  [a,b]:以传值的方式捕获外部的变量a和b
  [a,&b]:a以值捕获，b以引用捕获






 */
using namespace std;
int main() {
    vector<int> vector;
    for (int i = 0; i < 10; ++i) {
        vector.push_back(i);
    }

    sort(vector.begin(),vector.end(),[](int a,int b)->bool{
        return a > b;
    });

}
