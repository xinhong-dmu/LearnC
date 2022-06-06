#include <stdlib.h>
#include <stdio.h>

int main()
{
    // auto：默认类型，自动分配，自动回收（栈区）
    // 未初始化，随机赋值，但是编译器gcc会进行初始化为0
    auto int autoVar;
    
    // register：寄存器型，速度快但资源少，在cpu中取值.
    // 只能局部变量
    // 只能定义32位数据（long/double不行）
    // 寄存器变量没有地址
    register int regVar = 1;
    
    // static：静态全局类型变量，自动初始化为0或空值，并使其变量的值具有继承性
    static int staVar;
    // extern：说明性关键字，不能改变被说明的变量的值或类型，该变量可以被其他文件使用

    


    return 0;
}