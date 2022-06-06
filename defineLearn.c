#include <stdio.h>
#include <stdlib.h>


#define MAX1(a,b) ((a) > (b) ? (a) :(b))  //建议每个宏定义中的变量都加括号

//宏定义体必须写在一行之内,可通过 \ 来标识下一行进行宏的实现
#define MAX2(a,b) \
    ({typeof(a) A = (a);typeof(b) B = (b);((A) > (B) ? (A) : (B));})

// 防止数据溢出，每个数字加LL表示long long型肯定不会溢出
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main() {
    
    int i = 5, j = 4;

    // printf("i = %d\tj = %d\n", i, j);
    // printf("%d\n",MAX1(i++,j++)); 
    // 看结果i自增了两次，j自增一次，
    // 因为预处理过程三目运算 ？ i++ 多执行了一次
    // printf("i = %d\tj = %d\n", i, j);
    
    printf("i = %d\tj = %d\n", i, j);
    printf("max = %d\n",MAX2(i++,j++)); 
    // 看结果i自增了一次，j自增一次，因为宏定义预处理过程进行了变量替换(值传递)
    printf("i = %d\tj = %d\n", i, j);


    exit(0);
}