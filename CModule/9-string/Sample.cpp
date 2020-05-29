//
// Created by 海盗的帽子 on 2020/5/29.
//

#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cctype>


int str_len(char* str) {
    int len = 0;
    while (*(str)++) {
        len++;
    }
    return len;
}


char* sub_str(char * str,int start,int end) {
    int len = end - start;
    //这里 malloc
    //一定要 free，真的的开发不会这么做，自己的方法自己管理内存
    char* s = (char *)malloc(sizeof(char)*len);
    str+=start;
    for (int i = 0; i < len; ++i) {
        s[i] = *str;
        str++;
    }
    s[len]='\0';
    return s;
}

//
void lower(char* dest,char* source) {
    while (*source!='\0') {
        char c = *source;
        *dest = tolower(c);
        source++;
        dest++;
    }
}

//字符串替换  把 aa 替换成 ccc
int replace(char* str,char* src,char* dst) {
    //1有没有 aaa

    //2.计算新的数组的大小

    //3.进行拼接 aabbcc
}

int main() {
    //字符串定义

    //第一种
    char str[] = {'S','t','r','i','n','g'};
    printf("%s\n",str);

    //第二种
    char* str1 = "String";//6
    printf("%s\n",str1);

    printf("字符串的长度%d\n",strlen(str1));
    printf("自己写的字符串长度%d\n",str_len(str1));


    //字符串类型的转换
    char* num_str = "12";
    int number = atoi(num_str);//不能转换就是 0

    printf("number is %d",number);


    //字符串的比较
    char* name1 = "Darren";
    char* name2 = "Darren";

    if (strcmp(name2,name1)) {
        printf("区分大小写相等\n");
    }

    if (strncmp(name1,name2,2)) {
        printf("比较字符串的前几个是否相等\n");
    }

    //字符串的查找，包含，拼接，截取，大小写转换
    char* query = "name is Darren";
    char* key = "Darren";
    char* find = strstr(query,key);
    printf("找到是%s\n",find);//返回找到的字符的指针

    //查询找到的位置
    int pos = find - query;
    printf("第一次出现的位置是：%d\n",pos);


    //拼接
    char* pre = "Pre";
    char* next = "Next";

    char* all = strcat(pre,next);
    printf("字符串拼接%d\n",all);

    //复制
    char cpy[str_len(pre)];
    strcpy(cpy,pre);
    printf("复制的函数%s\n",cpy);


}
