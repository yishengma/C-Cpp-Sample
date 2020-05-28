//
// Created by 海盗的帽子 on 2020/5/28.
//

#include <stdio.h>
//通过指针修改
void pointer_change_value() {
    int i = 100;
    int *p = &i;
    i = 200;
    printf("i的值是：%d\n",i);

    *p = 300;
    printf("i的值是：%d\n",i);
}

//通过地址修改
void address_change_value(int* p) {
    *p = 200;
}

//
void changeValue(int* a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//
void changeValue(){
    int a = 100;
    int b = 200;

    int* p1 = &a;
    int* p2 = &b;


    p1 = p2;//这里只是改动了 p1 p2 "变量" 的值，并没有改动 a,b 的值
}



//不开辟额外内存，对 a,b 两个值交换





int main() {
    pointer_change_value();

    int j = 100;
    printf("j的修改前值是：%d\n",j);
    address_change_value(&j);
    printf("j的值修改后是：%d\n",j);

}