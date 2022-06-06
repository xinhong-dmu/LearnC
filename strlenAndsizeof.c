#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 3
#define ARRSIZE 3

int main()
{
    //当计算字符串有效长度时不算'\0'，当计算所占存储空间时算'\0'
    //对于strlen计算的是有效长度，不包括'\0'
    //当用sizeof计算时计算的是所占存储空间结果.
    char characterArray[ARRSIZE] = {'a','b','c'}; //字数组没有'\0'
    printf("strlen(characterArray) = %ld\n",strlen(characterArray));//遇到'\0'结束，由于该字符数组没有'\0'，所以strlen()随机
    printf("sizeof(characterArray) = %ld\n",sizeof(characterArray));//3

    char str[STRSIZE] = "abc"; //字符串有'\0'
    printf("strlen(str) = %ld\n",strlen(str));//3
    printf("sizeof(str) = %ld\n",sizeof(str));//4

    exit(0);
}