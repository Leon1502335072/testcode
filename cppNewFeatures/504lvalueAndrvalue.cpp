#include <iostream>
#include <stdio.h>
using namespace std;

class Test
{
public:
    Test() : num(new int(100))
    {
        printf("default constructor: num 的地址 %p\n", num);
    }
    // 拷贝构造（深拷贝）
    Test(const Test& a):num(new int(*a.num))
    {
        cout << "copy constructor!" << endl;
    }
    // 移动构造
    Test(Test&& a) noexcept:num(a.num)
    {
        a.num = nullptr;
        cout << "move constructor!" << endl;
    }

    ~Test()
    {
        cout << "destory construct!" << endl;
    }

private:
    int *num;
};

Test getTestObj()
{
    Test t;
    return t;
}


int main(int arg, char *argv[])
{
    Test t = getTestObj();

    int a = 10;
    int &a1 = a;
    printf("a的地址：%p, a1的地址：%p\n", &a, &a1);

    return 0;
}