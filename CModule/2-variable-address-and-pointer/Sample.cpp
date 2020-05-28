//
// Created by 海盗的帽子 on 2020/5/28.
//

#include <stdio.h>

//变量的地址
void variable_address() {
    int i = 100;
    printf("变量i的地址:%p\n",&i);
}

void byte_number() {
    printf("int 数据类型所占的字节数：%d\n",sizeof(int));
}


//指针变量和获取地址的值
void pointer_variable() {
    int i = 100;
    printf("i的值是：%d\n",i);
    printf("i的值是：%d\n",*(&i));


    //指针变量，指针存放的就是变量的地址
    //int *,代表的是 int 类型的指针
    int *p = &i;
    printf("i的值是：%d\n",*p);

    return;
}
int main() {
    variable_address();
    byte_number();
    return 0;
}