//
// Created by 海盗的帽子 on 2020/5/30.
//
#include <stdio.h>

//数组作为参数传递会退化成一个指针，比较高效因此，拿不到数组的长度
void print(int arr[]) {//int * arr
    //获取不到数组的长度
    int length = sizeof(arr) / sizeof(int);
    printf("len:%d",length);
    for (int i = 0; i < length; ++i) {
        printf("%d",arr[i]);
    }
}

//只能通过这种方式
void print(int arr[],int len) {

}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(int);
    printf("size = %d\n",size);
    print(arr);
}

