//
// Created by 海盗的帽子 on 2020/5/30.
//

//通过指针赋值的意义

//1.通过方法修改值
//2.间接赋值


#include <cstdlib>
#include <cstring>

//c和java的方法不同所在，c 可以传对象的地址在方法离里面去赋值，java 一般都是通过返回值
void change_num(int* p) {
    *p = 300;
}

//野指针：访问一个已销毁或者访问受限的内存区域的指针，野指针不能判断是否为NULL来避免
typedef struct Person{

};

int wild_pointer() {
   Person* person = (Person*)malloc(sizeof(Person));

   if (person){
       free(person);
       person = NULL;
   }

    //...
    //如果上面的person没有置为 null
    //就变为野指针
    if (person){
        free(person);
    }
}

//NULL 地址
int void_pointer() {
    char* p = NULL;
    //指针指向 NULL ,表示指针指向0x00000000
    //这个地方并不能操作，是c和c++ 编译器持有的
}

int main() {
    int num = 100;
    num = 200;
    int* p = &num;
    *p = 300;

    change_num(&num);

}

int set(char** str) {
    *str = "AAA";//指针变量的赋值，改变的是指针的指向
}

int test() {
    char * str = NULL;
    set(&str);
}
//使用指针需要注意的事项
//1.对指针做一系列操作后，指针已改变，后续对指针做操作
//2.指针变量和指针所指向的内存变量是两个不同的概念 str 是指针变量，NULL 是所指向的内存变量


//const 关键字在c 和 c++
void const_c() {
    //常量
    const int number = 0;
    //常量指针
    const int* numberp = & number;//内容不能修改，地址可以修改
    //指针常量
    const int* numberp2 = & number;//内容可以该，地址不能该

    const int* const number3 = &number;

}

//二级指针的内存模式
struct FILE {
    char * fileName;
    int length;
};

void double_pointer() {
    char* name = "Pointer";
    //二级指针，看成二维数组
    char** nameP = &name;
}

void string_array() {
    //第一种定义方式
    char* name[3] = {"ABC","ABC","ABC"};

    //c/c++ 会把char** 当作二级指针
//    char** name = {"JACK","ABV"};

    //第二种定义方式
   char name2[10][30] = {"","",""};


   //第三种方式
   int number = 3;
   char** params = (char **)malloc(sizeof(char *)*number);
    for (int i = 0; i < number; ++i) {
        params[i] = (char*)malloc(sizeof(char )*100);
        strcpy(params[i],"A");
    }
    //使用数组
    for (int j = 0; j < number; ++j) {
        if (params[j]) {
            free(params[j]);
            params[j] = NULL;
        }
    }
    if (params) {
        free(params);
        params = NULL;
    }

}