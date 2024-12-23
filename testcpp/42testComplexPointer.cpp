#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int *fun(int a)
{
    int temp = 10;
    int *arr[5];
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = &temp;
    }
    return arr;
}



int main()
{
    int *(*p1)(int) = fun;
    int *(*p2)(int) = fun;
    int *(*p3)(int) = fun;
    int *(*p4)(int) = fun;
    int *(*p5)(int) = fun;
    //int *(*(*fp)(int))[5] = {p1, p2, p3, p4, p5};
    
    // *fp->说明fp是一个指针 *(*fp)(int)->函数指针且这个函数返回一个指针  
    // (*(*fp)(int))[5] 函数返回的指针指向一个有5个元素的数组
    // *(*(*fp)(int))[5] 这个数组里面放的是地址
    // int *(*(*fp)(int))[5] 再与前面的int结合说明地址的类型是int
    int *(*(*fp)(int))[5];

    int a = 10, b = 12;

    int *p6[2] = {&a, &b};
    int(*p7)[2];
    printf("%p\n", p6);

    return 0;
}