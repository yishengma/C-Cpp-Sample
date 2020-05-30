//
// Created by 海盗的帽子 on 2020/5/29.
//

#include <stdio.h>
#include <stdlib.h>
//https://zh.cppreference.com/w/%E9%A6%96%E9%A1%B5 参考手册
void open_file() {
    char *fileName = "/Users/mayisheng/mayisheng/CLionProjects/C-Cpp-Sample/CModule/12-file/Demo.txt";
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("文件打开失败\n");

    }
    char buffer[10];
    while (fgets(buffer, 10, file)) {
        printf("%s",buffer);
    }
    fclose(file);
}

int write_file() {

    char *fileName = "/Users/mayisheng/mayisheng/CLionProjects/C-Cpp-Sample/CModule/12-file/Demo.txt";
    char *copyFileName = "/Users/mayisheng/mayisheng/CLionProjects/C-Cpp-Sample/CModule/12-file/WriteDemo.txt";
    FILE * file = fopen(fileName,"r");//如果当作二进制文件需要使用 rb 或者是 wb
    FILE * copyFile = fopen(copyFileName,"w");

    if (!file || !copyFile) {
        printf("文件打开失败");
    }

    int buffer[512];
    int len = 0;
    while ((len = fread(buffer,sizeof(int),512,file))!=0) {
        fwrite(buffer,sizeof(int),len,copyFile);
    }
    fclose(copyFile);
    fclose(file);
}


long get_file_size(char * fileName) {
    //char *fileName = "/Users/mayisheng/mayisheng/CLionProjects/C-Cpp-Sample/CModule/12-file/Demo.txt";
    FILE * file = fopen(fileName,"r");//如果当作二进制文件需要使用 rb 或者是 wb
    if (!file) {

    }
    //没有一个函数是可以直接拿文件大小
    //将文件指针移动到最后，然后再去计算偏移量
    //三个参数 SEEK_SET (开头)  SEEk_CUR(当前)  SEEK_END(移动到最后)
    fseek(file,0,SEEK_END);
    //计算偏移位置
    //ftell 从 0 开始统计到当前 SEEK_END
    long file_size = ftell(file);

    printf("文件大小：%ld",file_size);
    fclose(file);
    return file_size;
}

//文件切割
void split_file() {
    char* fileName = "";
    FILE * file = fopen(fileName,"wb");
    int file_size = get_file_size(fileName);
    int file_number = 3;
    char** fileNames = (char **)malloc(sizeof(char *)*file_number);
    for (int i = 0; i < 3; ++i) {
        fileNames[i] = (char *)malloc(sizeof(char *)*30);
        sprintf(fileName,"%d",i);
    }


    free(fileNames);

    fclose(file);
}

//int main() {
//    write_file();
//}