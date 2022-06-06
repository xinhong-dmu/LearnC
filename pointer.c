#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(int a, int b)
{
    return a + b;
}

struct Stu
{
    int ID;
    char name[10];
};

union Manger
{
    char name[10];
    int ID;
};

enum Week
{
    MON = 1,
    TUS,
    THR,
    WES = 1,
    FRI,
    SAT,
    SUN
};


int main()
{
    // *取值，&取地址，*&什么也没有
    // *与&相当于互相抵消操作 -> *& = 什么也没有
    // **p2 => *p1 => a
    // *p2 => p1 => &a
    // p2 => &p1
    // a的地址 => p1 <= p2解引用的值;//取一次地址，减一个*

    int a = 0;
    int *p1 = &a;
    int **p2 = &p1;
    // p2 = &p1
    // &p2 = &p2
    // *p2 = *(&p1) = p1 = &a
    // **p2 = *(*p2) = *(p1) = a
    printf("a = %d\n*p1 = %d\n**p2 = %d\n", a, *p1, **p2);
    printf("&a = %p\np1 = %p\n*p2 = %p\n", &a, p1, *p2);

    // 指针与一维数组
    double arr1[] = {1, 2, 3};
    // arr1 = {4,5,6};数组名是常量，不可作为左值；只能通过地址/指针来修改
    arr1[0] = 1.1;
    double *pArr1 = arr1; //等价于double *pArr1 = &arr1[0];
    *(pArr1 + 1) = 2.2;
    for (int i = 0; i < sizeof(arr1) / sizeof(*arr1); i++)
    {
        //数组元素的偏移量就是i，不论i的数据类型
        // arr[i] = *(arr+i) = *(p+i) = p[i]
        printf("%p = %.1f ", &arr1[i], arr1[i]);
        printf("%p = %.1f ", arr1 + i, *(arr1 + i));    // arr+-按行移动
        printf("%p = %.1f\n", pArr1 + i, *(pArr1 + i)); //指针+-按列移动
    }

    //指针与二维数组
    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // int *pArr2 = arr2;//错误:指针+-按列移动，而二维数组名+-按行移动
    // int *pArr2 = *arr2;//正确：arr2取*相当于降维变成一维数组
    int *pArr2 = &arr2[0][0];                             //正确：二维数组必须加[0][0]下标
    printf("arr2 = %p\narr2 + 1 = %p\n", arr2, arr2 + 1); // arr2+1移动了一行
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 因为二维数组也是连续存储的，所以可以按列查找
            // *(arr2 + i)相当于对arr2+i降维，变成按列移动取地址
            printf("%p = %d ", *(arr2 + i) + j, *(*(arr2 + i) + j));
        }
        printf("\n");
    }

    // 数组指针：指向数组的指针
    // 指针指向元素的数据类型 (*指针名)[列数] = 数组名;
    // 左边为数组指针的标准数据类型 int (*)[列数]
    // 数组指针在数组规定大小下移动
    // 指针名任意替换成数组名
    int arr3[2][3] = {10, 20, 30, 40, 50, 60};
    int *pArr3 = *arr3;
    int(*pArr33)[3] = arr3;
    // pArr3是一个行指针，指向一维数组，所以解引用一次*(pArr3+5)=60;
    //*pArr33是一个数组指针，等价于二维数组，第一次解引用成地址，第二次加偏移量解引用成值
    //二维数组指针名表示行指针，二维指针+-表示行移动
    //*(pArr3+5) = *(*arr3 + 5) = *(*pArr33 + 5) = 60;

    //当只有一个下标时
    //二维数组：arr[行偏移量] = *(arr+行偏移量);
    //一维数组：arr[列偏移量] = *(arr+列偏移量);

    // 列地址数据类型：int *
    // 行地址数据类型：int (*)[列数]

    // 指针与字符数组
    char str1[] = "0123456789abcdef";
    char *pStr1 = str1;
    puts(pStr1);
    // sizeof(指针名)永远等于地址长度
    printf("sizeof(tr1) = %ld;sizeof(pStr1) = %ld\n", sizeof(str1), sizeof(pStr1));
    // str1 = "error";//错误
    // strcpy(str1,"01234567890123456789");//strcpy()更改字符数组,写多了会溢出，但没错
    char tempStr[] = "9876543210";
    pStr1 = tempStr;
    puts(pStr1);
    puts(str1);

    const float pi = 3.14;
    int conVar = 0;
    //看到const就念常量，看到*就念指针
    //常量指针：指针所指常量不可改变
    const float *pPi1 = &pi;
    float const *pPi2 = &pi;
    // pi *pPi1 *pPi2都不能改变

    //指针常量：指针是常量，指针不可改变
    int *const pA = &a;
    // pA不可改变
    int a1 = 0;
    const int *const p = &a1; //都不可改变

    // 指针数组
    const char *arr4[4] = {"C", "C++", "Java", "Python"}; //每一个元素都是char*型的指针
    for (int i = 0; i < 4; i++)
    {
        puts(arr4[i]);
    }

    // 函数指针： 返回值数据类型 *(函数指针名) (参数列表)
    int (*pFunc)(int, int) = func; //必须带括号
    int ret = pFunc(a, a1);

    // 函数指针数组：数组元素都是指向函数的指针
    // 数据类型 (*数组名[下标]) (参数列表)

    // 结构体指针：结构体名 *指针名 = &对象；
    // 指针->成员
    struct Stu s1 = {1120201217, "Sincere"};
    struct Stu *pS1 = &s1;
    printf("Name:%s\tID:%d\n", pS1->name, pS1->ID);


    // union公用体，只能有一个成员有效
    union Manger um;
    um.ID = 211; //被后来的成员顶替掉了
    strcpy(um.name,"Xin Hong"); //给字符数组赋值字符串常量，必须使用strcpy
    printf("Manger ID: %d\nManger Name:%s\n", um.ID,um.name);


    // enum枚举:客观存在的对应关系
    // 默认从0开始，可以在枚举体中设定
    // 像数组一样，成员之间用逗号隔开，最后一个成员后面什么也没有
    // 每设定一个值，后面的成员就重新按顺序排列
    enum Week day1 = MON;
    enum Week day5 = FRI;
    printf("%d %d\n",day1,day5);


    // void *realloc(void *ptr, size_t size)
    // 在原指针基础上开始申请size大小的空间，如果无法向下申请足够的空间
    // 重新连续开辟空间，并把新的地址返回

    // 如果函数返回值是函数中malloc的指针，该指针不是main()中的原指针
    // 需要在main()中让一个指针等于函数函数返回的指针，释放主函数中的指针就行了

    // free()之后的该指针指向的地址就给别人使用
    // 该指针指向地址就随机，与之前开辟的地址空间没有联系
    // 建议free()之后就将该指针置为空


    // typedef 重定义： typedef 数据类型旧名 数据类型新名;
    // 建议使用重定义而不是宏定义。宏定义连续定义指针有问题
    // #define IP int *
    // IP p,q; --> int *p,q;;error
    typedef int *IP;//正确
    // 实际就是将新名定义的变量替换新的数据类型名
    typedef int ARR[6]; //ARR 表示 int 数组名[]
    ARR arr5 = {1,2,3,4,5,6}; //arr5代替ARR
    // typedef struce{...} 结构体，*新名;直接将结构体名和新名声明出来


    exit(0);
}