#include <iostream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

template<class T, class F>
class LexicalCast
{
public:
    T operator ()(const F& val)
    {
        return boost::lexical_cast<T>(val);
    }
};

// template<class T = int>这种给T指定类型是不行的，要在类名后面指定
template<class T>
class Base
{
public:
    Base(const T& _a) : a(_a) {}
    T a;
};

template<class T>
void fun(const T& a)
{
    cout << "a = " << a << endl;
}

template<class T, class F>
void fun2(const T& a, const F& b)
{
    cout << a << " " << b << endl;
}

template<class T, class F>
T fun3(const T& a, const F& b)
{
    return a;
}

int main()
{
    int b = 10;
    // 可以直接推到出来的
    fun(b);
    fun(1); // 这种右值形参需要用常量左值引用接收
    fun<int>(23);
    fun(1.2);
    fun("hello");
    fun(new vector<int>{1,2,3});
    fun2(1, "123");
    fun3(1, "123");
    //不能直接推导出来的
    Base<int> _b(1);

    cout << "---------------------" << endl;
    // LexicalCast<int, string>()这样相当于构造一个对象出来
    int a = LexicalCast<int, string>()("123");
    LexicalCast<int, string> fun;
    fun("123");
    fun.operator()("123");
    LexicalCast<int, string> *pfun = new LexicalCast<int, string>;
    pfun->operator()("123");
    cout << a << endl;

    cout << "gr" << 't' << endl;
    return 0;
}