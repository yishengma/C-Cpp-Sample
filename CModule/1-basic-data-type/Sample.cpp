//
// Created by 海盗的帽子 on 2020/5/28.
//
#include <stdio.h>


int basic_data_type() {
    //C语言的基本数据类型 6 个
    short s = 0;
    int i = 0;
    long l = 0;
    float f = 0;
    double d = 0;
    char c = 'C';
    //基本数据类型的占位符
    printf("s的值:%d\n",s);
    printf("i的值:%i\n",i);
    printf("l的值:%ld\n",l);
    printf("f的值:%f\n",f);
    printf("d的值:%lf\n",d);
    printf("c的值:%c\n",c);
}

int main() {
    basic_data_type();
    return 0;
}
