#include <iostream>
#include <functional>
using namespace std;

void fun(int a, int b)
{
    cout << a << " " << b << endl;
}

void func(const int& a, const int& b, const function<void(const int&, const int&)>& f)
{
    if(a % 2 == 0)
    {
        f(a, b);
    }
}

void add_f(const int& a, const int& b)
{
    cout << a << " + " << b << " = " << a + b << endl;
}

class Base
{
public:
    void fun(int a, int b)
    {
        cout << a << " " << b << endl;
    }

    int m_val = 0;
};

int
main(int arg, char *argv[])
{
    bind(fun, 1, 2)();
    bind(fun, placeholders::_1, 2)(6);
    bind(fun, placeholders::_1, placeholders::_2)(1,3);

    auto f1 = bind(add_f, 2, 3);
    func(2, 2, f1);

    Base b;
    // 绑定成员函数
    auto f2 = bind(&Base::fun, &b, 11, 22);
    function<void(int, int)> ff1 = bind(&Base::fun, &b, 11, 22);
    f2();
    ff1(1, 2);

    // 绑定成员变量
    auto m = bind(&Base::m_val, &b);
    function<int& (void)> ff2 = bind(&Base::m_val, &b);
    cout << "m()"<< m() << endl;
    cout << "ff2()"<< ff2() << endl;
    m() = 123;
    cout << m() << endl;
    cout << "b.m_val = " << b.m_val << endl;

    return 0;
}