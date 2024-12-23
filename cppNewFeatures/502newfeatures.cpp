#include <iostream>
#include <string>
#include <functional>
using namespace std;
// newfeatures.cpp
// 函数可调用对象

void fun(const int &a, const string &str) { cout << a << " " << str << endl; }

// 1、函数指针
typedef void (*pf1)(const int&, const string&);
pf1 f1 = fun;

using pf2 = void (*)(const int&, const string&);
pf2 f2 = fun;

// 2、仿函数 3、一个可被转换为函数指针的类对象 4、一个类函数指针或者成员指针
class Test
{
public:
    // 2、重载()
    void operator() (string str)
    {
        cout << str << endl;
    }

    // 3、将类对象转换为函数指针
    operator pf2()
    {
        return world;
    }

    void hello(const int& a, const string& str)
    {
        cout << a << " " << str << endl;
    }

    static void world(const int& a, const string& str)
    {
        cout << a << " " << str << endl;
    }

public:
    int m_val = 10;
    string name = "luffy";
};

int
main(int arg, char *argv[])
{
    f1(1, "f1");
    f2(2, "f2");

    Test t;
    t("hello");

    Test tt;
    tt(3, "luffy"); // 此时将tt（类对象）转换为了一个函数指针 并且调用它
    
    // 类对象的函数指针
    // 不能用类的普通成员函数给f3赋值，因为普通成员函数是属于对象的，
    // 在对象没创建出来的时候是不能使用的,静态成员函数是可以的，因为它属于类
    // pf2 f3 = Test::hello;
    pf2 f3 = Test::world;
    f3(4, "qwer");

    // pf4 就是Test类内这种成员函数的别名
    using pf4 = void(Test::*)(const int &, const string &);
    pf4 f4 = &Test::hello;
    
    // 类的成员指针
    using ptr1 = int Test::*;
    ptr1 p = &Test::m_val;

    Test ttt;
    (ttt.*f4)(5, "poiuy");
    ttt.*p = 100;
    cout << ttt.m_val << ttt.name << endl;

    // 普通函数
    function<void(const int &, const string &)> f11 = fun;
    // 类的静态成员函数
    function<void(const int &, const string &)> f12 = Test::world;
    // 仿函数对象
    Test ta;
    function<void(const string &)> f13 = ta;
    // 类对象转换的函数指针
    Test tb;
    function<void(const int &, const string &)> f14 = tb;

    f11(11, "f11");
    f12(12, "f12");
    f13("f13");
    f14(14, "f14");

    return 0;
}