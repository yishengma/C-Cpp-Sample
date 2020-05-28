//
// Created by 海盗的帽子 on 2020/5/28.
//

#include <stdio.h>
void double_pointer() {
    int num = 12;
    int* p = &num;//一级指针
    int** pp = &p;//二级指针
    int*** ppp = &pp;//多级指针

    printf(" p 的值：%p\n",p);//p的值是 num  变量的地址
    printf(" pp 的值：%p\n",pp);//pp 的值是 p 变量的地址

    //获取最终的值
    printf(" num 的值获取最终的地址：%d",**pp);
}



int main() {
    double_pointer();
}