#include <stdio.h>
#include <stdlib.h>

#define STRSIZE 32
#define ARRSIZE 5

int main()
{
    // 格式化输入输出 scanf(),printf()
    // 标准化格式化字符
    // %d 十进制整数有符号
    // %u 无符号整数
    // %o 八进制无符号
    // %x 十六进制无符号
    // %c 单个字符
    // %s 字符串
    // %f 小数形式浮点数
    // %% %本身
    char c = 65;
    printf("c = %c\n", c);
    // printf("%%d: c = %d\n",c);
    double f = 123.4567890;
    printf("f = %10.10f\n", f); //%.10控制小数点前后保留的位数
                                // 也可控制输出字符串长度
    char str[STRSIZE] = "Hello World!";
    printf("str = %.5s\n", str);
    // printf的\n用于刷新缓冲区，不写有可能后面的输出不了
    int i;
    float j;
    printf("Please input for i j :");
    scanf("%d %f", &i, &j); //这里必须空格分隔，如果中间什么也没有，空格回车tab都行
    printf("i = %d\nj = %.5f\n", i, j);
    // printf()的返回值为正常输出元素的个数，不包括'\0'

    // 字符数组作输入，地址就是本身
    char str2[STRSIZE];
    printf("Please input for str2: ");
    int retScanf = scanf("%s", str2); // scanf()的返回值为1是正确的匹配输入
    printf("str2 : %s\n", str2);

    int arr1[ARRSIZE];
    printf("Please enter arr1 elements\n");
    for (int n = 0; n < ARRSIZE; n++)
    {
        retScanf = scanf("%d", arr1); // scanf()的返回值为1是正确的匹配输入
        if (!retScanf)
        {
            printf("Input Error!\n");
            break;
        }
    }

    // 字符输入输出 getchar(),putchar().返回值都为ASCII码，到文件结尾为EOF
    printf("Input ch: ");
    int ch;
    ch = getchar();
    putchar(ch);
    printf("\n");

    // 字符串输入输出 gets()危险！不检查缓冲区溢出，不建议使用,puts()
    // gets()遇到换行符或者EOF停止
    // puts()遇到换行符终止
    char str3[STRSIZE];
    gets(str3); //危险！不检查缓冲区溢出，不建议使用，建议使用getline()
    puts(str3);

    exit(0);
}