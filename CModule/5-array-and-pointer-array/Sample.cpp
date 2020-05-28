//
// Created by 海盗的帽子 on 2020/5/28.
//

#include <stdio.h>
void def_array() {
    int arr[] = {1,2,3,4};
    for (int i = 0;i < 4 ; i++) {
        printf("数组的值：%d\n",arr[i]);
    }


    // arr = arr取地址的值 = arr[0] 取地址的值
    printf("arr = %p\n",arr);
    printf("arr&= %p\n",&arr);
    printf("arr[0]& = %p\n",&arr[0]);


    //对指针的一系列操作，指针的 ++ 和 --

    int * p = arr;
    p++;
    //

    for(int i = 0;i < 4 ;i++) {
        *(p+i) = 2;
    }

}

int main() {
    def_array();
}