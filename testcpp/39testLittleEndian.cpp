#include <iostream>
#include <stdio.h>

union VAR
{
    char ch[4];
    int val;
};


int main()
{
    VAR data;
    data.ch[0] = 0x04;
    data.ch[1] = 0x03;
    data.ch[2] = 0x02;
    data.ch[3] = 0x11;


    //数组中下标低的，地址也低，按地址从低到高，内存内容依次为：04,03,02,11。总共四字节
    //而把四个字节作为一个整体（不分类型，直接打印十六进制），应该从内存高地址到低地址看，0x11020304，低位04放在低地址上。
    printf("data.ch[0]: %p\n", &data.ch[0]);
    printf("data.ch[1]: %p\n", &data.ch[1]);
    printf("data.ch[2]: %p\n", &data.ch[2]);
    printf("data.ch[3]: %p\n", &data.ch[3]);
    printf("%x\n", data.val); // 11020304 小端


    union
    {
        short val;
        char ch[sizeof(short)];
    } test;

    test.val = 0x0102;
    if(test.ch[0] == 1 && test.ch[1] == 2)
    {
        // 高地址存低位
        std::cout << "大端" << std::endl;
    }
    else if(test.ch[0] == 2 && test.ch[1] == 1)
    {
        // 高地址存高位
        std::cout << "小端" << std::endl;
    }
    else
        std::cout << "未知" << std::endl;

    return 0;
}
