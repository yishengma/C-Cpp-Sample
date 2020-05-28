//
// Created by 海盗的帽子 on 2020/5/28.
//

//指针为什么要有类型
//用于指针取值和指针偏移时，判断字节数


#include <stdio.h>



//函数指针
//
void add(int a,int b) {
    printf("num1 + num2 = %d",(a+b));
}

void mins(int a,int b) {
    printf("num1 - num2 = %d",(a-b));
}

//函数指针的定义  方法返回值 （*方法名称）（方法参数）
void operate(void (/* 这里可省略* */method)(int,int ),int a,int b) {
    method(a,b);


    void (*call)(int,int) = method;
    call(a,b);
}

int main() {
    operate(add,100,200);
}