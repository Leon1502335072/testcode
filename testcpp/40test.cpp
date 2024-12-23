#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;


int randomLevel() 
{
    int lvl = 1;
    srand(time(0));
    while ((rand() % 2) && (lvl < 16))
        lvl++;
    return lvl;
}

int main()
{
    // int a = 1, b = 2, c = 3;
    // int *arr[3];
    // arr[0] = &a;
    // arr[1] = &b;
    // arr[2] = &c;

    // int **p = arr;
    // printf("a的地址: %p\n", &a);
    // printf("b的地址: %p\n", &b);
    // printf("c的地址: %p\n", &c);
    // cout << "=======================================" << endl;
    // printf("arr[0]的地址: %p\n", &arr[0]);
    // printf("arr[1]的地址: %p\n", &arr[1]);
    // printf("arr[2]的地址: %p\n", &arr[2]);
    // cout << "=======================================" << endl;

    // printf("arr数组地址: %p\n", arr);
    // printf("p: %p\n", p);
    // printf("*p: %p\n", *p);
    // printf("*(p+1): %p\n", *(p+1));
    // printf("*(p+2): %p\n", *(p+2));

    cout << "随机数：" << randomLevel() << endl;
    return 0;
}