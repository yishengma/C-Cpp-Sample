//
// Created by 海盗的帽子 on 2020/5/29.
//
//内存开辟

#include <stdio.h>
#include <cstdlib>

//栈，开辟内存的方式是静态内存开辟，方法结束后会自动回收
//如何判断一块内存中有没有写入数据
//
void static_alloc() {
    int arr[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i;
        printf("%d", arr[i]);
    }
}

//堆，开辟内存的方式是动态内存开辟，不会自动回收必须手动回收
void dynamic_alloc() {
    //使用的场景
    int *arr = (int *) malloc(10 * 1024 * 1024 * sizeof(int));
    free(arr);

}

//
//int main() {
//    int num;
//    printf("请输入数的个数：\n");
//    scanf("%d", &num);
//
//    int *arr = (int *) malloc(sizeof(int) * num);
//    int input = 0;
//    for (int i = 0; i < num; ++i) {
//        printf("输入第%d的值\n", i);
//        scanf("%d\n", &input);
//        arr[i] = input;
//        printf("%d,%p\n", *(arr + i), arr + i);
//    }
//
//    int new_num = 5;
//    //重新开辟空间
//    //有些情况返回的指针不是原来的指针相同的值，后面连续内存不足的情况下会重新找到新的内存，
//    //然后会copy内容，释放掉原来的内存
//
//    //新增内存可能会失败，失败的时候返回的是 NULL
//    int *new_arr = (int *) realloc(arr, sizeof(int) * (num + new_num));
//
//
//    //这个时候的free
//    //free(null)
//    if (new_arr) {//非空即true
//        free(new_arr);
//    } else {
//        free(arr);
//    }
//
//    //不要反复的释放，因为那块地址释放后可能会被新的程序占用，释放会引起错误
//
//}